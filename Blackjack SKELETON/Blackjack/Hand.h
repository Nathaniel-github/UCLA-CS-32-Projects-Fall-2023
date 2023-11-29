//
//  Hand.h
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//
/*
 Modified and completed by Nathaniel Thomas on 10/11/23
 */

#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Enums.h"

namespace cs32
{

// this class represents an opening blackjack player hand of
// two cards
// although this class builds and runs, various TODO operations
// need to be completed by CS 32 students
class Hand
{
public:
    Hand( Card card1, Card card2 );
    // getters for the Card fields of this class
    Card getCard1() const;
    Card getCard2() const;
    

    // TODO CS 32 students need to complete this operation
    // for a dealers card, what should the player's move be
    // based on the strategy card provided in the assignment?
    Choice evaluateHand( Card dealerCard ) const;
    
    // TODO CS 32 students need to complete this operation
    // is this hand made up of two matching Face cards?
    bool isPair() const;
    // TODO CS 32 students need to complete this operation
    // is this hand made up of atleast one Ace?
    bool isSoft() const;
private:
    // the data members of each Hand class
    Card mCard1, mCard2;
    Choice choices[27][10];
};


}


#endif
