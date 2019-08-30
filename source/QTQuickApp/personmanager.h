#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QGuiApplication>

class PersonManager : public QObject
{
    Q_OBJECT
public:
    explicit PersonManager(QObject *parent = nullptr);

signals:
   void kayitSonuc(QString resultMessage,bool result);
public slots:
    void kaydet(QString adSoyad,QString yas);
 private:
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // PERSONMANAGER_H
