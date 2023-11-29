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
    if (rhs.head == nullptr)
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
        while (p != nullptr) {
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
	makeEmpty();
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    return( head == nullptr );
}

template <typename Type>
void Deque<Type>::makeEmpty() {
    DequeNode<Type>* node = head;
    while (node != nullptr) {
        DequeNode<Type>* toDelete = node;
        node = node->getNext();
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    if (head == nullptr) {
        head = new DequeNode<Type>(data);
        tail = head;
    } else {
        head->setPrevious(new DequeNode<Type>(data, head));
        head = head->getPrevious();
    }
}

template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    if (tail == nullptr) {
        tail = new DequeNode<Type>(data);
        head = tail;
    } else {
        tail->setNext(new DequeNode<Type>(data, nullptr, tail));
        tail = tail->getNext();
    }
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    if (head == nullptr) {
        return;
    }
    if (head->getNext() == nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->getNext();
        delete head->getPrevious();
        head->setPrevious(nullptr);
    }
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    DequeNode<Type>* node = head;
    
    while (node != nullptr) {
        if (node->getElement() == data) {
            if (node->getNext() != nullptr) {
                node->getNext()->setPrevious(node->getPrevious());
            } else {
                tail = tail->getPrevious();
                tail->setNext(nullptr);
            }
            if (node->getPrevious() != nullptr) {
                node->getPrevious()->setNext(node->getNext());
            } else {
                head = head->getNext();
                head->setPrevious(nullptr);
            }
            delete node;
            return true;
        }
        node = node->getNext();
    }

    return( false );
}


template <typename Type>
Type Deque<Type>::front( ) const
{
    return( head->getElement() );
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    return( tail->getElement() );
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    if (tail == nullptr) {
        return;
    }
    if (tail->getPrevious() == nullptr) {
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->getPrevious();
        delete tail->getNext();
        tail->setNext(nullptr);
    }
}

template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    s << value;
    return( s.str() );
}


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
        DequeNode<Type>* node = rhs.front();
        while (node != nullptr) {
            addToRear(node->getElement());
            node = node->getNext();
        }
    }
    
	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    DequeNode<Type>* node = head;
    
    while (node != nullptr) {
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
    
    for (; node != nullptr; k++, node = node->getNext()) {
        if (k == i) {
            data = node->getElement();
            return true;
        }
    }

    return( false );
}

}


#endif
