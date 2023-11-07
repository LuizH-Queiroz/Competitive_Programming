#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    ///////////////////
    int tests;
    int lengthA, lengthB;
    int val;


    cin >> tests;
    while(tests--)
    {
        cin >> lengthA >> lengthB;

        queue<int> A;
        for (int i = 0; i < lengthA; i++)
        {
            cin >> val;
            A.push(val);
        }

        priority_queue<int> pq;
        for (int i = 0; i < lengthB; i++)
        {
            cin >> val;
            pq.push(val);
        }


        while(!A.empty() && !pq.empty())
        {
            while(!pq.empty() && pq.top() >= A.front())
            {
                cout << pq.top() << " ";
                pq.pop();
            }

            cout << A.front() << " ";
            A.pop();
        }

        while(!A.empty())
        {
            cout << A.front() << " ";
            A.pop();
        }
        while(!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }

        cout << endl;
    }


    return 0;
}