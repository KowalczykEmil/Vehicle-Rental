//
// Created by student on 17.06.2020.
//

#ifndef POBIPROJECT_RENT_H
#define POBIPROJECT_RENT_H
#include <string>
#include <memory>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/uuid.hpp>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::uuids;
class Client;
class Vehicle;
class RentsManager;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Vehicle> VehiclePtr;

class Rent
{
private:
    uuid ID;
    local_date_time *rentDateTime;
    local_date_time *endDateTime;
    int totalPrice;
    VehiclePtr vehicle;
    ClientPtr client;
public:
    Rent(const ClientPtr&, const VehiclePtr&, int=0);
    Rent(const Rent&);
    Rent& operator= (const Rent&) = default;
    ~Rent();
    string rentInfo() const;
    void endRent();
    int getPeriod() const;
    const int& getTotalPrice() const;
    const ClientPtr& getClient() const;
    const local_date_time& getRentDate() const;
    const local_date_time& getEndDate() const;
    const uuid& getID() const;
    const string& getRegistrationNumber() const;
    bool operator== (const Rent&) const;
};

typedef shared_ptr<Rent> RentPtr;

struct FindByID
{
    uuid ID;
    explicit FindByID(const uuid&);
    bool operator()(const RentPtr&) const;
};


#endif //POBIPROJECT_RENT_H
