/*
You find yourself in a mysterious binary world, where an array of N binary digits awaits your scrutiny.
Each digit is either a zero or a one, creating a unique pattern across the landscape.
Your quest is to uncover the hidden patterns of this binary realm by unraveling the significance of
subarrays with an odd number of ones.

The array of digits is denoted as b1,b2,…,bN. Your task is to embark on a journey to discover the enigmatic
subarrays – segments of consecutive digits – and determine the count of subarrays that harbor an odd
number of ones.

As you traverse this binary landscape, remember that a subarray is defined by its starting and ending digits.
For instance, in the sequence [b1,b2,b3]
, subarrays include [b1]
, [b2]
, [b3]
, [b1,b2]
, [b2,b3]
, and [b1,b2,b3].

Your mission is to design an algorithm that determines the total number of subarrays containing an odd number
of ones within this binary sequence. Please don't forget that the answer might not fit in a 32-bits integer.

Input
The first line contains an integer N (1≤N≤105) representing the length of the binary sequence.

The second line contains N binary digits b1,b2,…,bN (bi∈{0,1}) representing the elements of the sequence.

Output
Output a single line with an integer representing the count of subarrays in the sequence that hold
an odd number of ones.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    ///////////////////////
    int tamanho;
    vector<int> sequencia;


    cin >> tamanho;

    sequencia.resize(tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        cin >> sequencia[i];
    }


    unsigned long long contador;
    vector<unsigned long long> par(tamanho);
    vector<unsigned long long> impar(tamanho);

    if (sequencia[0] == 1)
    {
        par[0] = 0;
        impar[0] = 1;
        contador = 1;
    }
    else
    {
        par[0] = 1;
        impar[0] = 0;
        contador = 0;
    }


    for (int i = 1; i < tamanho; i++)
    {
        if (sequencia[i] == 1)
        {
            impar[i] = par[i-1] + 1;
            par[i] = impar[i-1];
        }
        else // sequencia[i] == 0
        {
            impar[i] = impar[i-1];
            par[i] = par[i-1] + 1;
        }

        contador += impar[i];
    }


    cout << contador << endl;


    return 0;
}