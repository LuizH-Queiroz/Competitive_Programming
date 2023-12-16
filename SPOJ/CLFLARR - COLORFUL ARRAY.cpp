/*
You have been given an array of n unpainted elements. By unpainted, we mean that each element initially
has a value of 0. You have to process q queries of the form l r c, in which you paint all the elements of
the array from index l to index r with color c. Assume that, each new color currently being applied to an
element overrides its previous color. Output the color of each element after all the queries have been processed.

Note: The problem is guaranteed to be solved using C or C++ programming language.

Input
The first line of input consists of two integers n and q. Next q lines consists of 3 integers l, r and c
denoting the starting index, ending index and the color respectively.

1 <= n <= 200000
1 <= q <= 200000
1 <= l <= r <= n
1 <= c <= 1 000 000 000

Output
Output the final color of each element starting from index 1 on a new line.
*/
#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;



typedef struct {
    int l, r;
    ll color;
} Query;



int numElements, numQueries;
vector<int> nextIndex;
vector<ll> elements;


int find_parent(int n) {
    if (n > numElements || elements[n] == 0ll)
        return n;
    
    return nextIndex[n] = find_parent(nextIndex[n]);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    vector<Query> queries;


    cin >> numElements >> numQueries;

    nextIndex.resize(numElements+1);
    elements.resize(numElements+1, 0ll);
    queries.resize(numQueries+1);

    iota(nextIndex.begin(), nextIndex.end(), 1);


    for (int i = 1; i <= numQueries; i++)
    {
        cin >> queries[i].l >> queries[i].r >> queries[i].color;
    }

    for (int i = numQueries; i >= 1; i--)
    {
        for (int j = find_parent(queries[i].l); j <= queries[i].r; j = find_parent(j))
        {
            elements[j] = queries[i].color;
        }
    }

    for (int i = 1; i <= numElements; i++)
    {
        cout << elements[i] << endl;
    }


    return 0;
}