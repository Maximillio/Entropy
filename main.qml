import QtQuick 2.7
import QtQuick.Window 2.2

Window
{
    visible: true
    width: 1024
    height: 900
    minimumHeight: 900
    maximumHeight: 900
    minimumWidth: 1024
    maximumWidth:  1024

    title: qsTr("Entropy")
    Rectangle
    {
        width: entropyModel.windowWidth
        height: entropyModel.windowHeight
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
    ControlPanel
    {
        y: 800
    }
}
