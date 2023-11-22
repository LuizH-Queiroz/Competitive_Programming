/*
There are N hotels along the beautiful Adriatic coast. Each hotel has its value in Euros.

Sroljo has won M Euros on the lottery. Now he wants to buy a sequence of consecutive hotels,
such that the sum of the values of these consecutive hotels is as great as possible - but not greater than M.

You are to calculate this greatest possible total value.

Input
In the first line of the input there are integers N and M (1 ≤ N ≤ 300 000, 1 ≤ M < 231).

In the next line there are N natural numbers less than 106, representing the hotel values in the order
they lie along the coast.

Output
Print the required number (it will be greater than 0 in all of the test data).
*/
#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int numHotels;
    vector<ll> cost;
    ll lottery;


    cin >> numHotels >> lottery;

    cost.resize(numHotels);
    for (int i = 0; i < numHotels; i++)
    {
        cin >> cost[i];
    }

    ll maxCost = 0;
    ll currCost = 0;
    queue<ll> q;
    for (int i = 0; i < numHotels; i++)
    {
        q.push(cost[i]);
        currCost += cost[i];

        while(currCost > lottery)
        {
            currCost -= q.front();
            q.pop();
        }

        maxCost = max(maxCost, currCost);
    }

    cout << maxCost << endl;


    return 0;
}