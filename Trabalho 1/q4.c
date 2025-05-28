#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
   // strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
   // strcpy(strBusca, "rato");

    char strFormated[250];
    int sizeTexto = strlen(strTexto), sizeBusca = strlen(strBusca), sizeFormated;
    int s, k, j, find, qtdOcorrencias, firstPosition;

    qtdOcorrencias = 0;

    s = 0;
    for (int i = 0; i < sizeTexto; i++)
    {
        if(strTexto[i] == 0xc3) 
        {
            i++;
        }
        else
        {
            strFormated[s] = strTexto[i];
            s++; 
        }
    }
    strFormated[s] = '\0';

    sizeFormated = strlen(strFormated);

    k = 0;

    for (int i = 0; i < sizeFormated; i++)
    {
        j = 1;
        find = 0;

        if (strBusca[0] == strFormated[i])
        {
            firstPosition = i;
            
            for (int x = i+1; x < sizeFormated; x++)
            {
                if (strBusca[j] == strFormated[x])
                {
                    j++;
                    if (j == sizeBusca)
                    {
                        posicoes[k] = firstPosition;
                        k++;
                        posicoes[k] = x;
                        k++;
                    }
                }
                else break;
            }
        }

        if (j == sizeBusca) find = 1;
        if (find) qtdOcorrencias++;
    }

    return qtdOcorrencias;
}

int main()
{
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }

    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);
}