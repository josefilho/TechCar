#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class People
{
public:
    People(string name, string cpf, string address, string phone, string email);

    void setName(string name);
    void setAddress(string address);
    void setPhone(string phone);
    void setEmail(string email);

    string getId();
    string getName();
    string getCpf();
    string getAddress();
    string getPhone();
    string getEmail();

private:
    string _id;
    string _name;
    string _CPF;
    string _address;
    string _phone;
    string _email;
};

#endif // PEOPLE_H
