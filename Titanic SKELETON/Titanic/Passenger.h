//
//  Passenger.h
//  Titanic
//
//  Created by Nathaniel Thomas on 11/8/23.
//

#ifndef Passenger_h
#define Passenger_h

#include <string>
#include "Enums.h"

namespace cs32 {

class Passenger
{
public:
    Passenger();
    
    // getters and setters for name
    void setName(std::string name);
    std::string getName();
    
    // setters for the passenger class
    void setEmbarcation(std::string embarked);
    void setClass(std::string classofFare);
    void setSurvived(std::string survived);
    void setFare(std::string fare);
    
    // getters for the passenger class
    Embarcation getEmbarcation();
    Class getClass();
    bool getSurvived();
    double getFare();
private:
    Class mClass;
    Embarcation mEmbarcation;
    std::string mName;
    bool mSurvived;
    double mFare;
};

}

#endif
