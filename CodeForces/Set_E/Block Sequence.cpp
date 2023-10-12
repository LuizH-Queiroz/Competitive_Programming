#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    /////////////////////////
    int tests;
    int length;
    vector<int> vals;


    cin >> tests;
    while(tests--)
    {
        cin >> length;

        vals.resize(length);
        for (int i = 0; i < length; i++)
        {
            cin >> vals[i];
        }


        vector<int> dp(length+1);
        dp.back() = 0;

        for (int i = dp.size()-2; i >= 0; i--)
        {
            dp[i] = 1 + dp[i+1];
            if ((i+vals[i]+1) < dp.size())
            {
                dp[i] = min(dp[i], dp[i+vals[i]+1]);
            }
        }

        cout << dp[0] << endl;
    }


    return 0;
}