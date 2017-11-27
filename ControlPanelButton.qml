import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.2

Button
{
    width: 200
    height: 100
    style: ButtonStyle
    {
      label: Text
      {
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
        font.pointSize: 20
        color: "black"
        text: control.text
      }
    }
}
