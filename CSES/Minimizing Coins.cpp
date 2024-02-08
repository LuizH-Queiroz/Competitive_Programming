#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "; " << #y << " = " << y << endl;

#define pii pair<int, int>
#define pll pair<ll, ll>

typedef long long ll;

const ll MOD = 10e9 + 7;

using namespace std;


const int UNDEFINED = -10;
const int IMPOSSIBLE = -1;

vector<int> coins;
vector<int> dp;


int solve(int sum) {
    if (sum < 0)
    {
        return IMPOSSIBLE;
    }
    else if (dp[sum] != UNDEFINED)
    {
        return dp[sum];
    }

    dp[sum] = IMPOSSIBLE;
    for (int val : coins)
    {
        int temp = solve(sum-val);
        if (temp != IMPOSSIBLE)
        {
            if (dp[sum] == IMPOSSIBLE) dp[sum] = 1 + temp;
            else dp[sum] = min(dp[sum], 1 + temp);
        }
    }

    return dp[sum];
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int n, sum;


    cin >> n >> sum;

    coins.resize(n);
    dp.resize(sum+1, UNDEFINED);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    dp[0] = 0;
    cout << solve(sum) << endl;


    return 0;
}