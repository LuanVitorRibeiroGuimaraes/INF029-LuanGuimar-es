#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findText()
{
    char strTexto[250];
    char strBusca[50];
    // int posicpoes[30];

    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");

    char strFormated[250];

    int sizeTexto = strlen(strTexto), sizeBusca = strlen(strBusca), sizeFormated;
    int j, find, words = 0;

    for (int i = 0; i < sizeTexto; i++)
    {
        if(strTexto[i] == -61)
        {
            strFormated[i] == " ";
        }
        else
        {
            strFormated[i] = strTexto[i];
        }
    }

    printf("\n String: %s", strFormated);

    sizeFormated = strlen(strFormated);

    for (int i = 0; i < sizeFormated; i++)
    {
        j = 1; //pega sempre a primeira posição (reinicia sempre para garantir isso)
        find = 0; //considera que ainda n encontrou nada

        if (strBusca[0] == strTexto[i]) //compara as 2 primeiras palabras de ambos
        {
            for (int x = i+1; x < sizeFormated; x++) //inicia da posição seguinte a primeira letra que foi encontrada e percorre todo o resto da string
            {
                if (strBusca[j] == strTexto[x]) //se as letras forem batendo, basta incrementar para ver a letra seguinte
                {
                    j++;
                }
                else break;
            }
        }

        if (j == sizeBusca) find = 1; //se o incrementador j for do mesmo size do tamanho 

        if (find) words++; // se encontrar, incrementa a quantidade de palavras
    }

    printf("\nVezes encontrada no texto: %d", words);
}

int main()
{
    findText();
}