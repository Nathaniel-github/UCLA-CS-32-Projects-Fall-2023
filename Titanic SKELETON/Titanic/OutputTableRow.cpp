//
//  OutputTableRow.cpp
//  Titanic
//
//  Created by Nathaniel Thomas on 11/11/23.
//

#include "OutputTableRow.h"
#include <iostream>

namespace cs32 {

OutputTableRow::OutputTableRow() {
    // need to define this but doesn't make sense to put anything here
}

void OutputTableRow::setDescription(std::string description) {
    mDescription = description; // set the description for the row
}

void OutputTableRow::setSurvived(int survived) { // set survived for the row
    mSurvived = survived;
}

void OutputTableRow::setTotal(int total) { // set total for the row
    mTotal = total;
}

std::string OutputTableRow::getDescription() { // get description for the row
    return mDescription;
}

int OutputTableRow::getTotal() { // get total for the row
    return mTotal;
}

int OutputTableRow::getSurvived() { // get survived for row
    return mSurvived;
}

double OutputTableRow::getPercentage() { // get percentage for row
    if (static_cast<double>(mTotal) == 0) {
        return 0;
    }
    return mSurvived / static_cast<double>(mTotal);
}

void OutputTableRow::display() { // display the row in its entirety
    std::cout << mDescription << "\t" << mSurvived << "/" << mTotal << "\t" << padToThreeCharacters(getPercentage()*100) << std::endl;
}

std::string OutputTableRow::padToThreeCharacters(int value) {
    std::string answer = "";
    for (int i = 0; i < 3 - std::to_string(value).size(); i++) {
        answer += " ";
    }
    answer += std::to_string(value);
    return answer;
}

}
