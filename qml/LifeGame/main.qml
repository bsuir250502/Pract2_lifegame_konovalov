import QtQuick 2.0

Rectangle {
    id: window
    property int rows_n: 10
    property int columns_n: 10
    width: rows_n*20
    height: columns_n*20+50
    color: "grey"
    signal gridwrite(int x,int y)
    signal updategrid()
    signal gridupdated()
    GridColumn{}
    Button{
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
    }
}
