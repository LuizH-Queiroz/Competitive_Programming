/*
Um novo robô de limpeza para um grande salão retangular está sendo desenvolvido.
O robô vai percorrer o caminho definido por uma linha marcada no chão, que é coberto com ladrilhos quadrados,
brancos e pretos: ladrilhos pretos indicam o caminho que o robô deve percorrer. Ao movimentar-se, o robô pode
andar apenas em linha reta, para a frente. Parado, o robô pode girar para as quatro direções (Norte, Sul,
Leste e Oeste).

Dados um mapa indicando a cor de cada ladrilho no chão e a posição inicial do robô, você deve escrever um 
 que determine a posição final do robô.

Entrada
A primeira linha contém dois inteiros L e C (1 ≤ L, C ≤ 1000) indicando as dimensões do salão
(número de linhas e número de colunas), medidas em ladrilhos. A segunda linha contém dois inteiros
A e B (1 ≤ B ≤ L, 1 ≤ B ≤ C) indicando respectivamente a linha e a coluna da posição inicial do robô
(as linhas são numeradas de 1 a L, de cima para baixo; as colunas são numeradas de 1 a C, da esquerda
para a direita). Cada uma das L linhas seguintes contém C inteiros, zeros ou uns. Nessa representação,
o valor ‘1’ indica que o ladrilho corresponte é preto. O ladrilho da linha A e coluna B sempre é preto.
O caminho do robô é definido unicamente: em nenhum momento o robô necessita fazer uma escolha sobre em qual
direção ir (em outras palavras, todo ladrilho preto tem no máximo dois vizinhos pretos e o ladrilho inicial
tem um vizinho preto).

Saída
Seu programa deve imprimir apenas uma linha, contendo dois números inteiros, respectivamente a linha e a coluna
da posição final do robô.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


typedef struct {
    int linha;
    int coluna;
} Ponto;


bool posicaoValida(int i, int j, int linhas, int colunas) {
    return (i >= 1 && i <= linhas) && (j >= 1 && j <= colunas);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int linhas, colunas;
    Ponto p;
    vector<vector<int>> matriz;


    cin >> linhas >> colunas;
    cin >> p.linha >> p.coluna;

    matriz = vector<vector<int>>(linhas+1, vector<int>(colunas+1));

    for (int i = 1; i <= linhas; i++)
        for (int j = 1; j <= colunas; j++)
            cin >> matriz[i][j];


    bool moveu;
    do {
        moveu = false;
        matriz[p.linha][p.coluna] = 0;

        if (posicaoValida(p.linha-1, p.coluna, linhas, colunas) && matriz[p.linha-1][p.coluna] == 1)
        {
            p.linha--;
            moveu = true;
        }
        else if (posicaoValida(p.linha+1, p.coluna, linhas, colunas) && matriz[p.linha+1][p.coluna] == 1)
        {
            p.linha++;
            moveu = true;
        }
        else if (posicaoValida(p.linha, p.coluna-1, linhas, colunas) && matriz[p.linha][p.coluna-1] == 1)
        {
            p.coluna--;
            moveu = true;
        }
        else if (posicaoValida(p.linha, p.coluna+1, linhas, colunas) && matriz[p.linha][p.coluna+1] == 1)
        {
            p.coluna++;
            moveu = true;
        }

    } while(moveu);


    cout << p.linha << " " << p.coluna << endl;


    return 0;
}