import QtQuick 2.7
import QtQuick.Window 2.2

Window
{
    visible: true
    width: entropyModel.windowWidth
    height: entropyModel.windowHeight + 100
    minimumHeight: 900
    maximumHeight: 900
    minimumWidth: width
    maximumWidth:  width

    title: qsTr("Entropy")
    Rectangle
    {
        width: entropyModel.windowWidth
        height: entropyModel.windowHeight
        border.width: 2
        border.color: "#000000"
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                entropyModel.createItem(mouse.x, mouse.y);
            }
        }
        Repeater
        {
            id: view
            model: entropyModel
            delegate: Delegate {x: xValue; y: yValue; color: colorValue; }
        }
    }
    ControlPanel
    {
        id: controlPanel
        circlesSpeed: entropyModel.itemSpeed
        circlesCount: entropyModel.itemCount
        onCirclesSpeedChanged:
        {
            entropyModel.itemSpeed = controlPanel.circlesSpeed;
            console.log("Changed " + entropyModel.itemSpeed);
        }
        y: 800
    }
}
