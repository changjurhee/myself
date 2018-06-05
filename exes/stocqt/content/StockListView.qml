import QtQuick 2.0
import "."

Rectangle {
    id: root
    width: 320
    height: 410
    anchors.top: parent.top
    anchors.bottom: parent.bottom
    color: "white"

    property string currentStockId: ""
    property string currentStockName: ""

    ListView {
        id: view
        anchors.fill: parent
        width: parent.width
        clip: true
        keyNavigationWraps: true
        highlightMoveDuration: 0
        focus: true
        snapMode: ListView.SnapToItem
        model: StockListModel{}
        currentIndex: -1 // Don't pre-select any item

        function requestUrl(stockId) {
            var endDate = new Date(""); //today
            var startDate = new Date()
            startDate.setDate(startDate.getDate() - 5);

            var request = "http://ichart.finance.yahoo.com/table.csv?";
            request += "s=" + stockId;
            request += "&g=d";
            request += "&a=" + startDate.getMonth();
            request += "&b=" + startDate.getDate();
            request += "&c=" + startDate.getFullYear();
            request += "&d=" + endDate.getMonth();
            request += "&e=" + endDate.getDate();
            request += "&f=" + endDate.getFullYear();
            request += "&g=d";
            request += "&ignore=.csv";
            return request;
        }

        function getCloseValue(index) {
            var req = requestUrl(model.get(index).stockId);

            if (!req)
                return;

            var xhr = new XMLHttpRequest;

            xhr.open("GET", req, true);

            xhr.onreadystatechange = function() {
                if (xhr.readyState === XMLHttpRequest.LOADING || xhr.readyState === XMLHttpRequest.DONE) {
                    var records = xhr.responseText.split('\n');
                    if (records.length > 0 && xhr.status == 200) {
                        var r = records[1].split(',');
                        var today = parseFloat(r[4]);
                        model.setProperty(index, "value", today.toFixed(2));

                        r = records[2].split(',');
                        var yesterday = parseFloat(r[4]);
                        var change = today - yesterday;
                        if (change >= 0.0)
                            model.setProperty(index, "change", "+" + change.toFixed(2));
                        else
                            model.setProperty(index, "change", change.toFixed(2));

                        var changePercentage = (change / yesterday) * 100.0;
                        if (changePercentage >= 0.0)
                            model.setProperty(index, "changePercentage", "+" + changePercentage.toFixed(2) + "%");
                        else
                            model.setProperty(index, "changePercentage", changePercentage.toFixed(2) + "%");
                    } else {
                        var unknown = "n/a";
                        model.set(index, {"value": unknown, "change": unknown, "changePercentage": unknown});
                    }
                }
            }
            xhr.send()
        }

        onCurrentIndexChanged: {
            if (currentItem) {
                root.currentStockId = model.get(currentIndex).stockId;
                root.currentStockName = model.get(currentIndex).name;
            }
        }

        delegate: Rectangle {
            height: 102
            width: parent.width
            color: "transparent"
            MouseArea {
                anchors.fill: parent;
                onClicked: {
                    if (view.currentIndex == index)
                        mainRect.currentIndex = 1;
                    else
                        view.currentIndex = index;
                }
            }

            Text {
                id: stockIdText
                anchors.top: parent.top
                anchors.topMargin: 15
                anchors.left: parent.left
                anchors.leftMargin: 15
                width: 125
                height: 40
                color: "#000000"
                font.family: Settings.fontFamily
                font.pointSize: 20
                font.weight: Font.Bold
                verticalAlignment: Text.AlignVCenter
                text: stockId
            }

            Text {
                id: stockValueText
                anchors.top: parent.top
                anchors.topMargin: 15
                anchors.right: parent.right
                anchors.rightMargin: 0.31 * parent.width
                width: 190
                height: 40
                color: "#000000"
                font.family: Settings.fontFamily
                font.pointSize: 20
                font.bold: true
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                text: value
                Component.onCompleted: view.getCloseValue(index);
            }

            Text {
                id: stockValueChangeText
                anchors.top: parent.top
                anchors.topMargin: 15
                anchors.right: parent.right
                anchors.rightMargin: 20
                width: 135
                height: 40
                color: "#328930"
                font.family: Settings.fontFamily
                font.pointSize: 20
                font.bold: true
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                text: change
                onTextChanged: {
                    if (parseFloat(text) >= 0.0)
                        color = "#328930";
                    else
                        color = "#d40000";
                }
            }

            Text {
                id: stockNameText
                anchors.top: stockIdText.bottom
                anchors.left: parent.left
                anchors.leftMargin: 15
                width: 330
                height: 30
                color: "#000000"
                font.family: Settings.fontFamily
                font.pointSize: 16
                font.bold: false
                elide: Text.ElideRight
                maximumLineCount: 1
                verticalAlignment: Text.AlignVCenter
                text: name
            }

            Text {
                id: stockValueChangePercentageText
                anchors.top: stockIdText.bottom
                anchors.right: parent.right
                anchors.rightMargin: 20
                width: 120
                height: 30
                color: "#328930"
                font.family: Settings.fontFamily
                font.pointSize: 18
                font.bold: false
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                text: changePercentage
                onTextChanged: {
                    if (parseFloat(text) >= 0.0)
                        color = "#328930";
                    else
                        color = "#d40000";
                }
            }

            Rectangle {
                id: endingLine
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                height: 1
                width: parent.width
                color: "#d7d7d7"
            }
        }

        highlight: Rectangle {
            width: view.width
            color: "#eeeeee"
        }
    }
}
