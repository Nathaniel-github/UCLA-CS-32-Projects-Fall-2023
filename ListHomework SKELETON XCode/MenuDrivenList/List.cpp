#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}

// return the number of total data values found on the List.  It is marked const to indicate that the no data members of the List will be changed when implementing this operation.
size_t List::size() const {
    size_t count = 0;
    ListNode * node = head;
    while( node != nullptr ) {
        node = node->getNext();
        count++;
    }
    return count;
}

// Counting from zero (like an array index), return the location of the first occurrence of data found in the List.  If the data occurs multiple times on the List, you should return the location of the first occurrence.  If the data is not found, return minus one.  It is marked const to indicate that the no data members of the List will be changed when implementing this operation.
int    List::position( const std::string& data ) const {
    ListNode * node = head;
    int k = 0;
    for (; node != nullptr; k++, node = node->getNext()) {
        if (node->getElement() == data) {
            return k;
        }
    }
    return -1;
}

// If the before value is found on List at a position less than the after value, return true; otherwise, return false.  It is marked const to indicate that the no data members of the List will be changed when implementing this operation.
bool   List::before( const std::string& before, const std::string& after ) const {
    return position(before) < position(after) && position(before) != -1;
}

// Sets the value of the parameter data to be the element located at position i of the List (if that position exists) and return true if the position exists; otherwise, return false.  It is marked const to indicate that the no data members of the List will be changed when implementing this operation.
bool   List::get( int i, std::string& data ) const {
    ListNode * node = head;
    int k = 0;
    for (; node != nullptr; k++, node = node->getNext()) {
        if (k == i) {
            data = node->getElement();
            return true;
        }
    }
    return false;
}

// Returns the smallest item on the list.  If the list is empty, the empty string should be returned.  It is marked const to indicate that the no data members of the List will be changed when implementing this operation.  HINT: std::string supports < and > to do string comparisons
std::string   List::min() const {
    if (isEmpty()) {
        return "";
    }
    ListNode * node = head;
    string ans = node->getElement();
    node = node->getNext();
    while( node != nullptr ) {
        if (node->getElement() < ans) {
            ans = node->getElement();
        }
        node = node->getNext();
    }
    return ans;
}

//Alters the list by removing all the items bigger than data that were originally on the list.   HINT: std::string supports < and > to do string comparisons
void   List::removeAllBiggerThan( const std::string & data ) {
    ListNode * node = head;
    while( node != nullptr ) {
        string el = node->getElement();
        node = node->getNext();
        if (el > data) {
            deleteItem(el);
        }
    }
}

// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

}


