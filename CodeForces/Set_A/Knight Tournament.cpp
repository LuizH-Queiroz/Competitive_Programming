/*
Hooray! Berl II, the king of Berland is making a knight tournament. The king has already sent the message
to all knights in the kingdom and they in turn agreed to participate in this grand event.

As for you, you're just a simple peasant. There's no surprise that you slept in this morning and were late
for the tournament (it was a weekend, after all). Now you are really curious about the results of the
tournament. This time the tournament in Berland went as follows:

There are n knights participating in the tournament. Each knight was assigned his unique number — an integer
from 1 to n. The tournament consisted of m fights, in the i-th fight the knights that were still in the game
with numbers at least li and at most ri have fought for the right to continue taking part in the tournament.
After the i-th fight among all participants of the fight only one knight won — the knight number xi, he
continued participating in the tournament. Other knights left the tournament.
The winner of the last (the m-th) fight (the knight number xm) became the winner of the tournament.
You fished out all the information about the fights from your friends. Now for each knight you want to know
the name of the knight he was conquered by. We think that the knight number b was conquered by the
knight number a, if there was a fight with both of these knights present and the winner was the knight number a.

Write the code that calculates for each knight, the name of the knight that beat him.

Input
The first line contains two integers n, m (2 ≤ n ≤ 3·105; 1 ≤ m ≤ 3·105) — the number of knights and the number
of fights. Each of the following m lines contains three integers li, ri, xi (1 ≤ li < ri ≤ n; li ≤ xi ≤ ri) —
the description of the i-th fight.

It is guaranteed that the input is correct and matches the problem statement. It is guaranteed that at least
two knights took part in each battle.

Output
Print n integers. If the i-th knight lost, then the i-th number should equal the number of the knight that
beat the knight number i. If the i-th knight is the winner, then the i-th number must equal 0.
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ld long double
#define llu unsigned long long int


int main() {
    std::ios::sync_with_stdio(0);
    ////////////////////////
    int numKnights, numFights;
    int l, r, winner;
    set<int> knights;
    vector<int> conquered;
    vector<int> toErase;


    cin >> numKnights >> numFights;

    conquered.resize(numKnights+1, 0);
    for (int i = 1; i <= numKnights; i++)
    {
        knights.insert(i);
    }

    for (int i = 0; i < numFights; i++)
    {
        cin >> l >> r >> winner;

        for (set<int>::iterator it = knights.lower_bound(l); it != knights.end() && (*it) <= r; it++)
        {
            if ((*it) == winner)
                continue;
            
            conquered[(*it)] = winner;
            toErase.push_back((*it));
        }

        for (int i = 0; i < toErase.size(); i++)
        {
            knights.erase(toErase[i]);
        }

        toErase.clear();
    }


    cout << conquered[1];
    for (int i = 2; i <= numKnights; i++)
    {
        cout << " " << conquered[i];
    }
    cout << endl;


    return 0;
}