export module tasks;

import std;
import geometry;

export int Factorial(int n)
{
    if (n < 0)
    {
        throw std::logic_error("Negative number");
    }

    int temp = n;

    if (temp == 1 || temp == 0)
    {
        return 1;
    }

    return temp * Factorial(temp - 1);
}