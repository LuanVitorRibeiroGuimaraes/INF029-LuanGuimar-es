#include <stdio.h>
#include <stdlib.h>

int q5(int num)
{
    int calcSize, numberSize, multp, invertedNumber, divBase;

    numberSize = 1;
    multp = 1;
    calcSize = num;

    if (num < 0) num *= -1;

    do
    {
        calcSize /= 10;
        if (calcSize > 0) numberSize++;
    }
    while (calcSize != 0);

    for (int i = 1; i < numberSize; i++)
    {
        multp *= 10;
    }

    divBase = 1;
    invertedNumber = 0;

    for (int i = 0; i < numberSize; i++)
    {
        invertedNumber += (((num / divBase) % 10) * multp);
        divBase *= 10;
        multp = multp / 10;
    }

    num = invertedNumber;

    return num;
}
