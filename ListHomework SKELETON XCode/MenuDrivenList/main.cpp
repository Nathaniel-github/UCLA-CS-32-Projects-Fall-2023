// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"


using namespace std;
using namespace cs32;

enum class CHOICE {MAKEEMPTY, ISEMPTY, ADDTOFRONT, ADDTOREAR, DELETE, FIND, QUIT, PRINT, OPERATOR };

CHOICE menu();

int main()
{

       // test code
    
       // Create an empty list
       cs32::List myList;

       // Test isEmpty() for an empty list
       assert(myList.isEmpty() == true);

       // Add elements to the list
       myList.addToFront("A");
       myList.addToRear("B");
       myList.addToFront("C");
       myList.addToRear("D");
       myList.addToFront("E");

       // Test isEmpty() for a non-empty list
       assert(myList.isEmpty() == false);

       // Test size() should be 5
       assert(myList.size() == 5);

       // Test position() for most elements and one non-present element
       assert(myList.position("A") == 2);
       assert(myList.position("B") == 3);
       assert(myList.position("E") == 0);
       assert(myList.position("F") == -1);

       // Test before() for true and false
       assert(myList.before("C", "D") == true);
       assert(myList.before("B", "A") == false);

       // Test get() for 2 positions that are present and verify their correctness and 1 position that isn't present
       string data;
       assert(myList.get(0, data) == true);
       assert(data == "E");
       assert(myList.get(4, data) == true);
       assert(data == "D");
       assert(myList.get(5, data) == false);

       // Test min() for the list
       assert(myList.min() == "A");

       // Test deleteItem() for the minimum and verify the change in list size as well as lack of deleted item position
       myList.deleteItem("A");
       assert(myList.size() == 4);
       assert(myList.position("A") == -1);

       // Test removeAllBiggerThan() for smallest element resulting in a list of one element
       myList.removeAllBiggerThan("B");
       assert(myList.size() == 1);
       assert(myList.position("D") == -1);
       assert(myList.position("C") == -1);
       assert(myList.position("B") == 0);

       // Test copy constructor and verify the elements are the same
       cs32::List copyList(myList);
       assert(copyList.size() == 1);
       assert(copyList.position("D") == -1);
       assert(copyList.position("C") == -1);
       assert(copyList.position("B") == 0);

       // Test assignment operator and verify the elements are the same
       cs32::List assignList;
       assignList = myList;
       assert(assignList.size() == 1);
       assert(assignList.position("D") == -1);
       assert(assignList.position("C") == -1);
       assert(assignList.position("B") == 0);

       // the get function enables a client to iterate over all elements of a List
       List l1;
       assert( l1.min() == "" );
       l1.addToFront("Hawkeye");
       l1.addToFront("Thor");
       l1.addToFront("Hulk");
       l1.addToFront("Black Widow");
       l1.addToFront("Iron Man");
       l1.addToFront("Captain America");
       for (int k = 0; k < l1.size(); k++)
       {
          string x;
          l1.get(k, x);
          cout << x << endl;
       }
       // should print:
       // Captain America
       // Iron Man
       // Black Widow
       // Hulk
       // Thor
       // Hawkeye
       assert( l1.position( "Hawkeye" ) == 5 );
       assert( l1.position( "Thor" ) == 4 );
       assert( l1.position( "Hulk" ) == 3 );
       assert( l1.position( "Black Widow" ) == 2 );
       assert( l1.position( "Iron Man" ) == 1 );
       assert( l1.position( "Captain America" ) == 0 );
       assert( l1.position( "Not there" ) == -1 );

       assert( l1.before( "Not there", "Hulk" ) == false );
       assert( l1.before( "Hulk", "Not there" ) == false );
       assert( l1.before( "Hulk", "Captain America" ) == false );
       assert( l1.before( "Black Widow", "Hulk" ) == true );
       assert( l1.before( "Captain America", "Hulk" ) == true );

       assert( l1.min() == "Black Widow" );

       l1.removeAllBiggerThan( "Happy" );
       // now just "Captain America", "Black Widow"
       assert( l1.size() == 2 );
       assert( l1.position( "Hawkeye" ) == -1 );
       assert( l1.position( "Thor" ) == -1 );
       assert( l1.position( "Hulk" ) == -1 );
       assert( l1.position( "Black Widow" ) == 1 );
       assert( l1.position( "Iron Man" ) == -1 );
       assert( l1.position( "Captain America" ) == 0 );
       assert( l1.position( "Not there" ) == -1 );

       cout << "all tests passed!" << endl;
       return( 0 );
}

//int main(int argc, char* argv[]) {
//
//	string value;
//	List list;
//    List list2;
//
//	CHOICE choice;
//	do {
//		choice = menu();
//		switch( choice ) {
//        case CHOICE::MAKEEMPTY:
//			list.makeEmpty();
//			break;
//        case CHOICE::ISEMPTY:
//			if (list.isEmpty()) {
//				cout << "list is empty" << endl;
//			}
//			else {
//				cout << "list is not empty" << endl;
//			}
//			break;
//        case CHOICE::DELETE:
//			cout << "Please provide a string to remove: ";
//			cin  >> value;
//			list.deleteItem( value );
//			break;
//        case CHOICE::ADDTOFRONT:
//			cout << "Please provide a string to insert in front: ";
//			cin  >> value;
//			list.addToFront( value );
//			break;
//        case CHOICE::ADDTOREAR:
//            cout << "Please provide a string to insert in rear: ";
//            cin  >> value;
//            list.addToRear( value );
//            break;
//        case CHOICE::FIND:
//			cout << "Please provide a string to find: ";
//			cin  >> value;
//            cout.setf( ios::boolalpha );
//            cout << list.findItem( value ) << endl;
//            cout.unsetf( ios::boolalpha );
//			break;
//        case CHOICE::PRINT:
//            cout << list.printItems() << endl;;
//			break;
//        case CHOICE::OPERATOR:
//            list2 = list;
//            cout << "second list now:" << endl;
//            cout << list2.printItems() << endl;
//            break;
//        case CHOICE::QUIT:
//            break;
//	}
//
//	} while (choice != CHOICE::QUIT);
//
//	return( 0 );
//}

CHOICE menu() {
	string s;
	CHOICE result;
	cout << "(M)akeEmpty I(s)Empty (D)elete (A)ddToFront (R)AddtoRear  (F)ind (P)rint (=) (Q)uit: " << endl;
	cin  >> s;
    char choice = s.at( 0 );
	switch( choice ) {
	case 'M':
	case 'm':
		result = CHOICE::MAKEEMPTY;
		break;
    case 'D':
    case 'd':
        result = CHOICE::DELETE;
        break;
	case 'S':
	case 's':
		result = CHOICE::ISEMPTY;
		break;
    case 'A':
    case 'a':
        result = CHOICE::ADDTOFRONT;
        break;
	case 'R':
	case 'r':
		result = CHOICE::ADDTOREAR;
		break;
	case 'F':
	case 'f':
		result = CHOICE::FIND;
		break;
	case 'Q':
	case 'q':
		result = CHOICE::QUIT;
		break;
	case 'P':
	case 'p':
		result = CHOICE::PRINT;
		break;
    case '=':
        result = CHOICE::OPERATOR;
        break;
    default:
        result = CHOICE::QUIT;
        break;
	}

	return( result );
}
