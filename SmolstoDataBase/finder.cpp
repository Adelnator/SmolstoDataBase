#include "finder.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "client.h"

Finder::Finder() {}

std::vector<int> Finder::findSubstring(std::vector<Client> const& temp, std::string substr, std::string column) {
    std::vector<int> result;
    //write families include input substring
    int numOfColumn;
    if (column == "ID") {
        numOfColumn = 0;
    }
    if (column == "Фамилия") {
        numOfColumn = 1;
    }
    if (column == "Имя") {
        numOfColumn = 2;
    }
    if (column == "Отчество") {
        numOfColumn = 3;
    }
    if (column == "День рождения") {
        numOfColumn = 4;
    }
    if (column == "Телефон") {
        numOfColumn = 5;
    }
    if (column == "Почта") {
        numOfColumn = 6;
    }
    if (column == "Марка авто") {
        numOfColumn = 7;
    }
    if (column == "Модель") {
        numOfColumn = 8;
    }
    if (column == "Год выпуска") {
        numOfColumn = 9;
    }
    if (column == "Цвет") {
        numOfColumn = 10;
    }
    if (column == "VIN номер") {
        numOfColumn = 11;
    }
    if (column == "Гос. номер") {
        numOfColumn = 12;
    }

    switch (numOfColumn) {
    case 0:
        for (size_t i = 0; i < temp.size(); i++) {
            QByteArray ba = QString::number(temp[i].id).toLocal8Bit();
            std::string numStr = std::string(ba.data(), ba.size());
            int n = numStr.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 1:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].lastName.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 2:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].firstName.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 3:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].middleName.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 4:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].birthDay.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 5:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].phoneNumber.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 6:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].eMail.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 7:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].carBrand.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 8:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].carModel.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 9:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].carYear.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 10:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].carColor.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 11:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].carVIN.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    case 12:
        for (size_t i = 0; i < temp.size(); i++) {
            int n = temp[i].carNumber.find(substr);
            if (n >= 0) {
                result.push_back(i + 1);
            }
        }
        break;
    }
    return result;
}
