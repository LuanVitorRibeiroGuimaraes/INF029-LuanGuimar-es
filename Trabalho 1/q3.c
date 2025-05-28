#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//texto[] = *texto

int q3(char *texto, char c, int isCaseSensitive)
{
    char formatedtexto[250];

    int sizetexto = strlen(texto), sizeFormated, qtdOcorrencias;

    qtdOcorrencias = -1;
    
    for (int i = 0; i < sizetexto; i++)
    {
        if(texto[i] == -61)
        {
            formatedtexto[i] == " ";
        }
        else
        {
            formatedtexto[i] = texto[i];
        }
    }

    sizeFormated = strlen(formatedtexto);

    //minúsculo = range(97, 122)
    //maiúsculo = range(65, 90)
    // +32, -32
    // 1 = diferenciar caracteres, 0 = não diferenciar caracteres

    if (isCaseSensitive == 0)
    {
        qtdOcorrencias = 0;

        for (int i = 0; i < sizeFormated; i++)
        {
            if (c == formatedtexto[i])
            {
                qtdOcorrencias++;
            }
            else continue;
        }

        for (int i = 0; i < sizeFormated; i++)
        {
            if (formatedtexto[i] >= 97 && formatedtexto[i] <= 122)
            {
                formatedtexto[i] = formatedtexto[i] - 32;
                if (c == formatedtexto[i]) qtdOcorrencias++;
            }
            else if (formatedtexto[i] >= 65 && formatedtexto[i] <= 90)
            {
                formatedtexto[i] = formatedtexto[i] + 32;
                if (c == formatedtexto[i]) qtdOcorrencias++;
            }
        } 
    }

    if (isCaseSensitive == 1) //compara somente com a original
    {
        qtdOcorrencias = 0;

        for (int i = 0; i < sizeFormated; i++)
        {
            if (c == formatedtexto[i])
            {
                qtdOcorrencias++;
            }
        }
    }


    printf("\nletter: %c, times: %d", c, qtdOcorrencias);

    return qtdOcorrencias;
}

int main()
{
    char str[250];
    strcpy(str, "Renato Lima Novais");
    q3(str, 'a', 0);
    q3(str, 'b', 0);
    q3(str, 'l', 1);
    q3(str, 'l', 0);
    q3(str, 'L', 0);
}
