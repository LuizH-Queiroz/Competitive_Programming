/*
Quite recently a creative student Lesha had a lecture on trees. After the lecture Lesha was inspired and
came up with the tree of his own which he called a k-tree.

A k-tree is an infinite rooted tree where:

each vertex has exactly k children;
each edge has some weight;
if we look at the edges that goes from some vertex to its children (exactly k edges), then their weights
will equal 1, 2, 3, ..., k.
The picture below shows a part of a 3-tree.

As soon as Dima, a good friend of Lesha, found out about the tree, he immediately wondered:
"How many paths of total weight n (the sum of all weights of the edges in the path) are there,
starting from the root of a k-tree and also containing at least one edge of weight at least d?".
Help Dima find an answer to his question. As the number of ways can be rather large, print it
modulo 1000000007 (109 + 7).

Input
A single line contains three space-separated integers: n, k and d (1 ≤ n, k ≤ 100; 1 ≤ d ≤ k).

Output
Print a single integer — the answer to the problem modulo 1000000007 (109 + 7).
*/
#include <iostream>
#include <vector>

#define endl "\n"

#define MOD 1000000007

using namespace std;


int n, k, d;
vector<vector<long long>> dp;


long long solve(int n, int flag) {
    if (n < 0)
    {
        return 0;
    }
    else if (dp[n][flag] != -1)
    {
        return dp[n][flag];
    }
    else if (n == 0)
    {
        return dp[n][flag] = flag;
    }

    long long sol = 0;
    for (int i = 1; i <= k; i++)
    {
        sol = (sol + solve(n-i, (flag || (i >= d)))) % MOD;
    }
    return dp[n][flag] = sol;
}


int main() {

    cin >> n >> k >> d;
    dp = vector<vector<long long>>(n+10, vector<long long>(2, -1));
    cout << solve(n, 0) << endl;

    return 0;
}