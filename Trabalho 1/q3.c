#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findLetter(char text[], char word[], int isCaseSensitive)
{
    char formatedText[250];

    int sizeText = strlen(text), sizeFormated, qnt;
    
    for (int i = 0; i < sizeText; i++)
    {
        if(text[i] == -61)
        {
            formatedText[i] == " ";
        }
        else
        {
            formatedText[i] = text[i];
        }
    }

    sizeFormated = strlen(formatedText);

    //minúsculo = range(97, 122)
    //maiúsculo = range(65, 90)
    // +32, -32
    // 1 = diferenciar caracteres, 0 = não diferenciar caracteres

    if (isCaseSensitive == 0)
    {
        qnt = 0;

        for (int i = 0; i < sizeFormated; i++)
        {
            if (word[0] == formatedText[i])
            {
                qnt++;
            }
            else continue;
        }

        for (int i = 0; i < sizeFormated; i++)
        {
            if (formatedText[i] >= 97 && formatedText[i] <= 122)
            {
                formatedText[i] = formatedText[i] - 32;
                if (word[0] == formatedText[i]) qnt++;
            }
            else if (formatedText[i] >= 65 && formatedText[i] <= 90)
            {
                formatedText[i] = formatedText[i] + 32;
                if (word[0] == formatedText[i]) qnt++;
            }
        } 
    }

    if (isCaseSensitive == 1) //compara somente com a original
    {
        qnt = 0;

        for (int i = 0; i < sizeFormated; i++)
        {
            if (word[0] == formatedText[i])
            {
                qnt++;
            }
        }
    }

    printf("\nletter: %c, times: %d", word[0], qnt);
}

int main()
{
    findLetter("Renato Lima Novais", "a", 0);
    findLetter("Renato Lima Novais", "b", 0);
    findLetter("Renato Lima Novais", "l", 1);
    findLetter("Renato Lima Novais", "l", 0);
    findLetter("Renato Lima Novais", "L", 0);
}