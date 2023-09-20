/*
You are given two integers n and k. You are also given an array of integers a1,a2,…,an of size n.
It is known that for all 1≤i≤n, 1≤ai≤k.

Define a two-dimensional array b of size n×n as follows: bi,j=min(ai,aj).
Represent array b as a square, where the upper left cell is b1,1,
rows are numbered from top to bottom from 1 to n, and columns are numbered from left to right from 1 to n.
Let the color of a cell be the number written in it (for a cell with coordinates (i,j), this is bi,j).

For each color from 1 to k, find the smallest rectangle in the array b containing all cells of
this color. Output the sum of width and height of this rectangle.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.
Then follows the description of the test cases.

The first line of each test case contains two integers n and k (1≤n,k≤105) — the size of
array a and the number of colors.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤k) — the array a.

It is guaranteed that the sum of the values of n and k over all test cases does not exceed 10^5.

Output
For each test case, output k numbers: the sums of width and height of the smallest rectangle containing
all cells of a color, for each color from 1 to k.
*/
#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"

using namespace std;
 

int main() {
    ios::sync_with_stdio(false);
    ////////////
    vector<vector<int>> valsIndex;
    vector<bool> used;
    priority_queue<int, vector<int>, greater<int>> pq;
    int size, maxVal;
    int aux;
    int lowerRow, upperRow;
    int tests;


    cin >> tests;
    while(tests--)
    {
        cin >> size >> maxVal;
        used = vector<bool>(size+1, false);
        valsIndex = vector<vector<int>>(maxVal+1, vector<int>());

        for (int i = 1; i <= size; i++)
        {
            cin >> aux;

            if (valsIndex[aux].empty())
            {
                pq.push(aux);
            }
            valsIndex[aux].push_back(i);
        }


        vector<int> ans(maxVal+1, 0);
        lowerRow = 1;
        upperRow = size;
        while(!pq.empty())
        {
            aux = pq.top();
            pq.pop();


            while(lowerRow <= size && used[lowerRow])
            {
                lowerRow++;
            }
            while(upperRow >= 1 && used[upperRow])
            {
                upperRow--;
            }

            ans[aux] = 2*(upperRow - lowerRow + 1);
            for (int index : valsIndex[aux])
            {
                used[index] = true;
            }
        }

        cout << ans[1];
        for (int i = 2; i < ans.size(); i++)
        {
            cout << " " << ans[i];
        }
        cout << endl;
    }


    return 0;
}