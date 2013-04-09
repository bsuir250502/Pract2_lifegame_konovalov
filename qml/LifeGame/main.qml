import QtQuick 2.0

Rectangle {
    width: 360
    height: 360
    color: "black"
    property int temp
    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log ("Executed")
            gridwrite(1,2)
        }
    }
    signal gridwrite(int x,int y)
    Griditem{
        anchors.centerIn: parent
    }
}
