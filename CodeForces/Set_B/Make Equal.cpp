/* https://codeforces.com/contest/1931/problem/B */
/*
There are n containers of water lined up, numbered from left to right from 1 to n. Each container can hold any
amount of water; initially, the i-th container contains ai units of water. The sum of ai is divisible by n.

You can apply the following operation any (possibly zero) number of times: pour any amount of water from the i-th
container to the j-th container, where i must be less than j (i.e. i<j). Any index can be chosen as i or j
any number of times.

Determine whether it is possible to make the amount of water in all containers the same using this operation.


Input

The first line of the input contains a single integer t
(1≤t≤104) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains a single integer n
(1≤n≤2⋅105) — the number of containers with water.

The second line of each test case contains n
integers a1,a2,…,an (0≤ai≤109) — the amounts of water in the containers. It is guaranteed that the sum of ai
in each test case does not exceed 2⋅109. Also, the sum of ai is divisible by n.

It is guaranteed that the sum of n
over all test cases in the input does not exceed 2⋅105.


Output

Output t

lines, each of which is the answer to the corresponding test case. As the answer, output "YES" if it is possible
to make the amount of water in all containers the same using the described operation. Otherwise, output "NO".

You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and
"YES" will be accepted as a positive answer.
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
        ll n;
        vector<ll> vec;
        ll extra = 0;
        ll equal = 0;
        bool cant = false;

        cin >> n;

        vec.resize(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
            equal += vec[i];
        }
        equal /= n;

        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] > equal)
            {
                extra += vec[i] - equal;
            }
            else if (vec[i] < equal)
            {
                if (extra < equal - vec[i])
                {
                    cant = true;
                    break;
                }
                else
                {
                    extra -= equal - vec[i];
                }
            }
        }

        if (cant || extra != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }




    return 0;
}