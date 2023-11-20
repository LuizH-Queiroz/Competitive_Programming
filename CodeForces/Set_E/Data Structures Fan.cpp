/*
You are given an array of integers a1,a2,…,an, as well as a binary string† s consisting of n characters.

Augustin is a big fan of data structures. Therefore, he asked you to implement a data structure that can answer q
queries. There are two types of queries:

"1 l r" (1≤l≤r≤n) — replace each character si for l≤i≤r with its opposite. That is, replace all 0 with 1
and all 1 with 0.

"2 g" (g∈{0,1}) — calculate the value of the bitwise XOR of the numbers ai for all indices i such that si=g.
Note that the XOR of an empty set of numbers is considered to be equal to 0.

Please help Augustin to answer all the queries!

For example, if n=4, a=[1,2,3,6], s=1001, consider the following series of queries:

"2 0" — we are interested in the indices i for which si=0, since s=1001, these are the indices 2 and 3,
so the answer to the query will be a2⊕a3=2⊕3=1.

"1 1 3" — we need to replace the characters s1,s2,s3 with their opposites, so before the query s=1001,
and after the query: s=0111.

"2 1" — we are interested in the indices i for which si=1, since s=0111, these are the indices 2, 3, and 4,
so the answer to the query will be a2⊕a3⊕a4=2⊕3⊕6=7.

"1 2 4" — s=0111 → s=0000.

"2 1" — s=0000, there are no indices with si=1, so since the XOR of an empty set of numbers is considered
to be equal to 0, the answer to this query is 0.

† A binary string is a string containing only characters 0 or 1.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases in the test.

The descriptions of the test cases follow.

The first line of each test case description contains an integer n (1≤n≤105) — the length of the array.

The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109).

The third line of the test case contains the binary string s of length n.

The fourth line of the test case contains one integer q (1≤q≤105) — the number of queries.

The subsequent q lines of the test case describe the queries. The first number of each query, tp∈{1,2},
characterizes the type of the query: if tp=1, then 2 integers 1≤l≤r≤n follow, meaning that the operation
of type 1 should be performed with parameters l,r, and if tp=2, then one integer g∈{0,1} follows,
meaning that the operation of type 2 should be performed with parameter g.

It is guaranteed that the sum of n over all test cases does not exceed 105, and also that the sum of q
over all test cases does not exceed 105.

Output
For each test case, and for each query of type 2 in it, output the answer to the corresponding query.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAXN 100'000

using namespace std;


//Declara a segtree. O parâmetro 'MAXN' deve ser substituído pelo tamanho do array
//que dará origem à segTree
int allTree[4*MAXN];
int oneTree[4*MAXN];
int lazy[4*MAXN]; // Refers to oneTree

string str;
vector<int> arr;


void build(int tree[], int node, int start, int end, bool all)
{
    if (start == end)
    {
        // Leaf node will have a single element
        if (all || str[start-1] == '1')
            tree[node] = arr[start];
        else
            tree[node] = 0;
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(tree, 2 * node, start, mid, all);
        // Recurse on the right child
        build(tree, 2 * node + 1, mid + 1, end, all);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }
}


int queryRange(int tree[], bool useLazy, int node, int start, int end, int l, int r)
{
    if(start > end || start > r || end < l)
        return 0;         // Out of range
    if(useLazy && lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] = tree[node] ^ queryRange(allTree, false, 1, 1, arr.size()-1, start, end); // Update it
        if(start != end)
        {
            lazy[node*2] = 1 - lazy[node*2];         // Mark child as lazy
            lazy[node*2+1] = 1 - lazy[node*2+1];    // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(start >= l && end <= r) // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(tree, useLazy, node*2, start, mid, l, r); // Query left child
    int p2 = queryRange(tree, useLazy, node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 ^ p2);
}


void updateRange(int node, int start, int end, int l, int r)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        oneTree[node] = oneTree[node] ^ queryRange(allTree, false, 1, 1, arr.size()-1, start, end); // Update it
        if(start != end)
        {
            lazy[node*2] = 1 - lazy[node*2];         // Mark child as lazy
            lazy[node*2+1] = 1 - lazy[node*2+1];    // Mark child as lazy
        }
        lazy[node] = 0; // Reset it
    }
    if(start > end || start > r || end < l) // Current segment is not within range [l, r]
        return;
    if(start >= l && end <= r)
    {
        // Segment is fully within range
        oneTree[node] = oneTree[node] ^ queryRange(allTree, false, 1, 1, arr.size()-1, start, end); // Update it
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] = 1 - lazy[node*2];
            lazy[node*2+1] = 1 - lazy[node*2+1];
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r); // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r); // Updating right child
    oneTree[node] = oneTree[node*2] ^ oneTree[node*2+1]; // Updating root with max value
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int tests;
    int length, numQueries;
    int type, l, r, g;


    cin >> tests;
    while(tests--)
    {
        cin >> length;

        arr.resize(length+1);
        for (int i = 1; i <= length; i++)
        {
            cin >> arr[i];
        }

        cin >> str;
        build(allTree, 1, 1, length, true);
        build(oneTree, 1, 1, length, false);
        memset(lazy, 0, sizeof(lazy));

        cin >> numQueries;
        for (int i = 0; i < numQueries; i++)
        {
            cin >> type;

            // Update
            if (type == 1)
            {
                cin >> l >> r;
                updateRange(1, 1, length, l, r);
            }
            // Calculate XOR
            else
            {
                cin >> g;

                if (g == 1)
                {
                    cout << queryRange(oneTree, true, 1, 1, length, 1, length) << " ";
                }
                else
                {
                    cout << (queryRange(oneTree, true, 1, 1, length, 1, length) ^ queryRange(allTree, false, 1, 1, length, 1, length)) << " ";
                }
            }
        }

        cout << endl;
    }


    return 0;
}