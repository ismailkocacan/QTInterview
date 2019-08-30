#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "person.h"
#include <QScopedPointer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString path = qApp->applicationDirPath()
            + QDir::separator()
            + "mydb.sqlite";
    database.setDatabaseName(path);
    bool result = database.open();
    if (!result){
       QMessageBox::critical(this,"Hata",database.lastError().text());
    }
}

MainWindow::~MainWindow()
{
    database.close();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString adSoyad = ui->edtAdSoyad->text().trimmed();
    QString yasStr = ui->spnBoxYas->text();
    qint32 yas = ui->spnBoxYas->value();

    if (yasStr.isEmpty()){
       QMessageBox::warning(this,"uyarı","Yaş Girin");
       return;
    }

    if (adSoyad.isEmpty()){
       QMessageBox::warning(this,"uyarı","Ad Soyad Girin");
       return;
    }

   // PPerson kisi = new Person(adSoyad,yas);
    QScopedPointer<Person> kisi(new Person(adSoyad,yas)); // delete etmeye gerek yok, otomatik silinecek(smart pointer).
    QString sql = "insert into KISI (ADSOYAD,YAS) values ('"+
            kisi->getAdiSoyadi()+"',"+QString::number(kisi->getYasi())+")";

    QSqlQuery query(database);
    bool result = query.exec(sql);
    if (result){
         QMessageBox::information(this,"Bilgi","Kayıt eklendi");
    }else{
        QMessageBox::critical(this,"Hata",query.lastError().text()+" \n"+sql);
    }
}
