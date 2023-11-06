/*
Given an array a1,a2,…,an, you need to handle a total of q updates and queries of two types:
1 l r — for each index i with l≤i≤r, update the value of ai to the sum of the digits of ai.
2 x — output ax.

Input
The first line of the input contains an integer t (1≤t≤1000) — the number of testcases.

The first line of each test case contains two integers n and q (1≤n,q≤2⋅105) — the size of the array
and the number of queries, respectively.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109).

The next q lines of each test case are of two forms:
1 l r (1≤l≤r≤n) — it means, for each index i with l≤i≤r, you should update the value of ai to the sum of
its digits.
2 x (1≤x≤n) — it means you should output ax.

There is at least one query of the second type.

The sum of n over all test cases does not exceed 2⋅105.

The sum of q over all test cases does not exceed 2⋅105.

Output
For each test case, output the answers of queries of the second type, in the order they are given.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAXVAL 200'000

using namespace std;


int BIT[MAXVAL + 1];

void update(int x, int delta) //add "delta" at index "x"
{
    for(; x <= MAXVAL + 1; x += x&-x)
          BIT[x] += delta;
}


int query(int x)//returns the sum of first x elements in given array a[]
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}


int newVal(int n) {
    int sol = 0;

    while(n > 0)
    {
        sol += n%10;
        n /= 10;
    }

    return sol;
}



int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int tests;
    int arrSize, numQueries;
    int type, l, r, x;


    cin >> tests;
    while(tests--)
    {
        cin >> arrSize >> numQueries;

        memset(BIT, 0, sizeof BIT);
        int arr[arrSize+1];
        int updates[arrSize+1] = {0};
        for (int i = 1; i <= arrSize; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < numQueries; i++)
        {
            cin >> type;

            // Update
            if (type == 1)
            {
                cin >> l >> r;

                update(l, 1);
                if (r+1 <= arrSize)
                    update(r+1, -1);
            }
            // Output
            else
            {
                cin >> x;

                for (int counter = (query(x) - updates[x]); counter > 0 && arr[x] > 9; counter--)
                {
                    arr[x] = newVal(arr[x]);
                }

                cout << arr[x] << endl;
                updates[x] = query(x);
            }
        }
    }


    return 0;
}