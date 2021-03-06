//
// Created by student on 19.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/rentsRepository.h"
#include "model/bicycle.h"
#include <sstream>
#include "model/rent.h"
#include "model/client.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RepositoryReportCase)
    {
        ostringstream chain;
        RentsRepository repository;
        VehiclePtr Scott = make_shared<Bicycle>(110, "AB321");
        VehiclePtr Scott2 = make_shared<Bicycle>(110, "AB321");
        ClientPtr client1 = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        ClientPtr client2 = make_shared<Client>("Bogdan", "Kowalski", "123A90", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client1, Scott);
        repository.create(r);
        RentPtr r2 = make_shared<Rent>(client2, Scott2);
        chain << r->rentInfo();
        chain << r2->rentInfo();
        repository.create(r2);
        BOOST_REQUIRE_EQUAL(repository.getAll(), chain.str());
    }

BOOST_AUTO_TEST_SUITE_END()


