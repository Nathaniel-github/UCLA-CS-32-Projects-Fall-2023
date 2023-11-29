//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//
/*
 Modified and completed by Nathaniel Thomas on 10/11/23
 */

#include "Hand.h"

namespace cs32
{

Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 ), choices{
    {Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::HIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::HIT, Choice::HIT},
    {Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT},
    {Choice::HIT, Choice::HIT, Choice::STAND, Choice::STAND, Choice::STAND, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::HIT, Choice::HIT, Choice::HIT, Choice::SURRENDERHIT, Choice::HIT},
    {Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::HIT, Choice::HIT, Choice::SURRENDERHIT, Choice::SURRENDERHIT, Choice::SURRENDERHIT},
    {Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND},
    {Choice::HIT, Choice::HIT, Choice::HIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::HIT, Choice::HIT, Choice::HIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::HIT, Choice::HIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::HIT, Choice::HIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::HIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::STAND, Choice::DOUBLESTAND, Choice::DOUBLESTAND, Choice::DOUBLESTAND, Choice::DOUBLESTAND, Choice::STAND, Choice::STAND, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND},
    {Choice::SPLITHIT, Choice::SPLITHIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::SPLITHIT, Choice::SPLITHIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::HIT, Choice::HIT, Choice::HIT, Choice::SPLITHIT, Choice::SPLITHIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::DOUBLEHIT, Choice::HIT, Choice::HIT},
    {Choice::SPLITHIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::HIT, Choice::HIT, Choice::HIT, Choice::HIT},
    {Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT},
    {Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::STAND, Choice::SPLIT, Choice::SPLIT, Choice::STAND, Choice::STAND},
    {Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND, Choice::STAND},
    {Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT, Choice::SPLIT} // This is a 2D array representing every choice possible from the strategy card where the rows are the player hands and the columns represent the dealer card
}
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

// TODO CS 32 students need to complete this operation
Choice Hand::evaluateHand( Card dealerCard ) const
{
    // by default STAND
    Choice c = Choice::STAND;
    int handSum = mCard1.getValue() + mCard2.getValue();
    int dIdx = dealerCard.getValue() - 2;
    if (dealerCard.getFace() == Face::ACE) {
        dIdx = 9;
    }
    if (isPair()) {
        int cardVal = mCard1.getValue();
        
        //This helps use the value to get the correct index since ace is usually the last row/column in the strategy card
        if (mCard1.getFace() == Face::ACE) {
            cardVal = 11;
        }
        c = choices[cardVal + 15][dIdx];
    } else if (isSoft()) {
        int cardVal = 0;
        if (mCard1.getFace() == Face::ACE) {
            cardVal = mCard2.getValue();
        } else {
            cardVal = mCard1.getValue();
        }
        if (cardVal > 8) {
            cardVal = 8; // Just to handle the soft hands not included in the strategy card
        }
        c = choices[cardVal + 8][dIdx];
    } else {
        if (handSum < 8) {
            handSum = 8; // Just to handle the sum hands not included in the strategy card
        }
        c = choices[handSum - 8][dIdx];
    }
    return( c );
}

// TODO CS 32 students need to complete this operation
bool Hand::isPair() const
{
    return( mCard1.getFace() == mCard2.getFace());
}

// TODO CS 32 students need to complete this operation
bool Hand::isSoft() const
{
    return( mCard1.getFace() == Face::ACE || mCard2.getFace() == Face::ACE );
}


}
