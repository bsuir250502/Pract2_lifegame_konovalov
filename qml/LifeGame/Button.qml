import QtQuick 2.0

Rectangle {
    id: button
    width: 100
    height: 30
    color: "lightblue"
    border.color: "blue"
    border.width: 2
    Text{
        anchors.centerIn: parent
        text: "next generation"
    }
    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: parent.opacity = 0.5
        onExited: parent.opacity = 1.00
        onClicked: updategrid()
    }
}
