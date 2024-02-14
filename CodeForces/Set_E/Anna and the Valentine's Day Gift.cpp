/* https://codeforces.com/contest/1931/problem/E */
/*
Sasha gave Anna a list a of n

integers for Valentine's Day. Anna doesn't need this list, so she suggests destroying it by playing a game.

Players take turns. Sasha is a gentleman, so he gives Anna the right to make the first move.

On her turn, Anna must choose an element ai from the list and reverse the sequence of its digits.
For example, if Anna chose the element with a value of 42, it would become 24;
if Anna chose the element with a value of 1580, it would become 851.
Note that leading zeros are removed. After such a turn, the number of elements in the list does not change.
On his turn, Sasha must extract two elements ai
and aj (i≠j) from the list, concatenate them in any order and insert the result back into the list.
For example, if Sasha chose the elements equal to 2007 and 19, he would remove these two elements from the list
and add the integer 200719 or 192007. After such a turn, the number of elements in the list decreases by 1.

Players can't skip turns. The game ends when Sasha can't make a move, i.e. after Anna's move there is exactly one
number left in the list.
If this integer is not less than 10m (i.e., ≥10m), Sasha wins. Otherwise, Anna wins.

It can be shown that the game will always end. Determine who will win if both players play optimally.


Input

The first line contains an integer t
(1≤t≤104) — the number of test cases.

Then follows the description of the test cases.

The first line of each test case contains integers n
, m (1≤n≤2⋅105, 0≤m≤2⋅106) — the number of integers in the list and the parameter determining when Sasha wins.

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤109) — the list that Sasha gave to Anna.

It is guaranteed that the sum of n
for all test cases does not exceed 2⋅105.


Output

For each test case, output:

    "Sasha", if Sasha wins with optimal play;
    "Anna", if Anna wins with optimal play. 
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


typedef struct Value {
    ll val;
    ll leading;

    bool operator<(Value other) const {
        return leading < other.leading;
    }
};


ll countLeading(ll n) {
    ll counter = 0;

    while(n != 0 && n%10 == 0)
    {
        counter++;
        n /= 10;
    }

    return counter;
}


ll countDigits(ll n) {
    ll counter = 0;

    while(n > 0)
    {
        counter++;
        n /= 10;
    }

    return counter;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int t;

    cin >> t;

    while(t--)
    {
        ll n, m;
        ll digits = 0;
        vector<Value> vec;

        cin >> n >> m;
        m += 1; // Number of digits

        vec.resize(n);

        for (int i = 0; i < vec.size(); i++)
        {
            cin >> vec[i].val;
            vec[i].leading = countLeading(vec[i].val);

            digits += countDigits(vec[i].val);
        }


        sort(vec.rbegin(), vec.rend());
        for (int i = 0; i < vec.size(); i+=2)
        {
            if (vec[i].leading == 0)
            {
                break;
            }

            digits -= vec[i].leading;
        }


        if (digits >= m)
        {
            cout << "Sasha" << endl;
        }
        else
        {
            cout << "Anna" << endl;
        }
    }




    return 0;
}