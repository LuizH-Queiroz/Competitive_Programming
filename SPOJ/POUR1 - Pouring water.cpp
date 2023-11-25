/*
Given two vessels, one of which can accommodate a litres of water and the other - b litres of water,
determine the number of steps required to obtain exactly c litres of water in one of the vessels.

At the beginning both vessels are empty. The following operations are counted as 'steps':

emptying a vessel,
filling a vessel,
pouring water from one vessel to the other, without spilling, until one of the vessels is either full or empty.
Input
An integer t, 1<=t<=100, denoting the number of testcases, followed by t sets of input data, each consisting
of three positive integers a, b, c, not larger than 40000, given in separate lines.

Output
For each set of input data, output the minimum number of steps required to obtain c litres, or -1 if this
is impossible.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


set<pair<int, int>> visited;
int maxV1, maxV2, target;


int bfs() {
    queue<pair<int, pair<int, int>>> q;
    int cost;
    pair<int, int> node;
    pair<int, int> temp;


    function<void()> verify;
    verify = [&]() {
        if (visited.find(temp) == visited.end())
        {
            q.push({cost+1, temp});
            visited.insert(temp);
        }
    };


    q.push({0, {0, 0}});
    visited.insert({0, 0});
    while(!q.empty())
    {
        cost = q.front().first;
        node = q.front().second;
        q.pop();

        if (node.first == target || node.second == target)
            return cost;
        
        temp = {0, node.second};
        verify();

        temp = {maxV1, node.second};
        verify();

        temp = {max(0, node.first-(maxV2-node.second)), min(node.first+node.second, maxV2)};
        verify();

        temp = {node.first, 0};
        verify();

        temp = {node.first, maxV2};
        verify();

        temp = {min(node.first+node.second, maxV1), max(0, node.second-(maxV1-node.first))};
        verify();
    }

    return -1;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int tests;

    cin >> tests;
    while(tests--)
    {
        cin >> maxV1 >> maxV2 >> target;


        if (target > maxV1 && target > maxV2)
        {
            cout << -1 << endl;
        }
        else
        {
            visited.clear();
            cout << bfs() << endl;
        }
    }


    return 0;
}