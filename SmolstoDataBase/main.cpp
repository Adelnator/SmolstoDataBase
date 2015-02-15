#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtSingleApplication>
#include <QMessageBox>
#include <QString>

int main(int argc, char *argv[])
{
    QtSingleApplication a(argc, argv);
    if (a.isRunning()) {
        QMessageBox::information(0, QString::fromLocal8Bit("����������"), QString::fromLocal8Bit("��������� ��� ��������!"));
        return 0;
    }
    MainWindow w;
    w.showMaximized();
    
    return a.exec();
}
