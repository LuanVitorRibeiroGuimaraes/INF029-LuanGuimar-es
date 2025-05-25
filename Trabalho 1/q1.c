#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int leapYear(int year)
{
    if (year % 400 == 0) return 1;
    if (year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}

//01/06/2004
//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
// i = 0, i = 3, i = 6

int validateData(char date[11])
{

    char sDia[3];
    char sMes[3];
    char sAno[5];

    int i = 0; //percorre a data da parada
    int j = 0;// = preenche na posicao do outro vetor q guarda a parada

    for (j = 0; date[i] != '/' && date[i] != '\0'; i++, j++)
    {
        sDia[j] = date[i];
    }
    sDia[j] = '\0'; //jogando \0 na ultima posicao

    i++;

    for (j = 0; date[i] != '/' && date[i] != '\0'; i++, j++)
    {
        sMes[j] = date[i];
    }
    sMes[j] = '\0';

    i++;
    for (j = 0; date[i] != '/' && date[i] != '\0'; i++, j++)
    {
        sAno[j] = date[i];
    }
    sAno[j] = '\0';

    int dia = atoi(sDia);
    int mes = atoi(sMes);
    int ano = atoi(sAno);

    if (sAno < 100) ano += 2000;

    if (dia > 0 && dia <= 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) return 1;

    if (dia > 0 && dia <= 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) return 1;

    if (leapYear(ano) == 1)
    {
        if (dia > 0 && dia <= 29 && (mes == 2)) return 1;
    }
        
    if (leapYear(ano) == 0)
    {
        if (dia > 0 && dia <= 28 && (mes == 2)) return 1;
    }
        
    return 0;
}

    int main()
    {
        char date[] = {"30/02/2025"};

        (validateData(date) == 1) ? printf("\nData valida\n") : printf("\nData invalida\n");

        return 0;
    }
