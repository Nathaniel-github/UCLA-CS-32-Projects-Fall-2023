#include "Garage.h"

namespace cs32
{


Garage::Garage( size_t capacity ): mCapacity(capacity)
{
}

// put something in the garage
// silently, it purges something once the garage is full
bool Garage::tossIn( std::string s )
{
    if (mDeque.size() >= mCapacity && mCapacity > 0) { // if the capacity is met
        mDeque.deleteRear();
        mDeque.addToFront(s);
        return true;
    } else if (mCapacity <= 0) { // if the capacity is some weird number
        return false;
    } else { // if the capacity is not met
        mDeque.addToFront(s);
    }

    return( false );
}

bool Garage::tossOut( std::string s )
{
    return mDeque.deleteItem(s);
}


// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s )
{
    if (mDeque.deleteItem(s)) { // if the item exists then delete it
        mDeque.addToFront(s); // add it back to the front
        return true;
    }
    return( false );
}

// is it in the garage?
bool Garage::find( std::string s )
{
    Deque<std::string> temp(mDeque);
    return( temp.deleteItem(s) ); // if it is able to delete that means its there
}

// how much can this garage maximally hold?
size_t Garage::capacity()
{
    return( mCapacity );
}
// how much is in this garage right now?
size_t Garage::size( )
{
    return( mDeque.size() );
}

std::string Garage::printItems( )
{
    return( mDeque.printItems() ); // just call the one from deque
}


}
