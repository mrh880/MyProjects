#include "MathOperations.h"

namespace MathOperations
{

    int CountDigitsOfNumber(int Number)
    {
        int Counter = 0;
        while(Number > 0)
        {
            Number /= 10;
            Counter++;
        }
        return Counter;
    }
}