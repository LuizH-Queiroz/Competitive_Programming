/*
You are given n cubes in a certain order, and your task is to build towers using them.
Whenever two cubes are one on top of the other, the upper cube must be smaller than the lower cube.
You must process the cubes in the given order. You can always either place the cube on top of an existing tower,
or begin a new tower. What is the minimum possible number of towers?

Input
The first input line contains an integer n: the number of cubes.
The next line contains n integers k_1,k_2,...,k_n: the sizes of the cubes.

Output
Print one integer: the minimum number of towers.
Constraints

1 <= n <= 2 * 10^5
1 <= k_i <= 10^9
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int numCubes;
    int size;
    multiset<int> towers;


    cin >> numCubes;
    for (int i = 0; i < numCubes; i++)
    {
        cin >> size;

        if (towers.upper_bound(size) != towers.end())
        {
            towers.erase(towers.upper_bound(size));
        }
        towers.insert(size);
    }

    cout << towers.size() << endl;


    return 0;
}