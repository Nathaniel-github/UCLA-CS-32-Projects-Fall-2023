//
//  main.cpp
//  Titanic
//
//  Created by Howard Stahl on 7/1/23.
//


#include <iostream>
#include <string>
#include <cassert>
#include "Passenger.h"
#include "PassengerDatabase.h"
#include "PassengerOutputTable.h"
#include "Settings.h"

int main()
{
   using namespace std;
   using namespace cs32;
 
    Passenger passenger2;
    passenger2.setName("Rose DeWitt Bukater");
    passenger2.setEmbarcation("C");
    passenger2.setClass("1");
    passenger2.setSurvived("1");
    passenger2.setFare("100.00");
    assert(passenger2.getName() == "Rose DeWitt Bukater");
    assert(passenger2.getClass() == Class::FIRST);
    assert(passenger2.getEmbarcation() == Embarcation::CHERBOURG);
    assert(std::to_string(passenger2.getFare()) == "100.000000");
    assert(passenger2.getSurvived() == true);
    // assert that all values of the assigned passenger were stored correctly

    OutputTableRow row2;
    row2.setDescription("additional testing");
    row2.setSurvived(8);
    row2.setTotal(12);
    assert(row2.getDescription() == "additional testing");
    assert(row2.getSurvived() == 8);
    assert(row2.getTotal() == 12);
    assert(std::to_string(row2.getPercentage()) == "0.666667");
    // test methods directly from outputtablerow

    PassengerDatabase emptyDatabase;
    assert(!emptyDatabase.loaded());  // Database should not be loaded initially.

    // Test loading a different dataset.
    PassengerDatabase anotherDatabase;
    anotherDatabase.load(PATH_TO_MOVIE_DATA_MAC);
    assert(anotherDatabase.loaded());

    // Test getting a passenger by a name that doesn't exist.
    Passenger *nonExistentPassenger = anotherDatabase.getPassenger_byName("Nonexistent");
    assert(nonExistentPassenger == nullptr);

    // Test creating an empty output table.
    vector<Passenger *> emptyPassengerList;
    PassengerOutputTable emptyTable(emptyPassengerList);
    assert(emptyTable.rowCount() == 0);

    // Test setting and getting a different output field.
    emptyTable.setOutputField(Field::BYEMBARCATION);
    assert(emptyTable.getOutputField() == Field::BYEMBARCATION);

    // Test displaying an empty table.
    emptyTable.setDescription("Empty Table");
    emptyTable.display();

    // Attempt to get passengers from an empty database.
    vector<Passenger *> emptyPassengers = emptyDatabase.getPassengers();
    assert(emptyPassengers.empty());

    // Attempt to get passengers by class from an empty database.
    vector<Passenger *> emptyClassPassengers = emptyDatabase.getPassengers_byClass(Class::SECOND, true, 0.00);
    assert(emptyClassPassengers.empty());

    // Test setting invalid values for Passenger attributes.
    Passenger invalidPassenger;
    invalidPassenger.setName("");
    invalidPassenger.setEmbarcation("X");  // Invalid Embarkation code
    invalidPassenger.setClass("4");        // Invalid Passenger class
    invalidPassenger.setSurvived("2");     // Invalid Survived value
    invalidPassenger.setFare("-5.00");      // Invalid Fare value

    // Ensure that the default values are set for invalid inputs.
    assert(invalidPassenger.getName() == "");
    assert(invalidPassenger.getEmbarcation() == Embarcation::NOTKNOWN);
    assert(invalidPassenger.getClass() == Class::NOTKNOWN);
    assert(invalidPassenger.getSurvived() == false);
    assert(invalidPassenger.getFare() == -5);

    // Test with passengers on the boundary of survival.
    Passenger boundaryPassenger;
    boundaryPassenger.setSurvived("1");  // Survived
    boundaryPassenger.setFare("0.00");   // Minimum Fare
    assert(boundaryPassenger.getSurvived() == true);
    assert(std::to_string(boundaryPassenger.getFare()) == "0.000000");

    // Test with passengers on the boundary of non-survival.
    Passenger nonSurvivalBoundaryPassenger;
    nonSurvivalBoundaryPassenger.setSurvived("0");  // Did not survive
    nonSurvivalBoundaryPassenger.setFare("999999");  // Maximum Fare
    assert(nonSurvivalBoundaryPassenger.getSurvived() == false);
    assert(nonSurvivalBoundaryPassenger.getFare() == 999999);

    // Test with a large dataset.
    PassengerDatabase largeDatabase;
    largeDatabase.load(PATH_TO_BIGGER_DATA_MAC);
    assert(largeDatabase.loaded());

    // Ensure the correct number of passengers is loaded.
    vector<Passenger *> largePassengers = largeDatabase.getPassengers();
    assert(largePassengers.size() > 1000);
    
    cout << "LOOK AT THIS" << endl;
    PassengerOutputTable pot(largeDatabase.getPassengers());
    pot.setOutputField(Field::BYEMBARCATION);
    pot.display();
    pot.setOutputField(Field::BYFARE);
    pot.display();
    pot.setOutputField(Field::BYCLASS);
    pot.display();
    cout << "LOOK AT THIS" << endl;
 
   Passenger passenger;
   passenger.setName( "Jack Dawson" );
   passenger.setEmbarcation( "S" );
   passenger.setClass( "3" );
   passenger.setSurvived( "0" );
   passenger.setFare( "12.50" );
   assert( passenger.getName() == "Jack Dawson" );
   assert( passenger.getClass() == Class::THIRD );
   assert( passenger.getEmbarcation() == Embarcation::SOUTHHAMPTON );
   assert( std::to_string(passenger.getFare()) == "12.500000" );
   assert( passenger.getSurvived() == false );
 
   OutputTableRow row;
   row.setDescription( "testing" );
   row.setSurvived( 5 );
   row.setTotal( 10 );
   assert( row.getDescription() == "testing" );
   assert( row.getSurvived() == 5 );
   assert( row.getTotal() == 10 );
   assert( std::to_string(row.getPercentage()) == "0.500000" );
 
   PassengerDatabase database;
   database.load( PATH_TO_MOVIE_DATA_MAC );
   if (database.loaded())
   {
      vector< Passenger * > byclass = database.getPassengers_byClass(Class::FIRST, true, -10.00);
      vector< Passenger * > byembark = database.getPassengers_byEmbarcation(Embarcation::SOUTHHAMPTON, true, 0.00);
    
      Passenger * p = database.getPassenger_byName( "Howard" );
      if (p)
         p->setEmbarcation( "S" );
   

      PassengerOutputTable t( byclass );
      t.setDescription( "List of First Class Survivors With Fare > 0" );
      t.setOutputField( Field::BYCLASS );
      assert( t.getDescription() == "List of First Class Survivors With Fare > 0" );
      assert( t.getOutputField() == Field::BYCLASS );
      t.display();
    
      vector< Passenger * > byclassdied = database.getPassengers_byClass(Class::FIRST, false, -10.00);
      PassengerOutputTable t1( byclassdied );
      t1.setDescription( "List of First Class Died With Fare > 0" );
      t1.setOutputField( Field::BYCLASS );
      t1.display();

      vector< Passenger * > all = database.getPassengers();
      PassengerOutputTable t2( all );
      t2.setDescription( "List of all passengers by class" );
      t2.setOutputField( Field::BYCLASS );
      t2.display();
 
      assert( t2.rowCount() == 4 );
      // first class
      row = t2.getRow( 0 );
      assert( row.getSurvived() == 4 );
      assert( row.getTotal() == 5 );
      assert( std::to_string(row.getPercentage()) == "0.800000" );
    
      t2.setDescription( "List of all passengers by embarcation" );
      t2.setOutputField( Field::BYEMBARCATION );
      t2.display();
    
      t2.setDescription( "List of all passengers by fare" );
      t2.setOutputField( Field::BYFARE );
      t2.display();
    
      t2.setDescription( "What is shown by NOVALUE??" );
      t2.setOutputField( Field::NOVALUE );
      t2.display();
    
   }
   else
   {
      cout << "database was not loaded correctly" << endl;
      cout << PATH_TO_MOVIE_DATA_MAC << " is not working!" << endl;
   }


   cout << "all tests passed!" << endl;
   return( 0 );
}
