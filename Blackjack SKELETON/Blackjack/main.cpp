//
//  main.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//
/*
 Modified and completed by Nathaniel Thomas on 10/11/23
 */

#include <iostream>
#include <cassert>
#include "Enums.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
using namespace cs32;

int main() {
    
    // test code for Card to make sure its methods are likely working
    
    Card c( Suit::CLUBS, Face::DEUCE );
    assert( c.getSuit() == Suit::CLUBS );
    assert( c.getFace() == Face::DEUCE );
    assert( c.getValue( ) == 2 );
    
    Card d( Suit::SPADES, Face::QUEEN );
    assert( d.getSuit() == Suit::SPADES );
    assert( d.getFace() == Face::QUEEN );
    assert( d.getValue( ) == 10 );
    
    // test code for Hand to make sure its initialization and methods work as intended
    
    Card ace( Suit::CLUBS, Face::ACE );
    Card two( Suit::HEARTS, Face::DEUCE );
    Card three( Suit::DIAMONDS, Face::THREE );
    Card four( Suit::SPADES, Face::FOUR );
    Card five( Suit::CLUBS, Face::FIVE );
    Card six( Suit::HEARTS, Face::SIX );
    Card seven( Suit::DIAMONDS, Face::SEVEN );
    Card eight( Suit::SPADES, Face::EIGHT );
    Card nine( Suit::CLUBS, Face::NINE );
    Card ten( Suit::HEARTS, Face::TEN );
    Card jack( Suit::DIAMONDS, Face::JACK );
    Card queen( Suit::CLUBS, Face::QUEEN );
    Card king( Suit::SPADES, Face::KING );
    assert( ace.getValue( ) == 1 );
    assert( two.getValue( ) == 2 );
    assert( three.getValue( ) == 3 );
    assert( four.getValue( ) == 4 );
    assert( five.getValue( ) == 5 );
    assert( six.getValue( ) == 6 );
    assert( seven.getValue( ) == 7 );
    assert( eight.getValue( ) == 8 );
    assert( nine.getValue( ) == 9 );
    assert( ten.getValue( ) == 10 );
    assert( jack.getValue( ) == 10 );
    assert( queen.getValue( ) == 10 );
    assert( king.getValue( ) == 10 );
    
    // Test evaluating hand for a sum of 12 without aces or pairs
    Hand h( c, d );
    assert( h.evaluateHand(two) == Choice::HIT );
    assert( h.evaluateHand(three) == Choice::HIT );
    assert( h.evaluateHand(four) == Choice::STAND );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand(queen, king);
    // Make sure that even though the values are equal its technically not a pair
    assert(h.isPair() == false);
    
    // Testing a bunch of different normal sums that don't contain aces or pairs
    
    h = Hand( six, two );
    assert( h.evaluateHand(five) == Choice::HIT );
    assert( h.evaluateHand(six) == Choice::HIT );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand( six, three );
    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand( six, four );
    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(seven) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(eight) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(nine) == Choice::DOUBLEHIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand( six, five );
    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(seven) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(eight) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(nine) == Choice::DOUBLEHIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand( six, seven );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand( six, eight );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand( six, nine );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand( six, ten );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::SURRENDERHIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    h = Hand( seven, ten );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::STAND );
    assert( h.evaluateHand(eight) == Choice::STAND );
    assert( h.evaluateHand(nine) == Choice::STAND );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == false );
    
    // Testing all the ace hands
    
    h = Hand( ace, two );
    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == true );
    
    h = Hand( ace, three );
    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == true );
    
    h = Hand( ace, four );
    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == true );
    
    h = Hand( ace, five );
    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == true );
    
    h = Hand( ace, six );
    assert( h.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(seven) == Choice::HIT );
    assert( h.evaluateHand(eight) == Choice::HIT );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == true );
    
    h = Hand( ace, seven );
    assert( h.evaluateHand(five) == Choice::DOUBLESTAND );
    assert( h.evaluateHand(six) == Choice::DOUBLESTAND );
    assert( h.evaluateHand(seven) == Choice::STAND );
    assert( h.evaluateHand(eight) == Choice::STAND );
    assert( h.evaluateHand(nine) == Choice::HIT );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == true );
    
    h = Hand( ace, eight );
    assert( h.evaluateHand(five) == Choice::STAND );
    assert( h.evaluateHand(six) == Choice::STAND );
    assert( h.evaluateHand(seven) == Choice::STAND );
    assert( h.evaluateHand(eight) == Choice::STAND );
    assert( h.evaluateHand(nine) == Choice::STAND );
    assert( h.isPair( ) == false );
    assert( h.isSoft( ) == true );
    
    // Testing all the pair hands
    
    h = Hand( ace, ace );
    assert( h.evaluateHand(two) == Choice::SPLIT );
    assert( h.evaluateHand(three) == Choice::SPLIT );
    assert( h.evaluateHand(four) == Choice::SPLIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == true );
    
    h = Hand( two, two );
    assert( h.evaluateHand(two) == Choice::SPLITHIT );
    assert( h.evaluateHand(three) == Choice::SPLITHIT );
    assert( h.evaluateHand(four) == Choice::SPLIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( three, three );
    assert( h.evaluateHand(two) == Choice::SPLITHIT );
    assert( h.evaluateHand(three) == Choice::SPLITHIT );
    assert( h.evaluateHand(four) == Choice::SPLIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( four, four );
    assert( h.evaluateHand(two) == Choice::HIT );
    assert( h.evaluateHand(three) == Choice::HIT );
    assert( h.evaluateHand(four) == Choice::HIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( five, five );
    assert( h.evaluateHand(two) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(three) == Choice::DOUBLEHIT );
    assert( h.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( six, six );
    assert( h.evaluateHand(two) == Choice::SPLITHIT );
    assert( h.evaluateHand(three) == Choice::SPLIT );
    assert( h.evaluateHand(four) == Choice::SPLIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( seven, seven );
    assert( h.evaluateHand(two) == Choice::SPLIT );
    assert( h.evaluateHand(three) == Choice::SPLIT );
    assert( h.evaluateHand(four) == Choice::SPLIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( eight, eight );
    assert( h.evaluateHand(two) == Choice::SPLIT );
    assert( h.evaluateHand(three) == Choice::SPLIT );
    assert( h.evaluateHand(four) == Choice::SPLIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( nine, nine );
    assert( h.evaluateHand(two) == Choice::SPLIT );
    assert( h.evaluateHand(three) == Choice::SPLIT );
    assert( h.evaluateHand(four) == Choice::SPLIT );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( ten, ten );
    assert( h.evaluateHand(two) == Choice::STAND );
    assert( h.evaluateHand(three) == Choice::STAND );
    assert( h.evaluateHand(four) == Choice::STAND );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( jack, jack );
    assert( h.evaluateHand(two) == Choice::STAND );
    assert( h.evaluateHand(three) == Choice::STAND );
    assert( h.evaluateHand(four) == Choice::STAND );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( queen, queen );
    assert( h.evaluateHand(two) == Choice::STAND );
    assert( h.evaluateHand(three) == Choice::STAND );
    assert( h.evaluateHand(four) == Choice::STAND );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    h = Hand( king, king );
    assert( h.evaluateHand(two) == Choice::STAND );
    assert( h.evaluateHand(three) == Choice::STAND );
    assert( h.evaluateHand(four) == Choice::STAND );
    assert( h.isPair( ) == true );
    assert( h.isSoft( ) == false );
    
    cerr << "all tests passed!" << endl;
    
    return( 0 );
}
