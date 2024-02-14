/* https://codeforces.com/contest/1931/problem/F */
/*
There are n

people in the programming contest chat. Chat participants are ordered by activity, but each person sees himself
at the top of the list.

For example, there are 4 participants in the chat, and their order is [2,3,1,4]. Then

1-st user sees the order [1,2,3,4].
2-nd user sees the order [2,3,1,4].
3-rd user sees the order [3,2,1,4].
4-th user sees the order [4,2,3,1]. 

k people posted screenshots in the chat, which show the order of participants shown to this user.
The screenshots were taken within a short period of time, and the order of participants has not changed.

Your task is to determine whether there is a certain order that all screenshots correspond to.


Input

The first line contains a single integer t
(1≤t≤104) — the number of input test cases. The descriptions of test cases follow.

The first line of the description of each test case contains two integers n
and k (1≤k≤n≤2⋅105,n⋅k≤2⋅105) — the number of chat participants and the number of participants who posted screenshots.

The following k lines contain descriptions of screenshots posted by the participants.

The i-th row contains n integers aij each (1≤aij≤n, all aij are different) — the order of participants shown to
the participant ai0, where ai0 — the author of the screenshot. You can show that in the screenshot description it
will always be at the top of the list.

It is guaranteed that the sum of n⋅k
for all test cases does not exceed 2⋅105.
It is also guaranteed that all the authors of the screenshots are different.


Output

Output t lines, each of which is the answer to the corresponding test case.
As an answer, output "YES" if there exists at least one order of participants, under which all k

screenshots could have been obtained. Otherwise, output "NO".

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes",
and "YES" will be recognized as positive responses.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "; " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int t;

    cin >> t;

    while(t--)
    {
        ll n, k;
        vector<set<ll>> adj;
        vector<set<ll>> rev;
        vector<ll> outEdges;
        vector<bool> used;
        ll prev, curr;

        cin >> n >> k;

        adj.resize(n+1);
        rev.resize(n+1);
        outEdges.resize(n+1, 0);
        used.resize(n+1, false);


        for (int i = 0; i < k; i++)
        {
            prev = -1;
            for (int j = 0; j < n; j++)
            {
                cin >> curr;
                if (j >= 2)
                {
                    adj[prev].insert(curr);
                    rev[curr].insert(prev);
                    // outEdges[prev]++;
                }

                prev = curr;
            }
        }

        // Looking for a topological sort
        queue<ll> q;
        ll counter = 0;

        for (int i = 1; i <= n; i++)
        {
            if (adj[i].size() == 0)
            {
                q.push(i);
                used[i] = true;
                counter++;
            }
        }

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            for (int u : rev[v])
            {
                // outEdges[u]--;
                adj[u].erase(v);
                if (adj[u].size() == 0)
                {
                    q.push(u);
                    used[u] = true;
                    counter++;
                }
            }
        }


        if (counter == n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }




    return 0;
}