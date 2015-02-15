#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogsearchquery.h"
#include "dialogconfirmation.h"
#include "loadsavebase.h"
#include "finder.h"
#include <vector>
#include "QStandardItemModel"
#include "QStandardItem"
#include <qstring.h>
#include <string.h>
#include <QMessageBox>
#include <QDialogButtonBox>

#define RUS     QString::fromLocal8Bit
#define CENTER  item->setTextAlignment(Qt::AlignCenter);
#define baStr   std::string(ba.data(), ba.size())

std::vector<Client> dataBase;
int edit;
bool saveOrEdit;

void MainWindow::DBUpdate() {
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(0);

    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;

    QStringList horizontalHeader;
    horizontalHeader.append("ID");
    horizontalHeader.append(RUS("Фамилия"));
    horizontalHeader.append(RUS("Имя"));
    horizontalHeader.append(RUS("Отчество"));
    horizontalHeader.append(RUS("День рождения"));
    horizontalHeader.append(RUS("Телефон"));
    horizontalHeader.append(RUS("Почта"));
    horizontalHeader.append(RUS("Марка авто"));
    horizontalHeader.append(RUS("Модель"));
    horizontalHeader.append(RUS("Год выпуска"));
    horizontalHeader.append(RUS("Цвет"));
    horizontalHeader.append(RUS("VIN номер"));
    horizontalHeader.append(RUS("Гос. номер"));

    model->setHorizontalHeaderLabels(horizontalHeader);

    for (int i = 0; i < dataBase.size(); i++) {
        item = new QStandardItem(QString::number(dataBase[i].id));
        CENTER
                model->setItem(i, 0, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].lastName.data(), dataBase[i].lastName.size()));
        CENTER
                model->setItem(i, 1, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].firstName.data(), dataBase[i].firstName.size()));
        CENTER
                model->setItem(i, 2, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].middleName.data(), dataBase[i].middleName.size()));
        CENTER
                model->setItem(i, 3, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].birthDay.data(), dataBase[i].birthDay.size()));
        CENTER
                model->setItem(i, 4, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].phoneNumber.data(), dataBase[i].phoneNumber.size()));
        CENTER
                model->setItem(i, 5, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].eMail.data(), dataBase[i].eMail.size()));
        CENTER
                model->setItem(i, 6, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].carBrand.data(), dataBase[i].carBrand.size()));
        CENTER
                model->setItem(i, 7, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].carModel.data(), dataBase[i].carModel.size()));
        CENTER
                model->setItem(i, 8, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].carYear.data(), dataBase[i].carYear.size()));
        CENTER
                model->setItem(i, 9, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].carColor.data(), dataBase[i].carColor.size()));
        CENTER
                model->setItem(i, 10, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].carVIN.data(), dataBase[i].carVIN.size()));
        CENTER
                model->setItem(i, 11, item);
        item = new QStandardItem(QString::fromLocal8Bit(dataBase[i].carNumber.data(), dataBase[i].carNumber.size()));
        CENTER
                model->setItem(i, 12, item);
    }

    ui->tableView->setModel(model);

    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    LoadSaveBase ld;
    dataBase = ld.loadBase();

    DBUpdate();

    ui->stackedWidget->setCurrentIndex(0);
    MainWindow::setWindowTitle(tr("Smolsto Data Base"));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked() {
    saveOrEdit = true;
    if (dataBase.size() > 0) {
        ui->label->setText(RUS("Добавление клиента № ") + (dataBase[dataBase.size() - 1].id + 1 + '0'));
    }
    else {
        ui->label->setText(RUS("Добавление клиента № 1"));
    }
    ui->lineEditLastName->setFocus();
    ui->lineEditLastName->clear();
    ui->lineEditFirstName->clear();
    ui->lineEditMiddleName->clear();
    ui->dateEditBirthDay->clear();
    ui->lineEditPhoneNumber->clear();
    ui->lineEditEMail->clear();
    ui->lineEditCarBrand->clear();
    ui->lineEditCarModel->clear();
    ui->dateEditCarYear->clear();
    ui->comboBoxCarColor->setCurrentIndex(0);
    ui->lineEditCarVIN->clear();
    ui->lineEditCarNumber->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonEdit_clicked() {
    saveOrEdit = false;
    QModelIndexList indexes = ui->tableView->selectionModel()->selection().indexes();
    QModelIndex index;

    if (!indexes.isEmpty()) {
        int rowCount = indexes[0].row();
        int checkedCount = 0;

        foreach (index, indexes) {
            checkedCount++;
            if (index.row() != rowCount) {
                rowCount = -1;
                break;
            }
        }

        if (rowCount != -1) {
            edit = indexes[0].row();
            ui->label->setText(RUS("Редактирование клиента № ") + (dataBase[edit].id + '0'));
            ui->lineEditLastName->setText(QString::fromLocal8Bit(dataBase[edit].lastName.data(), dataBase[edit].lastName.size()));
            ui->lineEditFirstName->setText(QString::fromLocal8Bit(dataBase[edit].firstName.data(), dataBase[edit].firstName.size()));
            ui->lineEditMiddleName->setText(QString::fromLocal8Bit(dataBase[edit].middleName.data(), dataBase[edit].middleName.size()));
            ui->dateEditBirthDay->setDate(QDate::fromString(QString::fromLocal8Bit(dataBase[edit].birthDay.data(), dataBase[edit].birthDay.size()), "dd.MM.yyyy"));
            ui->lineEditPhoneNumber->setText(QString::fromLocal8Bit(dataBase[edit].phoneNumber.data(), dataBase[edit].phoneNumber.size()));
            ui->lineEditEMail->setText(QString::fromLocal8Bit(dataBase[edit].eMail.data(), dataBase[edit].eMail.size()));
            ui->lineEditCarBrand->setText(QString::fromLocal8Bit(dataBase[edit].carBrand.data(), dataBase[edit].carBrand.size()));
            ui->lineEditCarModel->setText(QString::fromLocal8Bit(dataBase[edit].carModel.data(), dataBase[edit].carModel.size()));
            ui->dateEditCarYear->setDate(QDate::fromString(QString::fromLocal8Bit(dataBase[edit].carYear.data(), dataBase[edit].carYear.size()), "yyyy"));
            ui->comboBoxCarColor->setEditText(QString::fromLocal8Bit(dataBase[edit].carColor.data(), dataBase[edit].carColor.size()));
            ui->lineEditCarVIN->setText(QString::fromLocal8Bit(dataBase[edit].carVIN.data(), dataBase[edit].carVIN.size()));
            ui->lineEditCarNumber->setText(QString::fromLocal8Bit(dataBase[edit].carNumber.data(), dataBase[edit].carNumber.size()));
            if (checkedCount == 1) {
                int checkedColumn = indexes[0].column();
                switch (checkedColumn) {
                case 1:
                    ui->lineEditLastName->setFocus();
                    break;
                case 2:
                    ui->lineEditFirstName->setFocus();
                    break;
                case 3:
                    ui->lineEditMiddleName->setFocus();
                    break;
                case 4:
                    ui->dateEditBirthDay->setFocus();
                    break;
                case 5:
                    ui->lineEditPhoneNumber->setFocus();
                    break;
                case 6:
                    ui->lineEditEMail->setFocus();
                    break;
                case 7:
                    ui->lineEditCarBrand->setFocus();
                    break;
                case 8:
                    ui->lineEditCarModel->setFocus();
                    break;
                case 9:
                    ui->dateEditCarYear->setFocus();
                    break;
                case 10:
                    ui->comboBoxCarColor->setFocus();
                    break;
                case 11:
                    ui->lineEditCarVIN->setFocus();
                    break;
                case 12:
                    ui->lineEditCarNumber->setFocus();
                    break;
                }
            }
            ui->stackedWidget->setCurrentIndex(1);
        }
    }
    else {
        QMessageBox::information(0, QString::fromLocal8Bit("Информация"), QString::fromLocal8Bit("Выделите строчку или ее элементы, чтобы изменить их!"));
    }
}

void MainWindow::on_pushButtonFind_clicked() {
    DialogSearchQuery* dialog = new DialogSearchQuery(this);
    dialog->Load();
    if (dialog->exec() == QDialog::Accepted) {
        QByteArray ba = dialog->Query().toLocal8Bit();
        std::string query = std::string(ba.data(), ba.size());
        ba = dialog->Column().toLocal8Bit();
        std::string column = std::string(ba.data(), ba.size());
        if (query != "") {
            std::vector<int> rows;
            Finder find;
            rows = find.findSubstring(dataBase, query, column);
            if (rows.size() != 0) {
                ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
                ui->tableView->setModel(0);

                QStandardItemModel *model = new QStandardItemModel;
                QStandardItem *item;

                QStringList horizontalHeader;
                horizontalHeader.append("ID");
                horizontalHeader.append(RUS("Фамилия"));
                horizontalHeader.append(RUS("Имя"));
                horizontalHeader.append(RUS("Отчество"));
                horizontalHeader.append(RUS("День рождения"));
                horizontalHeader.append(RUS("Телефон"));
                horizontalHeader.append(RUS("Почта"));
                horizontalHeader.append(RUS("Марка авто"));
                horizontalHeader.append(RUS("Модель"));
                horizontalHeader.append(RUS("Год выпуска"));
                horizontalHeader.append(RUS("Цвет"));
                horizontalHeader.append(RUS("VIN номер"));
                horizontalHeader.append(RUS("Гос. номер"));

                model->setHorizontalHeaderLabels(horizontalHeader);

                for (int i = 0; i < rows.size(); i++) {
                    item = new QStandardItem(QString::number(dataBase[rows[i] - 1].id));
                    CENTER
                            model->setItem(i, 0, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].lastName.data(), dataBase[rows[i] - 1].lastName.size()));
                    CENTER
                            model->setItem(i, 1, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].firstName.data(), dataBase[rows[i] - 1].firstName.size()));
                    CENTER
                            model->setItem(i, 2, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].middleName.data(), dataBase[rows[i] - 1].middleName.size()));
                    CENTER
                            model->setItem(i, 3, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].birthDay.data(), dataBase[rows[i] - 1].birthDay.size()));
                    CENTER
                            model->setItem(i, 4, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].phoneNumber.data(), dataBase[rows[i] - 1].phoneNumber.size()));
                    CENTER
                            model->setItem(i, 5, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].eMail.data(), dataBase[rows[i] - 1].eMail.size()));
                    CENTER
                            model->setItem(i, 6, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].carBrand.data(), dataBase[rows[i] - 1].carBrand.size()));
                    CENTER
                            model->setItem(i, 7, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].carModel.data(), dataBase[rows[i] - 1].carModel.size()));
                    CENTER
                            model->setItem(i, 8, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].carYear.data(), dataBase[rows[i] - 1].carYear.size()));
                    CENTER
                            model->setItem(i, 9, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].carColor.data(), dataBase[rows[i] - 1].carColor.size()));
                    CENTER
                            model->setItem(i, 10, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].carVIN.data(), dataBase[rows[i] - 1].carVIN.size()));
                    CENTER
                            model->setItem(i, 11, item);
                    item = new QStandardItem(QString::fromLocal8Bit(dataBase[rows[i] - 1].carNumber.data(), dataBase[rows[i] - 1].carNumber.size()));
                    CENTER
                            model->setItem(i, 12, item);
                }

                ui->tableView->setModel(model);

                ui->tableView->resizeRowsToContents();
                ui->tableView->resizeColumnsToContents();
            }
            else {
                QMessageBox::information(0, QString::fromLocal8Bit("Информация"), QString::fromLocal8Bit("Не найдено ни одного совпадения!"));
            }
        }
        else {
            DBUpdate();
        }
    }
    delete dialog;
}

void MainWindow::on_pushButtonRemove_clicked() {
    QModelIndexList indexes = ui->tableView->selectionModel()->selection().indexes();
    QModelIndex index;
    if (!indexes.isEmpty()) {
        DialogConfirmation* dialog = new DialogConfirmation(this);
        dialog->Load();
        if (dialog->exec() == QDialog::Accepted) {
            std::vector<int> checkedRows;
            checkedRows.push_back(indexes[0].row() + 1);

            bool diffRow;
            foreach (index, indexes) {
                diffRow = 1;
                for (int i = 0; i < checkedRows.size(); i++) {
                    if ((index.row() + 1) == checkedRows[i]) {
                        diffRow = 0;
                    }
                }
                if (diffRow) {
                    checkedRows.push_back(index.row() + 1);
                }
            }

            std::sort(checkedRows.rbegin(), checkedRows.rend());

            for (int i = 0; i < checkedRows.size(); i++) {
                dataBase.erase(dataBase.begin() + checkedRows[i] - 1);
            }
            LoadSaveBase sv;
            sv.saveBase(dataBase);
            DBUpdate();
        }
    }
    else {
        QMessageBox::information(0, QString::fromLocal8Bit("Информация"), QString::fromLocal8Bit("Выделите строчку или ее элементы, чтобы удалить!"));
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    if (saveOrEdit) {
        Client newClient;
        if (dataBase.size() > 0) {
            newClient.id = dataBase[dataBase.size() - 1].id + 1;
        }
        else {
            newClient.id = 1;
        }
        QByteArray ba = ui->lineEditLastName->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.lastName = baStr;
        }
        else {
            newClient.lastName = "-";
        }
        ba = ui->lineEditFirstName->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.firstName = baStr;
        }
        else {
            newClient.firstName = "-";
        }
        ba = ui->lineEditMiddleName->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.middleName = baStr;
        }
        else {
            newClient.middleName = "-";
        }
        ba = ui->dateEditBirthDay->text().toLocal8Bit();
        newClient.birthDay = std::string(ba.data(), ba.size());
        ba = ui->lineEditPhoneNumber->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.phoneNumber = baStr;
        }
        else {
            newClient.phoneNumber = "-";
        }
        ba = ui->lineEditEMail->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.eMail = baStr;
        }
        else {
            newClient.eMail = "-";
        }
        ba = ui->lineEditCarBrand->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.carBrand = baStr;
        }
        else {
            newClient.carBrand = "-";
        }
        ba = ui->lineEditCarModel->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.carModel = baStr;
        }
        else {
            newClient.carModel = "-";
        }
        ba = ui->dateEditCarYear->text().toLocal8Bit();
        newClient.carYear = std::string(ba.data(), ba.size());
        ba = ui->comboBoxCarColor->currentText().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.carColor = baStr;
        }
        else {
            newClient.carColor = "-";
        }
        ba = ui->lineEditCarVIN->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.carVIN = baStr;
        }
        else {
            newClient.carVIN = "-";
        }
        ba = ui->lineEditCarNumber->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            newClient.carNumber = baStr;
        }
        else {
            newClient.carNumber = "-";
        }
        dataBase.push_back(newClient);
    }
    else {
        QByteArray ba = ui->lineEditLastName->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].lastName = baStr;
        }
        else {
            dataBase[edit].lastName = "-";
        }
        ba = ui->lineEditFirstName->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].firstName = baStr;
        }
        else {
            dataBase[edit].firstName = "-";
        }
        ba = ui->lineEditMiddleName->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].middleName = baStr;
        }
        else {
            dataBase[edit].middleName = "-";
        }
        ba = ui->dateEditBirthDay->text().toLocal8Bit();
        dataBase[edit].birthDay = std::string(ba.data(), ba.size());
        ba = ui->lineEditPhoneNumber->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].phoneNumber = baStr;
        }
        else {
            dataBase[edit].phoneNumber = "-";
        }
        ba = ui->lineEditEMail->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].eMail = baStr;
        }
        else {
            dataBase[edit].eMail = "-";
        }
        ba = ui->lineEditCarBrand->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].carBrand = baStr;
        }
        else {
            dataBase[edit].carBrand = "-";
        }
        ba = ui->lineEditCarModel->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].carModel = baStr;
        }
        else {
            dataBase[edit].carModel = "-";
        }
        ba = ui->dateEditCarYear->text().toLocal8Bit();
        dataBase[edit].carYear = std::string(ba.data(), ba.size());
        ba = ui->comboBoxCarColor->currentText().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].carColor = baStr;
        }
        else {
            dataBase[edit].carColor = "-";
        }
        ba = ui->lineEditCarVIN->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].carVIN = baStr;
        }
        else {
            dataBase[edit].carVIN = "-";
        }
        ba = ui->lineEditCarNumber->text().toLocal8Bit();
        if (!isEmpty(baStr)) {
            dataBase[edit].carNumber = baStr;
        }
        else {
            dataBase[edit].carNumber = "-";
        }
    }
    ui->tableView->setModel(0);
    DBUpdate();
    LoadSaveBase sv;
    sv.saveBase(dataBase);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonCancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

bool MainWindow::isEmpty(std::string str) {
    if (str == "") {
        return true;
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            return false;
        }
    }
    return true;
}

void MainWindow::on_pushButtonManual_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButtonToMain_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
