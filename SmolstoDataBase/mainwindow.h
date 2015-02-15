#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonEdit_clicked();
    void on_pushButtonFind_clicked();
    void on_pushButtonRemove_clicked();
    void on_pushButtonCancel_clicked();
    void on_pushButtonSave_clicked();
    void DBUpdate();
    bool isEmpty(std::string);
    void on_pushButtonManual_clicked();
    void on_pushButtonToMain_clicked();
};

#endif // MAINWINDOW_H
