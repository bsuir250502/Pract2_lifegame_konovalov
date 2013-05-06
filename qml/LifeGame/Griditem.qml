import QtQuick 2.0
import Test 1.0

Rectangle {
    id: griditem
    width: 20
    height: 20
    border.color: "black"
    border.width: 1
    property int active: 0
    property int row
    property int column
    signal gridupdated()
    color: active == 0 ? "white" : "yellow"
    MouseArea{
        anchors.fill: parent
        hoverEnabled: true
        onEntered: parent.opacity = 0.5
        onExited: parent.opacity = 1.00
        onClicked:{
            active = 1 - active
            gridwrite(row,column)
        }
    }
    Component.onCompleted:
    {
        window.gridupdated.connect(griditem.gridupdated)
    }
    Gridslot{
        id: object
    }
    onGridupdated:
    {
        active = object.getstate(row,column)
    }
}
