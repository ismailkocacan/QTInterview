#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QDebug>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);
    ~Person();
signals:

public slots:

private:
  QString adiSoyadi;
  qint32 yasi;
public:
  Person(QString adiSoyadi,qint32 yasi);
  void setAdiSoyadi(QString adiSoyadi);
  void setYasi(qint32 yasi);

  QString getAdiSoyadi();
  qint32 getYasi();
};

typedef Person* PPerson;

#endif // PERSON_H
