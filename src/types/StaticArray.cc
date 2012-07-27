#include "StaticArray.h"

StaticArray::~StaticArray()
{
    delete [] array_;
    array_ = NULL:
}
