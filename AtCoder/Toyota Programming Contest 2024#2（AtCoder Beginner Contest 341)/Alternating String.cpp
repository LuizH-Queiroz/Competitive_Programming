/* https://atcoder.jp/contests/abc341/tasks/abc341_e */
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


const ll MAX = 500'010;
ll BIT[MAX + 1];


void update(ll x, ll delta) //add "delta" at index "x"
{
    for(; x <= MAX; x += x&-x)
        BIT[x] += delta;
}


ll query(ll x)//returns the sum of first x elements in given array a[]
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}



int main() {
    ios::sync_with_stdio(0);
    // cin.tie(0);
    ////////////////////////
    ll n, q;
    ll type;
    ll l, r;
    string str, tempStr;

    cin >> n >> q;
    cin >> tempStr;

    str = " " + tempStr;

    // cout << str << endl;
    for (int i = 2; i < str.size(); i++)
    {
        if (str[i] == str[i-1])
        {
            update(i, 1);
        }
    }


    for (int i = 0; i < q; i++)
    {
        cin >> type >> l >> r;

        if (type == 1)
        {
            // l
            if (l != 1)
            {
                if ((query(l)-query(l-1)) == 1)
                {
                    update(l, -1);
                }
                else if ((query(l)-query(l-1)) == 0)
                {
                    update(l, 1);
                }
            }

            // r
            if ((query(r+1)-query(r)) == 1)
            {
                update(r+1, -1);
            }
            else if ((query(r+1)-query(r)) == 0)
            {
                update(r+1, 1);
            }
        }
        else // type == 2
        {
            ll temp = query(r) - query(l);

            if (temp == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }




    return 0;
}