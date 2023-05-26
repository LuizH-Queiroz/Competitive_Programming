/*
O discípulo Fan Chi’ih retornou recentemente da China com algumas cápsulas mágicas, que são capazes de produzir moedas de ouro!
Uma cápsula possui um certo ciclo de produção, que é um número C de dias. A cada C dias a cápsula produz uma nova moeda;
a moeda é sempre produzida no último dia do ciclo. Fan Chi’ih vai ativar todas as cápsulas ao mesmo tempo e quer acumular uma fortuna de
pelo menos F moedas. Ele precisa da sua ajuda para computar o número mínimo de dias para que as cápsulas produzam, no total, pelo menos F moedas.
Na tabela abaixo, por exemplo, existem três cápsulas com ciclos de 3, 7 e 2 dias. Se Fan Chi’ih quiser acumular pelo menos 12 moedas,
ele vai ter que esperar pelo menos 14 dias.


Entrada

A primeira linha da entrada contém dois inteiros N (1 ≤ N ≤ 105) e F (1 ≤ F ≤ 109), indicando o número de cápsulas e o número de moedas que
Fan Chi’ih quer produzir, respectivamente. A segunda linha contém N inteiros Ci (1 ≤ Ci ≤ 106), para 1 ≤ i ≤ N, representando os ciclos de cada cápsula.
Em todos os casos de teste, a resposta é sempre menor ou igual a 108 dias. Em todos os casos de teste, o número de moedas produzido, no total, após
108 dias, é sempre menor ou igual a 109.

Saída
Imprima um inteiro, representando o número mínimo de dias para que as cápsulas produzam, no total, pelo menos F moedas. 
*/
#include <iostream>
#include <vector>

#define MAX_DIAS 100000000

using namespace std;



int busca_binaria(vector<int>& ciclos, int moedas) {
    int inicio = 1;
    int fim = MAX_DIAS;
    int meio;

    int min_dias;
    int produzido;

    while(inicio <= fim)
    {
        meio = (inicio + fim)/2;

        produzido = 0;
        for (int i = 0; i < ciclos.size(); i++)
            produzido += meio/ciclos[i];
        
        if (moedas <= produzido)
        {
            min_dias = meio;
            fim = meio-1;
        }
        else if (moedas > produzido)
        {
            inicio = meio+1;
        }
    }

    return min_dias;
}



int main() {
    int capsulas, moedas;
    vector<int> ciclos;


    cin >> capsulas >> moedas;

    ciclos.resize(capsulas);
    for (int i = 0; i < capsulas; i++)
        cin >> ciclos[i];
    
    cout << busca_binaria(ciclos, moedas) << endl;


    return 0;
}