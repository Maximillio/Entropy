import QtQuick 2.7
import QtQuick.Window 2.2

Window
{
    visible: true
    width: 1024
    height: 800
    title: qsTr("Entropy")
    Rectangle
    {
        width: 1024
        height: 800
        border.width: 3
        border.color: "#000000"
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                entropyModel.canFetchMore();
            }
        }
        Repeater
        {
            id: gridView
            model: entropyModel
            delegate: Delegate {x: xValue; y: yValue; color: colorValue; }
        }
    }
}
