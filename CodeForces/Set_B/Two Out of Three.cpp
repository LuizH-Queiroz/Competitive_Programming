#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int tests;
    int length;
    int val;
    map<int, queue<int>> mq;


    cin >> tests;
    while(tests--)
    {
        mq.clear();
        cin >> length;

        vector<int> ans(length);
        for (int i = 0; i < length; i++)
        {
            cin >> val;
            mq[val].push(i);
        }

        bool flag1 = false;
        bool flag2 = false;
        int nextComplement = 2;
        for (auto it = mq.begin(); it != mq.end(); it++)
        {
            queue<int>& q = it->second;
            if (q.size() >= 2)
            {
                flag2 = true;
                if (nextComplement == 2)
                {
                    nextComplement = 3;
                }
                else
                {
                    nextComplement = 2;
                    flag1 = true;
                }
            }

            ans[q.front()] = 1;
            q.pop();
            while(!q.empty())
            {
                ans[q.front()] = nextComplement;
                q.pop();
            }
        }


        if (!flag1 || !flag2)
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < length; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }



    return 0;
}