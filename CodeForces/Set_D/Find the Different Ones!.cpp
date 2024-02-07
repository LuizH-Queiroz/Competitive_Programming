#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;

typedef long long ll;

using namespace std;


vector<int> vec;
vector<int> prevDiff;


int find(int val, int index) {
    if (index <= 0)
    {
        return -1;
    }
    else if (vec[index] != val)
    {
        return index;
    }
    else
    {
        return prevDiff[index];
    }
}



int main() {
    ios::sync_with_stdio(0);
    // cin.tie(0);
    ////////////////////////
    int tests;
    int n, q;
    int l, r;


    cin >> tests;
    while(tests--)
    {
        cin >> n;

        vec.resize(n+1);
        prevDiff.resize(n+1);

        for (int i = 1; i <= n; i++)
        {
            cin >> vec[i];
            prevDiff[i] = find(vec[i], i-1);
        }

        cin >> q;

        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;

            if (prevDiff[r] < l)
            {
                cout << -1 << " " << -1 << endl;
            }
            else
            {
                cout << prevDiff[r] << " " << r << endl;
            }
        }
    }



    return 0;
}