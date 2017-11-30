import QtQuick 2.0

Rectangle
{
    property int count: 0
    width: 200
    height: 100
    Text
    {
        width: 200
        height: 50
        font.pointSize: 15
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        text: "Number of circles:"
    }
    Text
    {
        y: 50
        width: 200
        height: 50
        font.pointSize: 20
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignHCenter
        text: count
    }

}
