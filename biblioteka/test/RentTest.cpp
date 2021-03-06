//
// Created by student on 17.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/rent.h"
#include "model/client.h"
#include "model/vehicle.h"
#include "model/clientGold.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentRentDataTimeCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd, 7);
        BOOST_REQUIRE_EQUAL(wypozyczenie.getPeriod(), 7);
    }

    BOOST_AUTO_TEST_CASE(RentEndDateTimeCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd, 10);
        wypozyczenie.endRent();
        BOOST_REQUIRE(wypozyczenie.getPeriod() + 1 == 11);
    }

    BOOST_AUTO_TEST_CASE(RentPeriodTimeCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        wypozyczenie.endRent();
        BOOST_REQUIRE(wypozyczenie.getRentDate().local_time() <= wypozyczenie.getEndDate().local_time());
    }

    BOOST_AUTO_TEST_CASE(RentValueCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        wypozyczenie.endRent();
        BOOST_REQUIRE_EQUAL(wypozyczenie.getTotalPrice(), (wypozyczenie.getPeriod() + 1) * pojazd -> getPrice());
    }

    BOOST_AUTO_TEST_CASE(RentClientCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        BOOST_REQUIRE_EQUAL(wypozyczenie.getClient(), client);
    }

    BOOST_AUTO_TEST_CASE(RentEndClientCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        wypozyczenie.endRent();
        BOOST_REQUIRE_EQUAL(wypozyczenie.getClient(), client);
    }

    BOOST_AUTO_TEST_CASE(RentTotalPriceCase)
    {
        ClientPtr client = make_shared<Client>("Emil", "Kowalczyk", "123", "Zwolinskiego", 8, "Lowicka", 13);
        VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "5Y80");
        Rent wypozyczenie(client, pojazd);
        ClientTypePtr typeOfClient(new ClientGold);
        (*client).setClientType(typeOfClient);
        wypozyczenie.endRent();
        BOOST_REQUIRE_EQUAL(wypozyczenie.getTotalPrice(), int(pojazd->getPrice() * (1 - client -> getDiscount())));
    }


BOOST_AUTO_TEST_SUITE_END()

