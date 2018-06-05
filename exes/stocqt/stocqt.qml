import QtQuick 2.0
import QtQml.Models 2.1
import "./content"

Rectangle {
    id: mainRect
    width: 1000
    height: 700

    property alias currentIndex: root.currentIndex

    Rectangle {
        id: banner
        height: 80
        anchors.top: parent.top
        width: parent.width
        color: "#000000"

        Image {
            id: arrow
            source: "./content/images/icon-left-arrow.png"
            anchors.left: banner.left
            anchors.leftMargin: 20
            anchors.verticalCenter: banner.verticalCenter
            visible: root.currentIndex == 1 ? true : false

            MouseArea {
                anchors.fill: parent
                onClicked: root.currentIndex = 0;
            }
        }

        Item {
            id: textItem
            width: stocText.width + qtText.width
            height: stocText.height + qtText.height
            anchors.horizontalCenter: banner.horizontalCenter
            anchors.verticalCenter: banner.verticalCenter

            Text {
                id: stocText
                anchors.verticalCenter: textItem.verticalCenter
                color: "#ffffff"
                font.family: "Abel"
                font.pointSize: 40
                text: "Stoc"
            }
            Text {
                id: qtText
                anchors.verticalCenter: textItem.verticalCenter
                anchors.left: stocText.right
                color: "#5caa15"
                font.family: "Abel"
                font.pointSize: 40
                text: "Qt"
            }
        }
    }

    ListView {
        id: root
        width: parent.width
        anchors.top: banner.bottom
        anchors.bottom: parent.bottom
        snapMode: ListView.SnapOneItem
        highlightRangeMode: ListView.StrictlyEnforceRange
        highlightMoveDuration: 250
        focus: false
        orientation: ListView.Horizontal
        boundsBehavior: Flickable.StopAtBounds

        StockModel {
            id: stock
            stockId: listView.currentStockId
            stockName: listView.currentStockName
            onStockIdChanged: stock.updateStock();
            onDataReady: {
                root.currentIndex = 1
                stockView.update()
            }
        }

        model: ObjectModel {
            StockListView {
                id: listView
                width: root.width
                height: root.height
            }

            StockView {
                id: stockView
                width: root.width
                height: root.height
                stocklist: listView
                stock: stock
            }
        }
    }
}
