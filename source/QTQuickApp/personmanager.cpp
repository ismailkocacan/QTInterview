#include "personmanager.h"
#include "person.h"
#include <QString>
#include <QScopedPointer>

PersonManager::PersonManager(QObject *parent) :
    QObject(parent)
{

}

void PersonManager::kaydet(QString adSoyad,QString yas){
    bool result = false;
    QString resultMessage;

    QString path = qApp->applicationDirPath()
            + QDir::separator()
            + "mydb.sqlite";
    database.setDatabaseName(path);
    result = database.open();
    if (!result){
        resultMessage = database.lastError().text().trimmed();
        emit kayitSonuc(resultMessage,result);
        return;
    }

   QScopedPointer<Person> kisi(new Person(adSoyad,yas.toInt()));
   QString sql = "insert into KISI (ADSOYAD,YAS) values ('"+
            kisi->getAdiSoyadi()+"',"+QString::number(kisi->getYasi())+")";

    QSqlQuery query(database);
    result = query.exec(sql);
    resultMessage = "Kayıt Eklendi";
    if (!result) resultMessage = query.lastError().text()+" \n"+sql;

    database.close();
    emit kayitSonuc(resultMessage,result);
}



