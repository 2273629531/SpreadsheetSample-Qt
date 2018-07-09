#include "mainwindow.h"
#include <QApplication>
#include<QSplashScreen>
#include <QDateTime>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //启动画面
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/World Map.jpg"));
    splash->show();
    app.processEvents();//这个函数告诉Qt去处理那些还没有被处理的各类事件，然后再把控制权返还给调用者。



    Qt::Alignment topRight = Qt::AlignRight|Qt::AlignTop;
    int  m = MainWindow::num;
    QString str = "Setting up main window...";
    ostringstream oss;
    oss << m ;

    str = str+QString::fromStdString(oss.str());
    const char * p = str.toLocal8Bit().data();
    //splash->showMessage(QObject::tr("Setting up main window..."),topRight,Qt::blue);
    splash->showMessage(QObject::tr(p),topRight,Qt::blue);

    QDateTime n2=QDateTime::currentDateTime();
    QDateTime now2;
    do{
        now2=QDateTime::currentDateTime();
    } while (n2.secsTo(now2)<=5);//6为需要延时的秒数

    MainWindow *mainWin = new MainWindow;

    splash->showMessage(QObject::tr("Loading modules..."),topRight,Qt::white);
    //loadm

    mainWin->show();
    splash->finish(mainWin);
    delete splash;
    return app.exec();
}
