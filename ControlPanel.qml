import QtQuick 2.0

Rectangle
{
    property int circlesSpeed: 0
    property int circlesCount: 0
    width: 1024
    height: 100
    Row
    {
        ControlPanelButton
        {
            width: 174
            text: "Start over"
        }
        ControlPanelButton
        {
            width: 150
            text: "Play"
            onClicked:
            {
                if (text === "Play")
                {
                    text = "Pause"
                }
                else
                {
                    text = "Play"
                }
            }
        }
        Counter {counterValue: circlesSpeed}
        ControlPanelButton
        {
            text: "Kill on click"
            onClicked:
            {
                if (text === "Kill on click")
                {
                    text = "Change color\n on click"
                }
                else
                {
                    text = "Kill on click"
                }
            }
        }
        ItemCountDisplay {circlesCount: circlesCount}
    }
}
