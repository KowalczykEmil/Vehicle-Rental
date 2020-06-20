//
// Created by student on 26.04.2020.
//

#ifndef clientClass
#define clientClass
#include <string>
#include <iostream>
#include "model/address.h"
#include <vector>
#include "model/rent.h"

using namespace std;

class Rent;

class Client
{
private:
    string firstName;
    string lastName;
    string personalID;
    Address *address;
    Address *registeredAddress;
    vector<Rent *> rentVector{};
public:
    Client(string imie, string nazwisko, string id, string ulica, int nrDomu, string ulica2, int nrDomu2);
    Client(const Client &c);
    Client& operator= (const Client&);
    ~Client();
    void clientInfo();
    void setLastName(string newLastName);
    void setAddress(Address newAddress);
    void setRegisteredAddress(Address newAddress);
    string getFirstName();
    string getLastName();
    string getPersonalID();
    string getAddress();
    string getRegisteredAddress();
    void addRent(Rent *r);
    void allRents();
};
#endif

