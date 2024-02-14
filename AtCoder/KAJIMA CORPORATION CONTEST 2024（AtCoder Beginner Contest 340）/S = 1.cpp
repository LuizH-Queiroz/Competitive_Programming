/* https://atcoder.jp/contests/abc340/tasks/abc340_f */
/*
You are given integers X and Y, which satisfy at least one of X=0 and Y=0.
Find a pair of integers (A,B) that satisfies all of the following conditions.
If no such pair exists, report so.

−10e18≤A,B≤10e18

The area of the triangle with vertices at points
(0,0),(X,Y),(A,B) on the xy-plane is 1.

Constraints

−10e17≤X,Y≤10e17
(X,Y)!=(0,0)
X and Y are integers.
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


// Problem's diophantine equation: xB - yA = 2
ll ex_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ex_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    ll x, y;
    ll a, b;
    ll ret;


    cin >> x >> y;

    ret = ex_gcd(x, -y, b, a);
    if (2%ret != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    ll mult = 2/ret;
    cout << (a*mult) << " " << (b*mult) << endl;


    return 0;
}