/*
Mart'in has a board of 1×N squares. He also has N tiles of 1×1,1×2,…,1×N squares, one of each type.
He has placed one of the tiles on the board. His friend, Nico, wants to place some of the remaining
tiles in such a way that as many squares as possible are covered. How many squares will remain empty
if he succeeds?

Tiles placed on the board cannot overlap each other. Besides, each placed tile must be located
completely within the board and must cover whole squares.

Input
The input consists of a single line that contains three integers N (1≤N≤1000), K (1≤K≤N) and E (0≤E≤N−K),
indicating that the board has 1×N squares, and a tile of 1×K squares is placed leaving E empty squares
to its left.

Output
Output a single line with an integer indicating the number of squares that will remain empty
if Nico covers as many squares as possible with the remaining tiles.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


vector<bool> used;

int solve(int size) {
    if (!used[size])
    {
        used[size] = true;
        return size;
    }

    for (int i = 1; i < size; i++)
    {
        if (!used[i] && !used[size-i] && i != (size-i))
        {
            used[i] = used[size-i] = true;
            return size;
        }
    }

    int temp = size;
    int count = 0;
    for (int i = size-1; i >= 1; i--)
    {
        if (!used[i] && i <= temp)
        {
            used[i] = true;
            count += i;
            temp -= i;
        }
    }

    return count;
}


int main() {
    int numSquares, tileWidth, left, right;
    int remainder1, remainder2;
    vector<bool> usedTemp;


    cin >> numSquares >> tileWidth >> left;
    
    used = vector<bool>(numSquares+10, false);
    used[tileWidth] = true;
    right = numSquares - (tileWidth + left);
    remainder1 = numSquares - tileWidth;
    remainder2 = numSquares - tileWidth;

    usedTemp = used;
    remainder1 -= solve(max(left, right));
    remainder1 -= solve(min(left, right));

    used = usedTemp;
    remainder2 -= solve(min(left, right));
    remainder2 -= solve(max(left, right));
    

    cout << min(remainder1, remainder2) << endl;


    return 0;
}