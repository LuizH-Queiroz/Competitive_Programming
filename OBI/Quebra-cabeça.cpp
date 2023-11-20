/*
Jade precisa da sua ajuda para montar o quebra-cabeças que ela ganhou de presente da sua tia Zoraide!
As peças são encaixadas lado a lado e contêm, cada uma, uma letra maiúscula. Quando o quebra-cabeças
estiver montado, a sequência de letras revelará uma frase secreta. Cada peça possui, além da letra,
dois números: um na parte esquerda e outro na parte direita. Uma peça se encaixa depois de outra,
na sequência, quando seu número esquerdo for igual ao número direito da outra peça.
O número esquerdo da primeira peça é sempre o 0 (zero) e o número direito da última peça é sempre o 1 (um).
Cada número aparece no máximo uma vez na parte esquerda de alguma peça, e no máximo uma vez na parte direita.
Sempre é possível encaixar todas as peças e em apenas uma única sequência! Veja um exemplo na figura,
com quatro peças formando a palavra " TEMA".


Entrada
A primeira linha da entrada contém um número natural N, indicando o número de peças do quebra-cabeças.
As N linhas seguintes contêm, cada uma, a descrição de uma peça na forma E C D, onde: E é o número esquerdo;
C é a letra maiúscula; e D é o número direito.

Saída
Seu programa deve escrever uma única linha na saída, contendo a sequência de letras formada quando o
quebra-cabeças está montado.

Restrições
3 ≤ N ≤ 100000; 0 ≤ E ≤ 200000; e 0 ≤ D ≤ 200000
Há exatamente uma maneira de montar o quebra-cabeças utilizando todas as peças dadas.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int numPecas;
    int esquerda, direita;
    char caractere;
    vector<pair<char, int>> peca(200'001);


    cin >> numPecas;
    for (int i = 0; i < numPecas; i++)
    {
        cin >> esquerda >> caractere >> direita;
        peca[esquerda] = {caractere, direita};
    }

    for (int atual = 0; atual != 1; atual = peca[atual].second)
    {
        cout << peca[atual].first;
    }
    cout << endl;


    return 0;
}