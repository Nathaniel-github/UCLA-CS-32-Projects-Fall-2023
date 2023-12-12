#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

using namespace std;

namespace cs32 {

template <typename Type>
Deque<Type>::Deque(): head(nullptr), tail(nullptr)
{
}

template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr) // if the first node is null then all nodes must be null
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) { // copy over all elements of rhs
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty(); // clean out the deque
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    return( head == nullptr ); // if first node is null then all nodes are null
}

template <typename Type>
void Deque<Type>::makeEmpty() {
    DequeNode<Type>* node = head;
    while (node != nullptr) { // iterate and delete all nodes
        DequeNode<Type>* toDelete = node;
        node = node->getNext();
        delete toDelete;
    }
    head = nullptr; // reset to nullptrs
    tail = nullptr;
}

template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    if (isEmpty()) { // if empty set both head and tail to this
        head = new DequeNode<Type>(data);
        tail = head;
    } else { // set the node previous to head to this one and then reset head
        head->setPrevious(new DequeNode<Type>(data, head));
        head = head->getPrevious();
    }
}

template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    if (isEmpty()) { // if empty set both head and tail to this
        head = new DequeNode<Type>(data);
        tail = head;
    } else { // set the node after tail to this one and then reset tail
        tail->setNext(new DequeNode<Type>(data, nullptr, tail));
        tail = tail->getNext();
    }
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    if (isEmpty()) { // nothing to do if empty
        return;
    }
    if (head->getNext() == nullptr) { // if singular element make sure to reset head and tail
        delete head;
        head = nullptr;
        tail = nullptr;
    } else { // if anything else standard procedure
        DequeNode<Type>* toDelete = head;
        head = head->getNext();
        delete toDelete;
        head->setPrevious(nullptr);
    }
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    DequeNode<Type>* node = head;
    
    while (node != nullptr) { // iterate deque until found
        if (node->getElement() == data) { // if data found
            if (node->getNext() != nullptr) { // if its not the tail just set the next node to the one prev
                node->getNext()->setPrevious(node->getPrevious());
            } else { // if it is the tail we just delete rear
                deleteRear();
                return true;
            }
            if (node->getPrevious() != nullptr) { // making sure its not the head node
                node->getPrevious()->setNext(node->getNext()); // link the previous node around this one
            } else { // if it is the head then just re assign the head and pop it off
                deleteFront();
                return true;
            }
            delete node; // remove trace of this node and return true
            return true;
        }
        node = node->getNext();
    }

    return( false );
}

// simple getters

template <typename Type>
Type Deque<Type>::front( ) const
{
    if (head != nullptr) {
        return( head->getElement() );
    } else {
        Type t;
        return t;
    }
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    if (tail != nullptr) {
        return( tail->getElement() );
    } else {
        Type t;
        return t;
    }
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    if (isEmpty()) {
        return;
    }
    if (tail->getPrevious() == nullptr) { // if its a length one deque
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else { // pop
        DequeNode<Type>* toDelete = tail;
        tail = tail->getPrevious();
        delete toDelete;
        tail->setNext(nullptr);
    }
}

// convert Type value to string
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    s << value;
    return( s.str() );
}

// convert this object to a string
template <typename Type>
std::string Deque<Type>::printItems( ) const
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        DequeNode<Type> * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += to_string(node->getElement());
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    
    if (this != &rhs) {
        makeEmpty();
        for (int i = 0; i < rhs.size(); i++) {
            Type data;
            rhs.get(i, data);
            addToRear(data);
        }
    }
    
	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    DequeNode<Type>* node = head;
    
    while (node != nullptr) { // iterate and count nodes
        node = node->getNext();
        result++;
    }

    return( result );
}


template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    DequeNode<Type>* node = head;
    int k = 0;
    
    for (; node != nullptr; k++, node = node->getNext()) { // iterate the deque and keep count
        if (k == i) { // if the count is in the deque
            data = node->getElement();
            return true;
        }
    }

    return( false );
}

}


#endif
