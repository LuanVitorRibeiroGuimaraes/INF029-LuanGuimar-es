#include <stdio.h>
#include <stdlib.h>

void invertNumber(int n)
{
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    n1 = n / 1000; //ok
    n2 = (n % 1000) / 100; //ok
    n3 = (n % 100) / 10; //ok
    n4 = n % 10; //ok

    if (n < 10)
    {
        return printf("\n%d", n4);
    }

    if (n < 100)
    {
        return printf("\n%d%d", n4, n3);
    }

    if (n < 1000)
    {
        return printf("\n%d%d%d", n4, n3, n2);
    }

    return printf("\n%d%d%d%d", n4, n3, n2, n1);
}

int main()
{
    invertNumber(543);
    invertNumber(78);
    invertNumber(3);
    invertNumber(345);
}