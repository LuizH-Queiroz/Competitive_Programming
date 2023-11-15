/*
Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n.
Xenia is currently studying bit operations. To better understand how they work, Xenia decided to
calculate some value v for a.

Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new
sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, consisting of 2n - 1 elements. In other words,
she writes down the bit-wise OR of adjacent elements of sequence a. At the second iteration, Xenia writes
the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration.
At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained
after the second iteration. And so on; the operations of bitwise exclusive OR and bitwise OR alternate.
In the end, she obtains a sequence consisting of one element, and that element is v.

Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). Then let's write down all the
transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.

You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy,
so you are given additional m queries. Each query is a pair of integers p, b.
Query p, b means that you need to perform the assignment ap = b.
After each query, you need to print the new value v for the new sequence a.

Input
The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 105).
The next line contains 2n integers a1, a2, ..., a2n (0 ≤ ai < 230). Each of the next m lines contains queries.
The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.

Output
Print m integers — the i-th integer denotes value v for sequence a after the i-th query.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAXN (1<<17)

#define OR 1
#define XOR 0

using namespace std;


//Declara a segtree. O parâmetro 'MAXN' deve ser substituído pelo tamanho do array
//que dará origem à segTree
int tree[4*MAXN];
vector<int> arr;


void build(int node, int start, int end, int *nextOperation)
{
    int currOperation;
    if (start == end)
    {
        // Leaf node will have a single element
        tree[node] = arr[start];
        *nextOperation = OR;
    }
    else
    {    
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2 * node, start, mid, &currOperation);
        // Recurse on the right child
        build(2 * node + 1, mid + 1, end, &currOperation);
        // Internal node will have the sum of both of its children

        if (currOperation == OR)
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        else
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];

        if (nextOperation != nullptr)
            *nextOperation = 1 - currOperation;
    }
}


void update(int node, int start, int end, int idx, int val, int *nextOperation)
{
    int currOperation;
    if (start == end)
    {
        // Leaf node
        // A[idx] += val;
        tree[node] = val;
        *nextOperation = OR;
    }
    else
    {
        int mid = (start + end) / 2;
        if (start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2 * node, start, mid, idx, val, &currOperation);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2 * node + 1, mid + 1, end, idx, val, &currOperation);
        }
        
        // Internal node will have the sum of both of its children
        if (currOperation == OR)
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        else
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        
        if (nextOperation != nullptr)
            *nextOperation = 1 - currOperation;
    }
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int length, numQueries;
    int index, val;


    cin >> length >> numQueries;
    length = (1<<length);

    arr.resize(length+1);
    for (int i = 1; i <= length; i++)
    {
        cin >> arr[i];
    }
    build(1, 1, length, nullptr);


    for (int i = 0; i < numQueries; i++)
    {
        cin >> index >> val;

        update(1, 1, length, index, val, nullptr);
        cout << tree[1] << endl;
    }


    return 0;
}