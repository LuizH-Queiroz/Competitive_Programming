/*
Seu Madruga finalmente arrumou um emprego, é sua grande chance de pagar os 14 meses de aluguel que
estão atrasados. Seu cargo é o de cortador de papel e o salário é excelente.

Madruga irá receber N tiras retangulares de papel com 1 cm de largura e C cm de comprimento.
As tiras devem ser colocadas uma ao lado da outra de forma que suas bases estejam alinhadas.
A tarefa de seu Madruga será, com apenas um corte em linha reta, paralelo à base, fazer com que
a soma das áreas das tiras cortadas seja igual a A cm².

Veja a ilustração abaixo com N = 5 e as tiras com 5, 3, 6, 2 e 3 cm de comprimento, respectivamente,
para um A = 3 cm².

comprimento das tiras

Com um corte feito a uma altura de 4 cm em relação a base, a área resultante, pintada de vermelho,
é exatamente igual a A cm². Sua tarefa é descobrir essa altura H e ajudar Seu Madruga a se manter
no emprego.

Entrada
Haverá diversos casos de testes. A primeira linha de cada caso inicia com dois inteiros N (1 ≤ N ≤ 105)
e A (1 ≤ A ≤ 109) representando, respectivamente, a quantidade de tiras e a área resultante esperada.
A próxima linha conterá N inteiros, representando o comprimento Ci (1 <= Ci <= 104) de cada tira.

A entrada termina com N = A = 0, a qual não deve ser processada.

Saída
Para cada caso, exiba uma única linha, a altura H do corte que Seu Madruga deve fazer para que
a soma da área das tiras cortadas seja igual a A cm². Use 4 casas decimais após o ponto.

Exiba “:D”, caso nenhum corte seja necessário, ou “-.-“ caso seja impossível.
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#define endl '\n'
#define llu unsigned long long

#define MAX_ALTURA 10'000

using namespace std;


int numTiras, areaEsperada;
int maiorAltura;

vector<int> contadorAltura;


double solve() {
    llu area = 0;
    int numRetangulos = 0;
    double altura = 0;

    for (int i = maiorAltura; area < areaEsperada; i--)
    {
        area += contadorAltura[i] + numRetangulos;
        numRetangulos += contadorAltura[i];
        altura++;
    }

    return maiorAltura - (altura - (area - areaEsperada)/((double) numRetangulos));
}


int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int altura;
    llu areaTotal;


    cout << fixed << setprecision(4);
    while(true)
    {
        cin >> numTiras >> areaEsperada;
        if (numTiras == 0)
            break;
        

        areaTotal = 0;
        maiorAltura = 0;
        contadorAltura = vector<int>(MAX_ALTURA+1, 0);
        for (int i = 0; i < numTiras; i++)
        {
            cin >> altura;
            contadorAltura[altura]++;
            areaTotal += altura;
            maiorAltura = max(maiorAltura, altura);
        }


        if (areaTotal < areaEsperada)
            cout << "-.-" << endl;
        else if (areaTotal == areaEsperada)
            cout << ":D" << endl;
        else
            cout << solve() << endl;
    }


    return 0;
}