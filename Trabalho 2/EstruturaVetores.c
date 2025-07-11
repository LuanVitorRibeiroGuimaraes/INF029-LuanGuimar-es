#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct EstruturaVetores
{
    int * vetor;
    int tamanho;
    int qtdElementos;
}EstruturaVetores;

EstruturaVetores vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/

//verificar validações
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao].vetor != NULL) {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    // se posição é um valor válido {entre 1 e 10}
    if (posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }
    
    // o tamanho ser muito grande
    if (tamanho > 10) {
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }

    // o tamanho nao pode ser menor que 1
    if (tamanho < 1) {
        retorno = TAMANHO_INVALIDO;
        return retorno;   
    }
    // deu tudo certo, crie
    vetorPrincipal[posicao].vetor = malloc(tamanho * sizeof(int));
    vetorPrincipal[posicao].tamanho = tamanho; //define o tamanho
    vetorPrincipal[posicao].qtdElementos = 0; //começa com 0 elementos
    retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno;

    if(posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao].vetor == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    else {
        if(vetorPrincipal[posicao].qtdElementos < vetorPrincipal[posicao].tamanho) {
            vetorPrincipal[posicao].vetor[vetorPrincipal[posicao].qtdElementos] = valor;
            vetorPrincipal[posicao].qtdElementos += 1;
            retorno = SUCESSO;
        }
        else {
            retorno = SEM_ESPACO;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    //validar a posição
    //validar se tem vetor na posição

    if (posicao < 1 || posicao > 10) {
        int retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if (vetorPrincipal[posicao].vetor == NULL) {
        int retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    
    if (vetorPrincipal[posicao].qtdElementos == 0) {
        int retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }
        
    vetorPrincipal[posicao].vetor[vetorPrincipal[posicao].qtdElementos-1] = NULL;
    vetorPrincipal[posicao].qtdElementos -= 1;

    int retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno;

    if(posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao].vetor == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    if(vetorPrincipal[posicao].qtdElementos == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    for(int i = 0; i < vetorPrincipal[posicao].qtdElementos; i++) {
        if(vetorPrincipal[posicao].vetor[i] == valor) {
            for(int j = i; j < vetorPrincipal[posicao].qtdElementos - 1; j++) {
                vetorPrincipal[posicao].vetor[j] = vetorPrincipal[posicao].vetor[j + 1];
            }
            vetorPrincipal[posicao].vetor[vetorPrincipal[posicao].qtdElementos - 1] = NULL;
            vetorPrincipal[posicao].qtdElementos -= 1;
            retorno = SUCESSO;
            return retorno;
        }
        else {
            retorno = NUMERO_INEXISTENTE;
            return retorno;
        }
    }

    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = 1;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }

    if(vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int qtd = vetorPrincipal[posicao].qtdElementos;

    for(int i = 0; i < qtd; i++)
        vetorAux[i] = vetorPrincipal[posicao].vetor[i];

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if(vetorPrincipal[posicao].vetor == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int qtd = vetorPrincipal[posicao].qtdElementos;

    for(int i = 0; i < qtd; i++)
        vetorAux[i] = vetorPrincipal[posicao].vetor[i];

    for(int i = 0; i < qtd - 1; i++) {
        for(int j = 0; j < qtd - i - 1; j++) {
            if(vetorAux[j] > vetorAux[j+1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            }
        }
    }

    return SUCESSO; // Deve retornar a quantidade de elementos copiados/ordenados
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int totalElementos = 0;
    int a = 0; 

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0) {
            for (int j = 0; j < vetorPrincipal[i].qtdElementos; j++) {
                vetorAux[a] = vetorPrincipal[i].vetor[j];
                a++;
                totalElementos++;
            }
        }
    }

    if (totalElementos == 0)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
int retorno;
int qtdElementos = 0;
int a = 0;

// Primeiro passada: contar o total de elementos em todas as estruturas
for (int i = 0; i < TAM; i++) {
    if (vetorPrincipal[i].vetor != NULL) {
        qtdElementos += vetorPrincipal[i].qtdElementos;
    }
}

// Verificar se todas as estruturas estão vazias
if (qtdElementos == 0) {
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

// Segunda passada: copiar todos os elementos para o vetorAux
for (int i = 0; i < TAM; i++) {
    if (vetorPrincipal[i].vetor != NULL && vetorPrincipal[i].qtdElementos > 0) {
        for (int j = 0; j < vetorPrincipal[i].qtdElementos; j++) {
            vetorAux[a++] = vetorPrincipal[i].vetor[j];
        }
    }
}

// Ordenação usando bubble sort
for (int i = 0; i < qtdElementos - 1; i++) {
    for (int j = 0; j < qtdElementos - i - 1; j++) {
        if (vetorAux[j] > vetorAux[j + 1]) {
            int temp = vetorAux[j];
            vetorAux[j] = vetorAux[j + 1];
            vetorAux[j + 1] = temp;
        }
    }
}

return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if(posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }

    if(vetorPrincipal[posicao].vetor == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    int novoTamanhoTotal = vetorPrincipal[posicao].tamanho + novoTamanho;
    
    if(novoTamanhoTotal < 1) {
        return NOVO_TAMANHO_INVALIDO;
    }

    int *novoVetor = realloc(vetorPrincipal[posicao].vetor, novoTamanhoTotal * sizeof(int));
    if(novoVetor == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao].vetor = novoVetor;
    
    if(vetorPrincipal[posicao].qtdElementos > novoTamanhoTotal) {
        vetorPrincipal[posicao].qtdElementos = novoTamanhoTotal;
    }
    
    vetorPrincipal[posicao].tamanho = novoTamanhoTotal;

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
     int retorno;

    if(posicao < 1 || posicao > 10) {
        retorno = POSICAO_INVALIDA;
        return retorno;
    }

    if(vetorPrincipal[posicao].vetor == NULL) {
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }

    if(vetorPrincipal[posicao].qtdElementos == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
        return retorno;
    }

    retorno = vetorPrincipal[posicao].qtdElementos;
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    // Aloca o nó cabeça
    No* cabeca = (No*)calloc(1, sizeof(No));
    if(!cabeca) return NULL;

    No* cauda = cabeca;
    int contador = 0;

    for(int indice = 0; indice < TAM; indice++)
    {
        // Verifica se a estrutura atual é válida
        if(vetorPrincipal[indice].vetor && vetorPrincipal[indice].qtdElementos > 0)
        {
            for(int elem = 0; elem < vetorPrincipal[indice].qtdElementos; elem++)
            {
                No* novo = (No*)malloc(sizeof(No));
                if(!novo)
                {
                    No* atual = cabeca->prox;
                    while(atual)
                    {
                        No* proximo = atual->prox;
                        free(atual);
                        atual = proximo;
                    }
                    free(cabeca);
                    return NULL;
                }

                novo->conteudo = vetorPrincipal[indice].vetor[elem];
                novo->prox = NULL;

                cauda->prox = novo;
                cauda = novo;
                contador++;
            }
        }
    }

    // Se não adicionou nenhum elemento, limpa o cabeçote
    if(contador == 0)
    {
        free(cabeca);
        return NULL;
    }

    return cabeca;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) //ok
{
    if (!inicio) return;

    No *atual = inicio->prox; // Pula o cabeçote
    int i = 0;
    const int MAX_ELEMENTOS = 10; // Tamanho máximo do vetor

    while (atual != NULL && i < MAX_ELEMENTOS) {
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    if(!inicio || !*inicio) return;

    No *atual = *inicio;
    No *prox;

    while(atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        vetorPrincipal[i].tamanho = 0;
        vetorPrincipal[i].qtdElementos = 0;
        vetorPrincipal[i].vetor = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/
void finalizar()
{   
    for(int i = 0; i < TAM; i++) 
    {
        if(vetorPrincipal[i].vetor) 
        {
            free(vetorPrincipal[i].vetor);
            vetorPrincipal[i].vetor = NULL;
            vetorPrincipal[i].qtdElementos = 0;
            vetorPrincipal[i].tamanho = 0;
        }
    }
}