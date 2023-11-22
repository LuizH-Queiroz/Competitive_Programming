/*
The famous knapsack problem. You are packing for a vacation on the sea side and you are going to carry only
one bag with capacity S (1 <= S <= 2000). You also have N (1<= N <= 2000) items that you might want to take
with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose.
For each item you are given its size and its value. You want to maximize the total value of all the items you
are going to bring. What is this maximum total value?

Input
On the first line you are given S and N. N lines follow with two integers on each line describing one
of your items. The first number is the size of the item and the next is the value of the item.

Output
You should output a single integer on one like - the total maximum value from the best choice of items
for your trip.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


typedef struct {
    int size;
    int value;
} Item;


vector<vector<int>> dp;
vector<Item> items;


int solve(int index, int size) {
    if (index == items.size() || size == 0)
    {
        return 0;
    }
    else if (dp[index][size] != -1)
    {
        return dp[index][size];
    }


    if (items[index].size <= size)
    {
        return dp[index][size] = max(
            items[index].value + solve(index+1, size - items[index].size),
            solve(index+1, size)
        );
    }
    return dp[index][size] = solve(index+1, size);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int numItems;
    int bagSize;


    cin >> bagSize >> numItems;

    items.resize(numItems+1);
    dp = vector<vector<int>>(numItems+1, vector<int>(bagSize+1, -1));

    for (int i = 1; i <= numItems; i++)
    {
        cin >> items[i].size >> items[i].value;
    }

    cout << solve(1, bagSize) << endl;


    return 0;
}