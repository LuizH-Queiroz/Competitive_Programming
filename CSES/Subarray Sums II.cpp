/*
Given an array of n integers, your task is to count the number of subarrays having sum x.

Input
The first input line has two integers n and x: the size of the array and the target sum x.
The next line has n integers a_1,a_2,\dots,a_n: the contents of the array.

Output
Print one integer: the required number of subarrays.
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



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    ll n, x;
    map<ll, ll> sumCount;
    ll val;
    ll pref = 0;
    ll ans = 0;


    cin >> n >> x;

    sumCount[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> val;

        pref += val;
        ans += sumCount[pref-x];
        
        sumCount[pref]++;
    }

    cout << ans << endl;


    return 0;
}