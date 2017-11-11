import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextInput {
        id: input
        y: 100
        anchors.horizontalCenter: parent.horizontalCenter
        focus: true
        onAccepted: {
            listModel.append({cool: text})
            clear()
        }
    }

    ListView {
        anchors.top: input.bottom
        anchors.horizontalCenter: input.horizontalCenter
        anchors.topMargin: 10

        height: contentHeight
        width: contentWidth
        spacing: 0

        delegate: Text {
            text: model.cool
        }

        model: ListModel {
            id: listModel
            ListElement {
                hi: "there"
                cool: "beans"
            }
            ListElement {
                hi: "there"
                cool: "beans"
            }
        }
    }
}
