import QtQuick 2.7
import QtQuick.Window 2.2

Window
{
    property int actionOnItemClick: 0

    id: mainWindow
    visible: true
    width: entropyModel.windowWidth
    height: entropyModel.windowHeight + 100
    minimumHeight: entropyModel.windowHeight + 100
    maximumHeight: entropyModel.windowHeight + 100
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
                if (entropyModel.isItem(mouse.x, mouse.y))
                {
                    switch (actionOnItemClick)
                    {
                        case 0:
                        {
                            entropyModel.destroyItem(mouse.x, mouse.y);
                            break;
                        }
                        case 1:
                        {
                            entropyModel.changeItemColor(mouse.x, mouse.y);
                            break;
                        }
                        default: break;
                    }
                }
                else
                {
                    entropyModel.createItem(mouse.x, mouse.y);
                }
            }
        }
        Repeater
        {
            id: view
            model: entropyModel
            delegate: Delegate {x: xValue; y: yValue; colorOverlay: colorValue; }
        }
    }
    ControlPanel
    {
        id: controlPanel
        circlesSpeed: entropyModel.itemSpeed
        circlesCount: entropyModel.itemCount
        Binding
        {
            target: entropyModel
            property: "itemSpeed"
            value: controlPanel.circlesSpeed
        }
        Binding
        {
            target: mainWindow
            property: "actionOnItemClick"
            value: controlPanel.actionOnItemClick
        }
        Binding
        {
            target: entropyModel
            property: "isRunning"
            value: controlPanel.isRunning
        }
        Connections
        {
            target: controlPanel
            onClearAll: {entropyModel.clearAll();}
        }
        y: 800
    }
}
