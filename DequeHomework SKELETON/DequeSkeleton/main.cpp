// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cassert>
#include "Deque.h"
#include "Deque.cpp"
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Garage.h"


int main()
{

    using namespace std;
    using namespace cs32;
  
    // Deque Tests

    Deque< int > dInt;
    int x;
    Deque< std::string > dString;
    std::string s;

    dInt.deleteFront( );
    dInt.deleteRear( );
    x = 12;
    assert( dInt.deleteItem( x ) == false );
    assert( dInt.size( ) == 0 );
    assert( dInt.get( -10, x ) == false );
    assert( dInt.isEmpty( )  );

    s = "Hello";
    dString.addToFront( s );
    s = "World!";
    dString.addToRear( s );
    s = "Howard";
    assert( dString.deleteItem( s ) == false );
    assert( dString.size( ) == 2 );
    assert( dString.get( -10, s ) == false );
    assert( dString.isEmpty( ) == false );
    assert( dString.get( 0, s ) && s == "Hello" );
    assert( dString.get( 1, s ) && s == "World!" );
    dString.deleteFront( );
    s = "Hello";
    assert( dString.deleteItem( s ) == false );
    assert( dString.size( ) == 1 );
    assert( dString.get( 0, s ) && s == "World!" );
    assert( dString.isEmpty( ) == false );
    dString.deleteRear( );
    s = "World!";
    assert( dString.deleteItem( s ) == false );
    assert( dString.size( ) == 0 );
    assert( dString.get( 0, s ) == false );
    assert( dString.isEmpty( ) );
    
    // Test 1: isEmpty()
    Deque<int> emptyDeque;
    assert(emptyDeque.isEmpty());

    // Test 2: addToFront() and deleteFront()
    Deque<int> deque1;
    deque1.addToFront(5);
    deque1.addToFront(10);
    assert(!deque1.isEmpty());
    assert(deque1.front() == 10);
    deque1.deleteFront();
    assert(deque1.front() == 5);

    // Test 3: addToRear() and deleteRear()
    Deque<int> deque2;
    deque2.addToRear(15);
    deque2.addToRear(20);
    assert(!deque2.isEmpty());
    assert(deque2.rear() == 20);
    deque2.deleteRear();
    assert(deque2.rear() == 15);

    // Test 4: deleteItem()
    Deque<int> deque3;
    deque3.addToFront(5);
    deque3.addToFront(10);
    deque3.addToFront(15);
    assert(deque3.deleteItem(10));
    assert(deque3.front() == 15);

    // Test 5: makeEmpty()
    deque3.makeEmpty();
    assert(deque3.isEmpty());

    // Test 6: printItems()
    Deque<int> deque4;
    deque4.addToFront(5);
    deque4.addToFront(10);
    deque4.addToFront(15);
    std::cout << deque4.printItems() << std::endl;

    // Test 7: operator=()
    Deque<int> deque5 = deque2;
    assert(deque5.rear() == 15);

    // Test 8: size()
    assert(deque5.size() == 1);

    // Test 9: get()
    int data;
    assert(deque5.get(0, data) && data == 15);
    
    // Test 1: deleteFront() and deleteRear() on an empty deque
    Deque<int> emptyDeque2;
    emptyDeque2.deleteFront();
    emptyDeque2.deleteRear();

    // Test 2: deleteItem() on an empty deque
    assert(!emptyDeque2.deleteItem(42));

    // Test 3: get() on an empty deque
    int emptyDequeData;
    assert(!emptyDeque2.get(0, emptyDequeData));

    // Test 4: size() on an empty deque
    assert(emptyDeque2.size() == 0);

    // Test 5: addToFront(), addToRear(), and deleteItem() with one element
    Deque<int> singleElementDeque;
    singleElementDeque.addToFront(5);
    assert(singleElementDeque.size() == 1);
    assert(singleElementDeque.deleteItem(5));
    assert(singleElementDeque.size() == 0);

    // Garage Tests
    Garage g;
    Garage gSix( 6 );

    assert( g.size( ) == 0 );
    assert( g.capacity( ) == 10 );
     
    assert( gSix.size( ) == 0 );
    assert( gSix.capacity( ) == 6 );
    gSix.tossIn( "shoes" );
    gSix.tossIn( "shirts" );
    gSix.tossIn( "books" );
    assert( gSix.size( ) == 3 );
    assert( gSix.capacity( ) == 6 );
    gSix.tossIn( "suitcases" );
    assert( gSix.tossIn( "tables" ) == false );  // nothing thrown away
    assert( gSix.tossIn( "chairs" ) == false );  // nothing thrown away
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "shoes" ) );
    assert( gSix.find( "shirts" ) );
    assert( gSix.find( "books" ) );
    assert( gSix.find( "suitcases" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );

    assert( gSix.tossIn( "boxes" ) );  // shoes thrown away...
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "boxes" ) );
    assert( gSix.find( "shoes" )  == false );
    assert( gSix.find( "shirts" ) );
    assert( gSix.find( "books" ) );
    assert( gSix.find( "suitcases" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );

    assert( gSix.tossOut( "shoes" ) == false );   // shoes not found...
    assert( gSix.use( "shoes" ) == false );       // shoes not found...
    assert( gSix.use( "tables" ) );

    assert( gSix.tossIn( "records" ) );     // shirts thrown away...
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "boxes" ) );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) );
    assert( gSix.find( "suitcases" ) );

    assert( gSix.tossOut( "books" ) );
    assert( gSix.tossOut( "records" ) );
    assert( gSix.tossOut( "shoes" ) == false);
    assert( gSix.size( ) == 4 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) == false );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );
    assert( gSix.find( "boxes" ) );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) == false );
    assert( gSix.find( "suitcases" ) );

    assert( gSix.tossOut( "tables" ) );
    assert( gSix.tossOut( "boxes" ) );
    assert( gSix.tossOut( "suitcases" ) );
    assert( gSix.size( ) == 1 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) == false );
    assert( gSix.find( "tables" ) == false );
    assert( gSix.find( "boxes" ) == false );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) == false );
    assert( gSix.find( "suitcases" ) == false );
    assert( gSix.find( "chairs" ) );
    
    Garage garage1(3);
    assert(!garage1.tossIn("Car"));
    assert(garage1.size() == 1);
    assert(!garage1.tossIn("Bicycle"));
    assert(garage1.size() == 2);
    assert(!garage1.tossIn("Motorcycle"));
    assert(garage1.size() == 3);
    assert(garage1.tossIn("Truck")); // Garage is full, should replace the oldest item

    // Test 2: tossOut() and size()
    assert(garage1.tossOut("Bicycle"));
    assert(garage1.size() == 2);
    assert(!garage1.tossOut("Bicycle")); // Not in the garage anymore

    // Test 3: use() and size()
    assert(garage1.use("Truck"));
    assert(garage1.size() == 2);
    assert(!garage1.use("Person")); // Person is not in the garage

    // Test 4: find()
    assert(garage1.find("Motorcycle"));

    // Test 5: capacity()
    assert(garage1.capacity() == 3);
    
    // Test 1: tossIn() and size() with capacity 0
    Garage emptyCapacityGarage(0);
    assert(!emptyCapacityGarage.tossIn("Car"));
    assert(emptyCapacityGarage.size() == 0);

    // Test 2: tossIn() with capacity 1
    Garage singleCapacityGarage(1);
    assert(!singleCapacityGarage.tossIn("Bicycle"));
    assert(singleCapacityGarage.size() == 1);
    assert(singleCapacityGarage.tossIn("Motorcycle")); // Replace the oldest item
    assert(singleCapacityGarage.size() == 1);

    // Test 3: tossOut() with an empty garage
    assert(!emptyCapacityGarage.tossOut("Car"));

    // Test 4: use() with an empty garage
    assert(!emptyCapacityGarage.use("Car"));

    // Test 5: find() with an empty garage
    assert(!emptyCapacityGarage.find("Car"));

    // Test 6: capacity() and size() with a non-empty garage
    assert(singleCapacityGarage.capacity() == 1);
    assert(singleCapacityGarage.size() == 1);
    
    // Test the operator= method
    Deque<int> d1;
    d1.addToRear(10);
    d1.addToRear(20);
    Deque<int> d2;
    d2 = d1;
    assert(d2.size() == 2);
    assert(d2.front() == 10);
    assert(d2.rear() == 20);

    cout << "all tests passed!" << endl;
    return( 0 );
}

