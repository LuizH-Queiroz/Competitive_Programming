/*
Está chovendo tanto na Obilândia que começaram a aparecer goteiras dentro da casa do prefeito.
Uma dessas goteiras está fazendo escorrer água verticalmente, a partir de um ponto no teto, numa parede onde há várias prateleiras horizontais.
Quando a água bate em uma prateleira, ela começa a escorrer horizontalmente para os dois lados, direita e esquerda, até as extremidades
da prateleira, quando volta a escorrer verticalmente. Vamos representar a parede por uma matriz de N linhas e M colunas de caracteres,
como mostrado ao lado. As prateleiras serão representadas por “#” e a parede por “.”.
Só existem prateleiras nas linhas pares e elas nunca encostam na borda da parede. Há apenas um ponto de vazamento representado pelo
caractere “o” na primeira linha.

Para deixar mais rigorosa a forma como a água vai escorrer, seja c(i, j) o caractere na linha i coluna j. Se c(i, j)= “.”, então ele deve
virar “o” sempre que:

• c(i − 1, j)= “o”; ou

• c(i, j − 1)= “o” e c(i + 1, j − 1)= “#”; ou

• c(i, j + 1)= “o” e c(i + 1, j + 1)= “#”. 

Neste problema, dada a matriz representando a parede no início do vazamento, seu programa deve imprimir na saída uma matriz representando
a parede usando o caractere “o” exatamente nas posições que serão molhadas pelo vazamento, como ilustrado acima.
Entrada

A primeira linha da entrada contém dois inteiros N (3 ≤ N ≤ 500) e M(3 ≤ M ≤ 500), respectivamente o número de linhas e colunas da matriz.
As N linhas seguintes da entrada contêm, cada uma, uma sequência de M caracteres entre três possíveis: “.”, “#” ou “o”.

• O número de linhas N é ímpar;

• Há exatamente um caractere “o” na primeira linha;

• As linhas ímpares, a primeira coluna e a última coluna não possuem o caractere “#”.
Saída

Seu programa deve imprimir N linhas, cada uma contendo uma sequência de M caracteres, representando a matriz da entrada usando o
caractere “o” exatamente nas posições que serão molhadas pelo vazamento.
*/
#include <iostream>
#include <vector>

using namespace std;


vector<vector<char>> matriz;


void escorrer(int i, int j) {
    if (matriz[i][j] == 'o')
        return;
    
    matriz[i][j] = 'o';
    if ((i+1) < matriz.size())
    {
        if (matriz[i+1][j] == '#')
        {
            escorrer(i, j-1);
            escorrer(i, j+1);
        }
        else
        {
            escorrer(i+1, j);
        }
    }
}



int main() {
    int linhas, colunas;
    int i_inicial, j_inicial;


    cin >> linhas >> colunas;
    matriz = vector<vector<char>>(linhas, vector<char>(colunas));

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cin >> matriz[i][j];
            if (matriz[i][j] == 'o')
            {
                i_inicial = i;
                j_inicial = j;
                matriz[i][j] = '.';
            }
        }
    }


    escorrer(i_inicial, j_inicial);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cout << matriz[i][j];
        }
        cout << endl;
    }



    return 0;
}