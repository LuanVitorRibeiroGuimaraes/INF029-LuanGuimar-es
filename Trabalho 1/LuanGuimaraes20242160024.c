// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LuanGuimaraes20242160024.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char data[])
{
   int datavalida = 0;
   int anoBissexto = 0;

  //quebrar a string data em strings sDia, sMes, sAno

   char sDia[3];
   char sMes[3];
   char sAno[5];

   int i = 0;
   int j = 0;

   for (j = 0; data[i] != '/' && data[i] != '\0'; i++, j++)
   {
      sDia[j] = data[i];
   }
   sDia[j] = '\0';

   i++;

   for (j = 0; data[i] != '/' && data[i] != '\0'; i++, j++)
   {
      sMes[j] = data[i];
   }
   sMes[j] = '\0';

   i++;
   for (j = 0; data[i] != '/' && data[i] != '\0'; i++, j++)
   {
      sAno[j] = data[i];
   }
   sAno[j] = '\0';

   int dia = atoi(sDia);
   int mes = atoi(sMes);
   int ano = atoi(sAno); 

   if (dia == 0 || dia > 31) datavalida = 0;
   if (mes == 0) datavalida = 0;
   if (ano == 0) datavalida = 0;

   if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
   {
      anoBissexto = 1;
      if (anoBissexto && (dia > 0 && dia <= 29 && (mes == 2))) datavalida = 1;
   }
   else if (!anoBissexto)
   {
      if (!anoBissexto && (dia > 0 && dia <= 28 && (mes == 2))) datavalida = 1;
   }
   else
   {
      datavalida = 0;
   }

   if (sAno < 100) ano += 2000;

   if (dia > 0 && dia <= 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) datavalida = 1;

   if (dia > 0 && dia <= 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) datavalida = 1;

  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]) {
   DiasMesesAnos dma;

   if (!q1(datainicial)) {
      dma.retorno = 2;
      return dma;
   }

   if (!q1(datafinal)) {
      dma.retorno = 3;
      return dma;
   }

   int d1, m1, a1, d2, m2, a2;
   sscanf(datainicial, "%d/%d/%d", &d1, &m1, &a1);
   sscanf(datafinal, "%d/%d/%d", &d2, &m2, &a2);

   if (a2 < a1 || (a2 == a1 && m2 < m1) || (a2 == a1 && m2 == m1 && d2 < d1)) {
      dma.retorno = 4;
      return dma;
   }

   int dia = d2 - d1;
   int mes = m2 - m1;
   int ano = a2 - a1;

   if (dia < 0) {
      dia += 30;
      mes--;
   }

   if (mes < 0) {
      mes += 12;
      ano--;
   }

   dma.qtdDias = dia;
   dma.qtdMeses = mes;
   dma.qtdAnos = ano;
   dma.retorno = 1;

   return dma;
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
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

   return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
   char strFormated[250];
   int sizeTexto = strlen(strTexto), sizeBusca = strlen(strBusca), sizeFormated;
   int s, k, j, find, qtdOcorrencias, firstPosition;

   qtdOcorrencias = 0;

   s = 0;
   for (int i = 0; i < sizeTexto; i++)
   {
      if(strTexto[i] != -61) //tirando o espaço vazio
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
                     posicoes[k] = firstPosition+1;
                     k++;
                     posicoes[k] = x+1;
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

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

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

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
   int qtdOcorrencias = 0;

   int calc = numerobase; 
   int calcBusca = numerobusca, calcBase = numerobase;
   int sizeBusca = 1, sizeBase = 1;
   int baseDecimal = 1;
   int number = 1;

   do
   {
      calcBusca /= 10;
      if (calcBusca > 0) sizeBusca++;
   } while (calcBusca != 0);

   do
   {
      calcBase /= 10;
      if (sizeBase > 0) sizeBase++;
   } while (calcBase != 0);

   for (int i = 0; i < sizeBusca; i++)
   {
      baseDecimal *= 10;
   }

   for (int i = 0; calc != 0; i++)
   {
      number = (calc % baseDecimal);
      calc /= 10;
      if (number == numerobusca) qtdOcorrencias++;
   }

   return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
   int linhas = 8;
   int colunas = 10;
   int len = strlen(palavra);

   int dx[8] = {  0,  0,  1, -1,  1, -1,  1, -1 };
   int dy[8] = {  1, -1,  0,  0,  1, -1, -1,  1 };

   for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
         for (int dir = 0; dir < 8; dir++) {
               int k, x = i, y = j;

               for (k = 0; k < len; k++) {
                  if (x < 0 || x >= linhas || y < 0 || y >= colunas)
                     break;
                  if (matriz[x][y] != palavra[k])
                     break;
                  
                  x += dx[dir];
                  y += dy[dir];
               }

               if (k == len)
                  return 1;
         }
      }
   }

   return 0; // Palavra não encontrada
 }
