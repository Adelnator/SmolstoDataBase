#include "loadsavebase.h"
#include "client.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <io.h>

LoadSaveBase::LoadSaveBase() {}

std::vector <Client> LoadSaveBase::loadBase() {
    std::vector <Client> input;
    if(!access("database.txt", 0)) {
        int countInput, countOutput = 0, id;
        Client temp;
        std::string line;
        std::ifstream ifs;
        ifs.open("database.txt");

        ifs >> countInput;
        while (!ifs.eof()) {
            ifs >> id;
            temp.id = id;
            ifs >> line;
            temp.lastName = line;
            ifs >> line;
            temp.firstName = line;
            ifs >> line;
            temp.middleName = line;
            ifs >> line;
            temp.birthDay = line;
            ifs >> line;
            temp.phoneNumber = line;
            ifs >> line;
            temp.eMail = line;
            ifs >> line;
            temp.carBrand = line;
            ifs >> line;
            temp.carModel = line;
            ifs >> line;
            temp.carYear = line;
            ifs >> line;
            temp.carColor = line;
            ifs >> line;
            temp.carVIN = line;
            ifs >> line;
            temp.carNumber = line;

            input.push_back(temp);
            countOutput += 13;
        }
        //mod 13 <> 0 or div 13 <> countInput
        ifs.close();
        //fclose(ifs);

        if (countOutput % 13 != 0 || countOutput / 13 != countInput) {
            input[0].id = -1;
        }
    }
    return input;
}

void LoadSaveBase::saveBase(std::vector <Client> const& temp) {
    remove("database.txt");
    if (temp.size() != 0) {
        freopen("database.txt", "w", stdout);

        std::cout << temp.size() << std::endl;
        size_t i;
        for (i = 0; i < temp.size() - 1; i++) {
            std::cout << temp[i].id << std::endl;
            std::cout << temp[i].lastName << std::endl;
            std::cout << temp[i].firstName << std::endl;
            std::cout << temp[i].middleName << std::endl;
            std::cout << temp[i].birthDay << std::endl;
            std::cout << temp[i].phoneNumber << std::endl;
            std::cout << temp[i].eMail << std::endl;
            std::cout << temp[i].carBrand << std::endl;
            std::cout << temp[i].carModel << std::endl;
            std::cout << temp[i].carYear << std::endl;
            std::cout << temp[i].carColor << std::endl;
            std::cout << temp[i].carVIN << std::endl;
            std::cout << temp[i].carNumber << std::endl;
        }
        std::cout << temp[i].id << std::endl;
        std::cout << temp[i].lastName << std::endl;
        std::cout << temp[i].firstName << std::endl;
        std::cout << temp[i].middleName << std::endl;
        std::cout << temp[i].birthDay << std::endl;
        std::cout << temp[i].phoneNumber << std::endl;
        std::cout << temp[i].eMail << std::endl;
        std::cout << temp[i].carBrand << std::endl;
        std::cout << temp[i].carModel << std::endl;
        std::cout << temp[i].carYear << std::endl;
        std::cout << temp[i].carColor << std::endl;
        std::cout << temp[i].carVIN << std::endl;
        std::cout << temp[i].carNumber;
    }
}
