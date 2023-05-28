/*
Implemente um programa denominado combinador, que recebe duas strings e deve combiná-las, alternando as letras de cada string,
começando com a primeira letra da primeira string, seguido pela primeira letra da segunda string, em seguida pela segunda letra da primeira string,
e assim sucessivamente. As letras restantes da cadeia mais longa devem ser adicionadas ao fim da string resultante e retornada.


Entrada

A entrada contém vários casos de teste. A primeira linha contém um inteiro N que indica a quantidade de casos de teste que vem a seguir. Cada caso de teste é composto por uma linha que contém duas cadeias de caracteres, cada cadeia de caracteres contém entre 1 e 50 caracteres inclusive.

Saída

Combine as duas cadeias de caracteres da entrada como mostrado no exemplo abaixo e exiba a cadeia resultante.

*/
#include <stdio.h>
#include <string.h>

#define TAM_STRING 51 // '\0' incluso


int main() {
    int testes;
    char str1[TAM_STRING], str2[TAM_STRING];
    int indice;
    int len1, len2;


    scanf("%d", &testes);
    for (int i = 0; i < testes; i++)
    {
        scanf("%s %s", str1, str2);
        indice = 0;
        len1 = strlen(str1);
        len2 = strlen(str2);

        while(indice < len1 && indice < len2)
        {
            printf("%c%c", str1[indice], str2[indice]);
            indice++;
        }

        while(indice < len1)
        {
            printf("%c", str1[indice]);
            indice++;
        }

        while(indice < len2)
        {
            printf("%c", str2[indice]);
            indice++;
        }

        printf("\n");
    }


    return 0;
}