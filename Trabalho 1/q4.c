#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char phrase[250], char *word;


//percorrer toda a string - OK
//encontrar a primeira letra de "text" em strFormated - OK
//se encontrar percorrer pela string o tamanho "text" - OK
//começar a buscar a partir da segunda posição do array -> utilizar uma variável que reinicia caso a segunda letra n dê match
//se não encontar a letra seguinte, parar o loop e voltar a variável para iniciar de 1 (segunda posição do array)

int findString()
{
    char phrase[250];
    char text[30];
    
    strcpy(phrase, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(text, "mui");
    
    char strFormated[250];

    int words = 0;
    int x, i, j, sizeWord, sizePhrase, find;

    for (int i = 0; i < strlen(phrase); i++)
    {
        if (phrase[i] == -61)
        {
            strFormated[i] = ""; 
        }
        else
        {
            strFormated[i] = phrase[i];
        }
    }

    sizePhrase = strlen(strFormated);
    sizeWord = strlen(text);

    printf("\noriginal: %s", strFormated);

    for (i = 0; i < sizePhrase; i++)
    {
        j = 1;
        find = 0;

        if (text[0] == strFormated[i])
        {
            for (x = i+1; x < sizePhrase; x++)
            {
                if (text[j] == strFormated[x])
                {
                    j++;
                } 
                else
                {
                    break;
                }
            }
            if (j == sizeWord) find = 1;

            if (find) words++;
        }
    }
    printf("\npalavras encontradas: %d", words);
    return 1;
}

int main()
{
    findString();

    return 0;
}