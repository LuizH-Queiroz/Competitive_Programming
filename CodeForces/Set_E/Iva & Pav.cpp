/*
Iva and Pav are a famous Serbian competitive programming couple. In Serbia, they call Pav "papuca" and
that's why he will make all of Iva's wishes come true.

Iva gave Pav an array a of n elements.

Let's define f(l,r)=al & al+1 &…& ar (here & denotes the bitwise AND operation).

Note that f(l,r) is not defined when l>r.

Iva also gave Pav q queries.

Each query consists of 2 numbers, k and l, and she wants Pav to find the largest index r (l≤r≤n),
such that f(l,r)≥k.

Pav wants to solve this problem fast because he doesn't want to upset Iva. He needs your help.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤2⋅105) — the length of array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of array a.

The third line of each test case contains a single integer q (1≤q≤105) — the number of queries Iva gave Pav.

The next q lines of each test case contains two numbers, l and k (1≤l≤n, 1≤k≤109) — the
left bound for the subsegment, and the integer k described in statement.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.
Also, it is guaranteed that the sum of q over all test cases does not exceed 2⋅105.

Output
For each query output maximal index r (l≤r≤n) such that al & al+1 &…& ar ≥ k.

If such r doesn't exist, output −1.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAXN 200'000

using namespace std;


//Declara a segtree. O parâmetro 'MAXN' deve ser substituído pelo tamanho do array
//que dará origem à segTree
int t[4*MAXN];


// preenche o vator t com a segTree.
//O usuário preenche v com 1, tl com o índice inicial do array e tr com o índice final
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] & t[v*2+1];
    }
}


//retorna a soma dos elementos no intervalo l e r do array original
int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT32_MAX;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
           & query(v*2+1, tm+1, tr, max(l, tm+1), r);
}


//faz um update no equivalente de segTree ao índice 'pos' no array
//original com o valor 'new_val'
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] & t[v*2+1];
    }
}



int bsearch(int l, int r, int k) {
    int start = l;
    int end = r;
    int middle = r;
    int index = -1;

    while(start <= end)
    {
        if (query(1, 1, r, l, middle) >= k)
        {
            index = middle;
            start = middle+1;
        }
        else
        {
            end = middle-1;
        }
        middle = (start+end)/2;
    }

    return index;
}



int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int tests;
    int length, numQueries;
    int l, k;


    cin >> tests;
    while(tests--)
    {
        cin >> length;

        int arr[length+1];
        for (int i = 1; i <= length; i++)
        {
            cin >> arr[i];
        }
        build(arr, 1, 1, length);


        cin >> numQueries;
        for (int i = 0; i < numQueries; i++)
        {
            cin >> l >> k;
            cout << bsearch(l, length, k) << " ";
        }
        cout << endl;
    }


    return 0;
}