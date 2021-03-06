//
// Created by student on 19.06.2020.
//

#include "model/vehicleManager.h"
#include "model/rent.h"
#include "model/vehicleRepository.h"
#include "model/vehicle.h"
#include "model/vehicleRepositoryException.h"


VehicleManager::VehicleManager()
        : currentVehicles(new VehicleRepository), archiveVehicles(new VehicleRepository)
{}

void VehicleManager::addVehicle(const VehiclePtr &vehicle)
{
    for(const auto& v : currentVehicles->getRepository())
    {
        if(*vehicle == *v)
        {
            throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleExists);
        }
    }
    for(const auto& v : archiveVehicles->getRepository())
    {
        if(*vehicle == *v)
        {
            archiveVehicles->remove(vehicle);
            break;
        }
    }
    currentVehicles->create(vehicle);
}

void VehicleManager::removeVehicle(const VehiclePtr &vehicle)
{
    currentVehicles->remove(vehicle);
    archiveVehicles->create(vehicle);
}

int VehicleManager::getNumberOfCurrentVehicles() const
{
    return currentVehicles->getRepository().size();
}

int VehicleManager::getNumberOfArchVehicles() const
{
    return archiveVehicles->getRepository().size();
}


