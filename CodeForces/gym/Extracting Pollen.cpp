/*
Spring has arrived, ushering in a season of hard work at the Swarm of Bees Company (SBC).
With the blooming of N beautiful flowers in the garden, each flower boasts a certain quantity of
pollen grains. The SBC enforces strict rules to keep the bees industrious in their pollen collection.

The first rule pertains to the amount of pollen grains collected: when a bee visits a flower,
it must gather the sum of the digits in its current pollen quantity. For instance, if a bee visits a flower
with 123 pollen grains, it must collect 1+2+3=6 grains, leaving the flower with 123−6=117
grains. Similarly, if the flower holds 201 grains, the bee must gather 2+0+1=3 grains, leaving 198 grains
remaining.

All bees must form a queue at the start of the day; the bee at the front of the queue must collect pollen
from one of the flowers with the largest amount pollen. If a bee visits a flower with 0 grains of pollen,
it collects zero grains. After collecting pollen from a flower, the bee ends its shift and returns to the
hive. Gertrude finds these rules bewildering and seeks help to determine the pollen amount she must
collect when it's her turn. Getrude has amazingly sharp sight and noticed that she is currently the K-th
bee in the SBC-defined order.

Input
The first line contains two integers N (1≤N≤106) and K (1≤K≤109), representing the number of flowers and
Gertrude's position in the bee line, respectively. The second line contains N integers, where the
i-th integer Fi (1≤Fi≤106 for 1≤i≤N) denotes the initial quantity of pollen grains of the i-th flower.

Output
Output a single integer Q representing the amount of pollen Gertrude will collect.
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int nextPollen(int n) {
    int sum = 0;
    int temp = n;

    while(temp > 0)
    {
        sum += temp%10;
        temp /= 10;
    }

    return n - sum;
}


int main() {
    ios::sync_with_stdio(0);
    ///////////////////////
    int numFlowers, position;
    int pollen;
    vector<int> flowers;


    cin >> numFlowers >> position;

    flowers.resize(1'000'001, 0);
    for (int i = 0; i < numFlowers; i++)
    {
        cin >> pollen;
        flowers[pollen]++;
    }


    int gertrude = 0;
    for (int i = 1'000'000; i >= 1; i--)
    {
        if (position <= flowers[i])
        {
            gertrude = i - nextPollen(i);
            break;
        }

        flowers[nextPollen(i)] += flowers[i];
        position -= flowers[i];
    }

    cout << gertrude << endl;


    return 0;
}