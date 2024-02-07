#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()

#define debug(x) cout << #x << " = " << x << endl;

typedef long long ll;

using namespace std;


int findFirst(string &str) {

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'B')
        {
            return i;
        }
    }

    return -1;
}


int findLast(string &str) {
    
    for (int i = str.size()-1; i >= 0; i--)
    {
        if (str[i] == 'B')
        {
            return i;
        }
    }

    return -1;
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int tests;
    string str;
    int length;


    cin >> tests;
    while(tests--)
    {
        cin >> length;
        cin >> str;

        int first = findFirst(str);
        int last = findLast(str);

        if (first != -1) cout << (last - first + 1) << endl;
        else cout << 0 << endl;
    }


    return 0;
}