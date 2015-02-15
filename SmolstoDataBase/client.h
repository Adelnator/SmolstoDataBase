#ifndef CLIENT_H
#define CLIENT_H

#include <mainwindow.h>

class Client {
public:
    Client();
    ~Client();
    int id;
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string birthDay;
    std::string phoneNumber;
    std::string eMail;

    std::string carBrand;
    std::string carModel;
    std::string carYear;
    std::string carColor;
    std::string carVIN;
    std::string carNumber;
};

#endif // CLIENT_H
