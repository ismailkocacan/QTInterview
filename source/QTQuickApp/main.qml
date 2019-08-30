import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: myWindow1
    visible: true
    width: 320
    height: 240
    title: qsTr("SQLite QML App")

    Connections{
        target: personManager
        onKayitSonuc:{
            textResult.text = resultMessage;
        }
    }

    Column {
        anchors.fill: parent
        anchors.margins: 5
        spacing: 3
        Rectangle{
            id:rectAdSoyad
            width: parent.width
            height: 25
            border.color: "gray"
            border.width: 1
            TextInput {
                id: edtAdSoyad
                anchors.fill: parent
                anchors.margins: 4
                color: "black"
                focus: true
                text: qsTr("ismail kocacan")
            }
        }

        Rectangle{
            id:rectYas
            width: parent.width
            height: 25
            border.color: "gray"
            border.width: 1
            TextInput {
                id: edtYas
                anchors.fill: parent
                anchors.margins: 4
                color: "black"
                text: qsTr("30")
            }
        }


        Rectangle{
            id:rectKaydet
            width: parent.width
            height: 25
            border.color: "gray"
            border.width: 1
            Button{
                id:btnKaydet
                width: parent.width
                height: 25
                text: "Kaydet"
                onClicked: {
                    personManager.kaydet(edtAdSoyad.text.trim(),edtYas.text.trim());
                }
            }
        }

        Rectangle{
            id:rectResult
            width: parent.width
            height: 25
            border.color: "gray"
            border.width: 1
            Text {
                id: textResult
                text: ""
            }
        }
    }

}
