import QtQuick 2.0
import QtGraphicalEffects 1.0

Rectangle {
    property string colorOverlay: ""
    width: 50
    height: 50
    radius: 25
    Image
    {
        id: bubble
        source: "Resources/Bubble.png"
    }
    ColorOverlay
    {
        anchors.fill: bubble
        source: bubble
        color: "#4fff0000";
    }
    OpacityMask
    {
        anchors.fill: bubble
        source: bubble
        maskSource: bubble
    }
    //color: "#FF33CC"
}
