//
//  PassengerOutputTable.cpp
//  Titanic
//
//  Created by Nathaniel Thomas on 11/11/23.
//

#include "PassengerOutputTable.h"
#include "Enums.h"
#include <vector>
#include <iostream>

namespace cs32 {

PassengerOutputTable::PassengerOutputTable(std::vector< Passenger * > passengers) { // initialize output table with passenger list and no grouping field for now
    mPassengerList = passengers;
    mField = Field::NOVALUE;
}

void PassengerOutputTable::setOutputField(Field f) { // set the grouping field for the list
    mField = f;
}
void PassengerOutputTable::setDescription(std::string description) { // set description
    mDescription = description;
}
Field PassengerOutputTable::getOutputField() { // get grouping field
    return mField;
}
std::string PassengerOutputTable::getDescription() { // get description
    return mDescription;
}

void PassengerOutputTable::display() {
    mRows.clear();
    switch (mField) { // pick the output field we want to group by
        case Field::BYFARE: {
            int s1_10 = 0, s10_25 = 0, s25_50 = 0, s50 = 0, snk = 0, t1_10 = 0, t10_25 = 0, t25_50 = 0, t50 = 0, tnk = 0;
            for (Passenger * p : mPassengerList) { // iterate passenger list and count survived and totals for each subgroup
                if (p->getFare() > 0 && p->getFare() <= 10) {
                    if (p->getSurvived()) {
                        s1_10++;
                    }
                    t1_10++;
                } else if (p->getFare() > 10 && p->getFare() <= 25) {
                    if (p->getSurvived()) {
                        s10_25++;
                    }
                    t10_25++;
                } else if (p->getFare() > 25 && p->getFare() <= 50) {
                    if (p->getSurvived()) {
                        s25_50++;
                    }
                    t25_50++;
                } else if (p->getFare() > 50) {
                    if (p->getSurvived()) {
                        s50++;
                    }
                    t50++;
                } else {
                    if (p->getSurvived()) {
                        snk++;
                    }
                    tnk++;
                }
            }
            OutputTableRow o1, o2, o3, o4, o5;
            o1.setDescription("Not Known");
            o1.setTotal(tnk);
            o1.setSurvived(snk);
            o2.setDescription("$0-$10");
            o2.setTotal(t1_10);
            o2.setSurvived(s1_10);
            o3.setDescription("$10-$25");
            o3.setTotal(t10_25);
            o3.setSurvived(s10_25);
            o4.setDescription("$25-$50");
            o4.setTotal(t25_50);
            o4.setSurvived(s25_50);
            o5.setDescription(">$50");
            o5.setTotal(t50);
            o5.setSurvived(s50);
            
            std::cout << mDescription << std::endl;
            std::cout << "\tSurvived/Total\t%" << std::endl; // basic title of output table
            
            mRows.push_back(o1);
            mRows.push_back(o2);
            mRows.push_back(o3);
            mRows.push_back(o4);
            mRows.push_back(o5); // push the individual rows to the list
            break;
        }
        case Field::BYCLASS: {
            int sf = 0, ss = 0, st = 0, snk = 0, tf = 0, ts = 0, tt = 0, tnk = 0;
            for (Passenger * p : mPassengerList) { // iterate passenger list
                switch (p->getClass()) { // count survived and total for each grouping
                    case Class::FIRST:
                        if (p->getSurvived()) {
                            sf++;
                        }
                        tf++;
                        break;
                    case Class::SECOND:
                        if (p->getSurvived()) {
                            ss++;
                        }
                        ts++;
                        break;
                    case Class::THIRD:
                        if (p->getSurvived()) {
                            st++;
                        }
                        tt++;
                        break;
                    default:
                        if (p->getSurvived()) {
                            snk++;
                        }
                        tnk++;
                        break;
                }
            }
            OutputTableRow o1, o2, o3, o4;
            o4.setDescription("Not Known");
            o4.setTotal(tnk);
            o4.setSurvived(snk);
            o1.setDescription("First Class");
            o1.setTotal(tf);
            o1.setSurvived(sf);
            o2.setDescription("Second Class");
            o2.setTotal(ts);
            o2.setSurvived(ss);
            o3.setDescription("Third Class");
            o3.setTotal(tt);
            o3.setSurvived(st);
            
            std::cout << mDescription << std::endl;
            std::cout << "\tSurvived/Total\t%" << std::endl; // basic title of output table
            
            mRows.push_back(o1);
            mRows.push_back(o2);
            mRows.push_back(o3);
            mRows.push_back(o4);
            // push all rows to the field and prepare for print
            break;
        }
        case Field::BYEMBARCATION: {
            int sc = 0, sq = 0, ss = 0, snk = 0, tc = 0, tq = 0, ts = 0, tnk = 0;
            for (Passenger * p : mPassengerList) { // iterate passenger list
                switch (p->getEmbarcation()) { // group the passengers by their embarcation
                    case Embarcation::CHERBOURG:
                        if (p->getSurvived()) {
                            sc++;
                        }
                        tc++;
                        break;
                    case Embarcation::QUEENSTOWN:
                        if (p->getSurvived()) {
                            sq++;
                        }
                        tq++;
                        break;
                    case Embarcation::SOUTHHAMPTON:
                        if (p->getSurvived()) {
                            ss++;
                        }
                        ts++;
                        break;
                    default:
                        if (p->getSurvived()) {
                            snk++;
                        }
                        tnk++;
                        break;
                }
                
            }
            OutputTableRow o1, o2, o3, o4;
            o4.setDescription("Not Known");
            o4.setTotal(tnk);
            o4.setSurvived(snk);
            o1.setDescription("Cherbourg");
            o1.setTotal(tc);
            o1.setSurvived(sc);
            o2.setDescription("Queenstown");
            o2.setTotal(tq);
            o2.setSurvived(sq);
            o3.setDescription("Southhampton");
            o3.setTotal(ts);
            o3.setSurvived(ss);
            
            std::cout << mDescription << std::endl;
            std::cout << "\tSurvived/Total\t%" << std::endl; // basic title of output table
            
            mRows.push_back(o1);
            mRows.push_back(o2);
            mRows.push_back(o3);
            mRows.push_back(o4); // initialize and push all rows to the rows field
            break;
        }
        default:
            break;
    }
    for (OutputTableRow o : mRows) { // print out all rows
        o.display();
    }
}

size_t PassengerOutputTable::rowCount() { // get number of rows
    return mRows.size();
}

OutputTableRow PassengerOutputTable::getRow(int index) { // get individual row
    return mRows.at(index);
}

}
