#include "DealingWithBuffer.h"

#include <iostream>
#include <limits>

using namespace std;

void FlushInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}