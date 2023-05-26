/*
Temos uma sequência de N quadrados desenhados lado a lado. Cada quadrado possui um número natural anotado dentro dele. Dados a sequência dos
N quadrados e um valor K , quantos retângulos distintos existem cuja soma dos números dentro do retângulo é exatamente igual a K?
Por exemplo, a figura mostra uma sequência de N = 10 quadrados para a qual existem 5 retângulos cuja soma dos números é igual a K = 4.


Entrada

A primeira linha da entrada contém dois inteiros N (1 ≤ N ≤ 5 × 105) e K (0 ≤ K ≤ 106) representando o número de quadrados na sequência e o valor
da soma desejada. A segunda linha da entrada contém N números naturais Xi , para 1 ≤ i ≤ N, indicando a sequência de números anotados dentro
dos quadrados.

Saída

Seu programa deve imprimir uma linha contendo um número inteiro representando quantos retângulos existem na sequência cuja soma é igual a K.
*/
#include <iostream>
#include <vector>

using namespace std;



int primeira_ocorrencia(vector<int>& vec, int alvo, int inicio) {
    int fim = vec.size()-1;
    int meio;

    int indice = -1;

    while(inicio <= fim)
    {
        meio = (inicio + fim)/2;

        if (alvo < vec[meio])
        {
            fim = meio - 1;
        }
        else if (alvo > vec[meio])
        {
            inicio = meio + 1;
        }
        else // alvo == vec[meio]
        {
            indice = meio;
            fim = meio - 1;
        }
    }

    return indice;
}


int ultima_ocorrencia(vector<int>& vec, int alvo, int inicio) {
    int fim = vec.size()-1;
    int meio;

    int indice = -1;

    while(inicio <= fim)
    {
        meio = (inicio + fim)/2;

        if (alvo < vec[meio])
        {
            fim = meio - 1;
        }
        else if (alvo > vec[meio])
        {
            inicio = meio + 1;
        }
        else // alvo == vec[meio]
        {
            indice = meio;
            inicio = meio + 1;
        }
    }

    return indice;
}



int main() {
    int tamanho, valor_desejado;
    vector<int> sequencia; // Vector de soma acumulada


    cin >> tamanho >> valor_desejado;

    sequencia.resize(tamanho+1);
    sequencia[0] = 0;
    for (int i = 1; i <= tamanho; i++)
    {
        cin >> sequencia[i];
        sequencia[i] += sequencia[i-1];
    }


    unsigned long long subArrays = 0;
    int primeiraOcorrencia;
    for (int i = 1; i <= tamanho; i++)
    {
        primeiraOcorrencia = primeira_ocorrencia(sequencia, (valor_desejado + sequencia[i-1]), i);
        if (primeiraOcorrencia != -1)
        {
            subArrays += (ultima_ocorrencia(sequencia, (valor_desejado + sequencia[i-1]), i) - primeiraOcorrencia) + 1;
        }
    }
    cout << subArrays << endl;


    return 0;
}