/*---------------------------------------
 * StaticArray.h
 *
 *  Created on: 27 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef STATICARRAY_H
#define STATICARRAY_H
/*--------------------------------------*/

template <class Item_>
class StaticArray
{
private:
    int size_;
    Item_* array;
public:
    StaticArray(int size=10) : size_(size), array_(new Item_[size])
    { }

    ~StaticArray()
    {
        delete [] array_;
        array_ = NULL;
    }

    Item& operator[](const int index)
    {
        return array_[index];
    }

    int size()
    {
        return size_;
    }
}

/*--------------------------------------*/
#endif /*STATICARRAY_H*/
