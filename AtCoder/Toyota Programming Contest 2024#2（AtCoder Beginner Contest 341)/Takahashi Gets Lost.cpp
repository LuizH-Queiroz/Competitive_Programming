/* https://atcoder.jp/contests/abc341/tasks/abc341_c */
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


ll solve(vector<string>& matrix, string& str, ll i, ll j) {

    for (char c : str)
    {
        if (c == 'L')
        {
            j--;
        }
        else if (c == 'R')
        {
            j++;
        }
        else if (c == 'U')
        {
            i--;
        }
        else if (c == 'D')
        {
            i++;
        }

        if (matrix[i][j] == '#')
        {
            return 0LL;
        }
    }

    return 1LL;
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    ll lines, col, n;
    string str;
    vector<string> matrix;

    cin >> lines >> col >> n;
    cin >> str;

    matrix.resize(lines);

    for (int i = 0; i < lines; i++)
    {
        cin >> matrix[i];
    }

    ll ans = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == '.')
            {
                ans += solve(matrix, str, i, j);
            }
        }
    }

    cout << ans << endl;


    return 0;
}