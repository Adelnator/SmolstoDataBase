#include "dialogconfirmation.h"
#include "ui_dialogconfirmation.h"

DialogConfirmation::DialogConfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfirmation)
{
    ui->setupUi(this);
}

DialogConfirmation::~DialogConfirmation()
{
    delete ui;
}

void DialogConfirmation::Load() {
    setWindowTitle(QString::fromLocal8Bit("Подтверждение"));
}
