//
//  PassengerDatabase.cpp
//  Titanic
//
//  Created by Nathaniel Thomas on 11/8/23.
//
#include "PassengerDatabase.h"
#include "CSVFile.h"

namespace  cs32 {

PassengerDatabase::PassengerDatabase() {
    isLoaded = false; // to prevent some runtime errors
}

PassengerDatabase::~PassengerDatabase() { // need to delete all the newed passengers
    clearAllPassengers();
}

int PassengerDatabase::load(std::string filePath) { // read the csvfile and load the database
    CSVFile file( this );
    int recordCount = file.readFile( filePath );
    if (recordCount != 0) {
        isLoaded = true;
    } else {
        isLoaded = false;
    }
    return( recordCount );
}

void PassengerDatabase::clearAllPassengers() { // clear passengers while making sure to delete anything newed
    for (Passenger * p : passengers) {
        delete p;
    }
    passengers.clear();
}

bool PassengerDatabase::loaded() { // getter for loaded field
    return isLoaded;
}

Passenger * PassengerDatabase::getPassenger_byName(std::string name) { // iterate the passenger list and find the passenger with the desired name
    for (Passenger * p : passengers) {
        if (p->getName() == name) {
            return p;
        }
    }
    return nullptr;
}

std::vector< Passenger * > PassengerDatabase::getPassengers() { // return entire passenger list
    return passengers;
}

std::vector< Passenger * > PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare) {
    std::vector<Passenger *> selected;
    
    for (Passenger * p : passengers) { // iterate passenger list
        if (p->getClass() == paidClass && p->getSurvived() == survived && p->getFare() > minimumFare) { // check all conditions for the get by class call
            selected.push_back(p); // add it to the selected list if it meets conditions
        }
    }
    
    return selected;
}

std::vector< Passenger * > PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare) {
    std::vector<Passenger *> selected;
    
    for (Passenger * p : passengers) { // iterate passenger list
        if (p->getEmbarcation() == embarked && p->getSurvived() == survived && p->getFare() > minimumFare) { // check all conditions for the get by embarcation call
            selected.push_back(p); // add it to the selected list if it meets conditions
        }
    }
    
    return selected;
}

void PassengerDatabase::csvData(std::map< std::string, std::string > row) {
    Passenger * p = new Passenger();
    p->setName(row["name"]);
    p->setClass(row["pclass"]);
    p->setSurvived(row["survived"]);
    p->setFare(row["fare"]);
    p->setEmbarcation(row["embarked"]);
    // create a new passenger with all its fields set
    passengers.push_back(p); // add it to the passenger list
}

}
