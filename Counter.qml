import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2


Rectangle
{
    height: 100
    width: 300
    property int counterValue: 0
    Row
    {
        Button
        {
            id: arrowLeft
            width: 100
            height: 100
            iconSource: "file:Resources/Icon_Left.png"
        }
        Label
        {
            id: counter
            width: 100
            height: 100
            text: counterValue
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        Button
        {
            id: arrowRight
            width: 100
            height: 100
            iconSource: "file:Resources/Icon_Right.png"
        }
    }
}
