import QtQuick 2.0
import QtQuick.Layouts 1.1
import "."

Rectangle{
	id: root
	color: "transparent"

	property bool drawOpenPrice: openButton.buttonEnabled
	property bool drawClosePrice: closeButton.buttonEnabled
	property bool drawHighPrice: highButton.buttonEnabled
	property bool drawLowPrice: lowButton.buttonEnabled

	property string openColor: "#face20"
	property string closeColor: "#14aaff"
	property string highColor: "#80c342"
	property string lowColor: "#f30000"
	property string volumeColor: "#14aaff"

	GridLayout{
		id: settingsGrid
		rows: 5
		columns: 3
		rowSpacing: 4
		anchors.fill: parent

		Item {
			Layout.fillHeight: true
			Layout.columnSpan: 3
		}

		Text {
			id: openText
			color: "#000000"
			font.family: Settings.fontFamily
			font.pointSize: 19
			text: "Open"
			Layout.leftMargin: 10
		}
		Rectangle {
			Layout.preferredHeight: 4
			Layout.preferredWidth: 114
			color: openColor	
		}
		CheckBox {
			id: openButton
			buttonEnabled: false
			Layout.rightMargin: 10
		}
	
		Text {
			id: closeText
			color: "#000000"
			font.family: Settings.fontFamily
			font.pointSize: 19
			text: "Close"
			Layout.leftMargin: 10
		}
		Rectangle {
			Layout.preferredHeight: 4
			Layout.preferredWidth: 114
			color: closeColor	
		}
		CheckBox {
			id: closeButton
			buttonEnabled: false
			Layout.rightMargin: 10
		}
		Text {
			id: highText
			color: "#000000"
			font.family: Settings.fontFamily
			font.pointSize: 19
			text: "High"
			Layout.leftMargin: 10
		}
		Rectangle {
			Layout.preferredHeight: 4
			Layout.preferredWidth: 114
			color: highColor	
		}
		CheckBox {
			id: highButton
			buttonEnabled: false
			Layout.rightMargin: 10
		}
		Text {
			id: lowText
			color: "#000000"
			font.family: Settings.fontFamily
			font.pointSize: 19
			text: "Low"
			Layout.leftMargin: 10
		}
		Rectangle {
			Layout.preferredHeight: 4
			Layout.preferredWidth: 114
			color: lowColor	
		}
		CheckBox {
			id: lowButton
			buttonEnabled: false
			Layout.rightMargin: 10
		}
	}
}
