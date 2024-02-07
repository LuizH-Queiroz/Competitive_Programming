#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;

typedef long long ll;

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int tests;
    int n, m, k;
    int val;
    vector<int> freq;
    int unique1, unique2;
    int intersec;


    cin >> tests;
    while(tests--)
    {
        cin >> n >> m >> k;

        freq.resize(k+1, 0);

        unique1 = 0;
        unique2 = 0;
        intersec = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> val;
            if (val >= 1 && val <= k && freq[val] == 0)
            {
                freq[val]++;
                unique1++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            cin >> val;
            if (val >= 1 && val <= k)
            {
                if (freq[val] == 0)
                {
                    freq[val] = -1;
                    unique2++;
                }
                else if (freq[val] == 1)
                {
                    freq[val] = -1;
                    unique1--;
                    intersec++;
                }
            }
        }


        if ((unique1 + unique2 + intersec == k) && (unique1 + intersec >= k/2) && (unique2 + intersec >= k/2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }


        /////////////////////////////
        freq.clear();
    }



    return 0;
}