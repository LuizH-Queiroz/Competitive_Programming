#include <bits/stdc++.h>

#define endl '\n'
#define llu unsigned long long

#define MAXVAL 1'000'000

using namespace std;


llu freqBIT[MAXVAL + 1];
llu invBIT[MAXVAL + 1];


void update(int x, int delta, llu BIT[]) //add "delta" at index "x"
{
    for(; x <= MAXVAL + 1; x += x&-x)
          BIT[x] += delta;
}


llu query(int x, llu BIT[])//returns the sum of first x elements in given array a[]
{
    llu sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[x];
    return sum;
}


void compress(vector<int>& vals) {
    set<int> s;
    map<int, int> m;

    for (int i = 0; i < vals.size(); i++)
    {
        s.insert(vals[i]);
    }

    int nextVal = 1;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        m[*it] = nextVal;
        nextVal++;
    }

    for (int i = 0; i < vals.size(); i++)
    {
        vals[i] = m[vals[i]];
    }
}



int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int n;
    vector<int> vals;


    cin >> n;

    vals.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vals[i];
    }
    compress(vals);


    llu weakness = 0;
    for (int i = 0; i < n; i++)
    {
        weakness += query(MAXVAL, invBIT) - query(vals[i], invBIT);

        update(vals[i], query(MAXVAL, freqBIT) - query(vals[i], freqBIT), invBIT);
        update(vals[i], 1, freqBIT);
    }

    cout << weakness << endl;


    return 0;
}