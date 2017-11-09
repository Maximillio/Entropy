import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 500
    height: 500
    title: qsTr("Entropy")

    MouseArea {
        anchors.fill: parent
    }
    ListView
    {
        id: gridView
        model: entropyModel
        delegate: Delegate {x: xValue; y: yValue; color: colorValue; }
    }
}
