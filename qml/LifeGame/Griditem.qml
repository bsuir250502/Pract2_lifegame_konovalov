import QtQuick 2.0

Rectangle {
    id: griditem
    width: 10
    height: 10
    property int active: 0
    property int row
    property int column
    color: active == 0 ? "white" : "yellow"
    signal gridwrite(int row, int column)
    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: parent.opacity = 0.5
        onExited: parent.opacity = 1.00
        onClicked:{
            active = 1 - active
            parent.gridwrite(row,column)
        }
    }
}
