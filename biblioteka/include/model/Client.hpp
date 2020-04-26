//
// Created by student on 26.04.2020.
//

#ifndef POBIPROJECT_CLIENT_HPP
#define POBIPROJECT_CLIENT_HPP

#endif //POBIPROJECT_CLIENT_HPP
#include <iostream>
#include <string>

class Client{
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
public:
    Client();
    Client(std::string firstname, std::string lastname, std::string personalID);
    std::string clientinfo();
    ~Client();

};