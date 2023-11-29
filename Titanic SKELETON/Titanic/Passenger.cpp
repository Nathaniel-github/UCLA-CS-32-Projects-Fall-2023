//
//  Passenger.cpp
//  Titanic
//
//  Created by Nathaniel Thomas on 11/8/23.
//

#include "Passenger.h"
#include "Enums.h"
#include <string>
#include <iostream>

namespace cs32 {

Passenger::Passenger() {
    // must be defined but we can't do much with an empty constructor
}

void Passenger::setName(std::string name) {
    mName = name; // set the name to the field
}
std::string Passenger::getName() {
    return mName; // get the field of name
}

void Passenger::setEmbarcation(std::string embarked) {
    if (embarked == "C") { // if its Cherbourg
        mEmbarcation = Embarcation::CHERBOURG;
    } else if (embarked == "Q") { // if its Queenstown
        mEmbarcation = Embarcation::QUEENSTOWN;
    } else if (embarked == "S") { // if its Southhampton
        mEmbarcation = Embarcation::SOUTHHAMPTON;
    } else { // if its anything else
        mEmbarcation = Embarcation::NOTKNOWN;
    }
}
void Passenger::setClass(std::string classofFare) {
    if (classofFare == "1") { // if its first class
        mClass = Class::FIRST;
    } else if (classofFare == "2") { // if its second class
        mClass = Class::SECOND;
    } else if (classofFare == "3") { // if its third class
        mClass = Class::THIRD;
    } else { // if its anything else
        mClass = Class::NOTKNOWN;
    }
}
void Passenger::setSurvived(std::string survived) {
    if (survived == "1") { // if they survived
        mSurvived = true;
    } else { // they died
        mSurvived = false;
    }
}
void Passenger::setFare(std::string fare) {
    if (fare == "") { // empty fare field means the data is missing and we use 0 to show an invalid fare field
        mFare = 0;
        return;
    }
    mFare = std::stof(fare);
}

Embarcation Passenger::getEmbarcation() {
    return mEmbarcation; // return the field of embarcation
}
Class Passenger::getClass() {
    return  mClass; // get the field of class
}
bool Passenger::getSurvived() {
    return mSurvived; // get the field of survived
}
double Passenger::getFare() {
    return mFare; // get the field of fare
}

}
