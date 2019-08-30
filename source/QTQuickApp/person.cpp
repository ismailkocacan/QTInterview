#include "person.h"

Person::Person(QObject *parent) :
    QObject(parent)
{

}
Person::~Person(){
    qDebug() << "nesne hafızadan silindi";
}

Person::Person(QString adiSoyadi,qint32 yasi){
    this->adiSoyadi = adiSoyadi;
    this->yasi = yasi;
}

void Person::setAdiSoyadi(QString adiSoyadi){
    this->adiSoyadi = adiSoyadi;
}

void Person::setYasi(qint32 yasi){
    this->yasi = yasi;
}

QString Person::getAdiSoyadi(){
    return this->adiSoyadi;
}

qint32 Person::getYasi(){
    return this->yasi;
}
