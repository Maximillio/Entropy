import QtQuick 2.0

Rectangle
{
    width: 1024
    height: 100
    Row
    {
        ControlPanelButton
        {
            text: "Start over"
        }
        ControlPanelButton
        {
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
        Counter
        {}
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
    }
}
