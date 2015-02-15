#include "dialogsearchquery.h"
#include "ui_dialogsearchquery.h"

DialogSearchQuery::DialogSearchQuery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSearchQuery)
{
    ui->setupUi(this);
}

DialogSearchQuery::~DialogSearchQuery()
{
    delete ui;
}

void DialogSearchQuery::Load() {
    setWindowTitle(tr("Finder"));
}

QString DialogSearchQuery::Query() {
    return ui->lineEditQuery->text();
}

QString DialogSearchQuery::Column() {
    return ui->comboBoxColumn->currentText();
}
