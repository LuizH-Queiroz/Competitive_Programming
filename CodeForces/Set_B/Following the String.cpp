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
    int length;
    vector<int> vec;
    string ans;
    map<int, queue<char>> m;

    
    cin >> tests;
    while(tests--)
    {
        cin >> length;

        vec.resize(length);
        ans.resize(length);

        for (int i = 0; i < length; i++)
        {
            cin >> vec[i];
        }

        for (char c = 'a'; c <= 'z'; c++)
        {
            m[0].push(c);
        }

        for (int i = 0; i < length; i++)
        {
            ans[i] = m[vec[i]].front();
            m[vec[i]+1].push(ans[i]);
            m[vec[i]].pop();
        }

        cout << ans << endl;
        ///////////////////////
        m.clear();
    }



    return 0;
}