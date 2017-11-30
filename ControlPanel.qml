import QtQuick 2.0
import "Resources/Variables.js" as Variables

Rectangle
{
    property int circlesSpeed: 0
    property int circlesCount: 0
    property int actionOnItemClick: 0
    property bool isRunning: true

    signal clearAll();

    width: 1024
    height: 100
    Row
    {
        ControlPanelButton
        {
            id: startOverButton
            width: 174
            text: "Start over"
            onClicked:
            {
                clearAll();
            }
        }
        ControlPanelButton
        {
            id: playPauseButton
            width: 150
            text: "Pause"
            onClicked:
            {
                if (text === "Pause")
                {
                    text = "Play"
                    isRunning = false;
                }
                else
                {
                    text = "Pause"
                    isRunning = true;
                }
            }
        }
        Counter
        {
            id: speedCounter
            counterValue: circlesSpeed
            onCounterValueChanged:
            {
                circlesSpeed = counterValue;
            }
        }
        ControlPanelButton
        {
            id: killChangeButton
            text: "Kill on click"
            onClicked:
            {
                if (text === "Kill on click")
                {
                    text = "Change color\n on click"
                    actionOnItemClick = Variables.actionOnItemClick.ChangeColor;
                }
                else
                {
                    text = "Kill on click"
                    actionOnItemClick = Variables.actionOnItemClick.Kill;
                }
            }
        }
        ItemCountDisplay
        {
            id: itemCounter
            count: circlesCount
        }
    }
}
