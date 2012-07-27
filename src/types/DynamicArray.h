/*---------------------------------------
 * DynamicArray.h
 *
 *  Created on: 27 Jul 2012
 *      Author: Eliot J. Walker
 *---------------------------------------*/
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
/*--------------------------------------*/
#include <stdexcept>
/*--------------------------------------*/

template <class Item_>
class DynamicArray
{
private:
    int capacity_;
    int size_;
    Item_* array_;
    static const int resize_multiplier_ = 2;

    void resizeArray()
    {
        // a temporary array in which to store the current values in array_
        Item_* tmp_array = new Item_[capacity_];

        // copy the contents of array_ into tmp_array
        std::copy(array_, array_ + capacity_, tmp_array);

        // reset array_
        delete [] array;

        // the capacity of array_ has now been multiplied by resize_multiplier_
        array_ = new Item_[capacity_*resize_multiplier_];

        // copy the contents of tmp_array back into the beginning of array_
        std::copy(tmp_array, tmp_array+capacity_, array_);

        // capacity is now resize_muliplier_ times greater
        capacity *= resize_multiplier_;

        // free memory
        delete[] tmp_array;
        tmp_array = NULL;
    }

public:
    DynamicArray(int capacity = 10)
    {
        size_ = -1;
        capacity_ = capacity;
        array_ = new Item_[capacity_];
    }

    ~DynamicArray()
    {
        delete [] array_;
        array_ = NULL;
    }

    Item_& operator[] (const int index)
    {
        if(index <= capacity_)
        {
            return array_[index];
        }
        else
        {
            throw std::out_of_range("Out of range exception.");
        }
    }

    void push(Item_ value)
    {
        ++size_;
        if(size_ < capacity_)
        {
            resizeArray();
        }
        array_[size_] = value;
    }

    int size()
    {
        return size_;
    }
}

/*--------------------------------------*/
#endif /*DYNAMICARRAY_H*/

