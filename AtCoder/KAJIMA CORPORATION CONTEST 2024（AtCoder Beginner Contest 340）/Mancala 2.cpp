/*
There are N boxes numbered 0 to N−1. Initially, box i contains

Ai​ balls.

Takahashi will perform the following operations for

i=1,2,…,M in order:

Set a variable  C to 0.
Take out all the balls from box Bi​ and hold them in hand.

While holding at least one ball in hand, repeat the following process:

Increase the value of C by 1.
Put one ball from hand into box (Bi​+C)modN.

Determine the number of balls in each box after completing all operations.

Constraints

1≤N≤2×105
1≤M≤2×105
0≤Ai​≤109
0≤Bi​<N

All input values are integers.
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

const ll MOD = 10e9 + 7;
const ll MOD_FFT = 998'244'353;

const ll PRIME_HASH1 = 31;
const ll PRIME_HASH2 = 37;

using namespace std;


const ll MAX = 200'000;
ll BIT[MAX + 10];


void update(ll x, ll delta) //add "delta" at index "x"
{
    for(; x <= MAX; x += x&-x)
          BIT[x] += delta;
}


ll query(int x)//returns the sum of first x elements in given array a[]
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
    ll n, m;
    vector<ll> balls;
    ll index;


    cin >> n >> m;

    balls.resize(n+1);

    for (int i = 1; i <= n; i++)
    {
        cin >> balls[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> index;
        index += 1;

        ll temp = query(index);
        balls[index] += temp;
        update(index, -temp);
        update(index+1, temp);

        update(1, balls[index]/n);
        balls[index] %= n;

        if (balls[index] > 0)
        {
            if (index+balls[index] <= n)
            {
                update(index+1, 1);
                update(index+balls[index]+1, -1);
            }
            else
            {
                update(index+1, 1);
                update(1, 1);
                update((index+balls[index])%(n+1)+2, -1);
            }
        }
        /////////////////
        balls[index] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (query(i) + balls[i]) << " ";
    }
    cout << endl;


    return 0;
}