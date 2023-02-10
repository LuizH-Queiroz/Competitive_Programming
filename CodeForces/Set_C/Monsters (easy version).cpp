/*
In a computer game, you are fighting against n
 monsters. Monster number i
 has ai
 health points, all ai
 are integers. A monster is alive while it has at least 1
 health point.

You can cast spells of two types:

1 - Deal 1 damage to any single alive monster of your choice.
2 - Deal 1 damage to all alive monsters. If at least one monster dies (ends up with 0 health points) as a result of
this action, then repeat it (and keep repeating while at least one monster dies every time). Dealing 1 damage to
a monster reduces its health by 1.

Spells of type 1 can be cast any number of times, while a spell of type 2 can be cast at most once during the game.

What is the smallest number of times you need to cast spells of type 1 to kill all monsters?

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

Each test case consists of two lines. The first line contains a single integer n
 (1≤n≤2⋅105
) — the number of monsters.

The second line contains n
 integers a1,a2,…,an
 (1≤ai≤n
) — monsters' health points.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the smallest number of times you need to cast spells of type 1 to kill all monsters.
*/

#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int numberMonsters;
    unsigned long long minSpells;
    int tests;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> numberMonsters;

        int health[numberMonsters];
        for (int j = 0; j < numberMonsters; j++)
        {
            cin >> health[j];
        }

        sort(health, health+numberMonsters);
        minSpells = health[0] - 1; // For the monster health points to be equal to 1
        health[0] = 1;
        for (int j = 1; j < numberMonsters; j++)
        {
            minSpells += max(0, (health[j] - health[j-1]) - 1);
            health[j] = min(health[j], health[j-1] + 1);
        }

        cout << minSpells << endl;
    }



    return 0;
}