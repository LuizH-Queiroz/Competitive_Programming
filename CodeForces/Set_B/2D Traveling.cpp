/*
Piggy lives on an infinite plane with the Cartesian coordinate system on it.

There are n
 cities on the plane, numbered from 1
 to n
, and the first k
 cities are defined as major cities. The coordinates of the i
-th city are (xi,yi)
.

Piggy, as a well-experienced traveller, wants to have a relaxing trip after Zhongkao examination. Currently, he is in city a
, and he wants to travel to city b
 by air. You can fly between any two cities, and you can visit several cities in any order while travelling, but the final destination must be city b
.

Because of active trade between major cities, it's possible to travel by plane between them for free. Formally, the price of an air ticket f(i,j)
 between two cities i
 and j
 is defined as follows:

f(i,j)={0,|xi−xj|+|yi−yj|,if cities i and j are both major citiesotherwise
Piggy doesn't want to save time, but he wants to save money. So you need to tell him the minimum value of the total cost of all air tickets if he can take any number of flights.

Input
The first line of input contains a single integer t
 (1≤t≤104
) — the number of test cases. The description of test cases follows.

The first line of each test case contains four integers n
, k
, a
 and b
 (2≤n≤2⋅105
, 0≤k≤n
, 1≤a,b≤n
, a≠b
) — the number of cities, the number of major cities and the numbers of the starting and the ending cities.

Then n
 lines follow, the i
-th line contains two integers xi
 and yi
 (−109≤xi,yi≤109
) — the coordinates of the i
-th city. The first k
 lines describe major cities. It is guaranteed that all coordinates are pairwise distinct.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a single integer — the minimum value of the total price of all air tickets.
*/
#include <iostream>
#include <algorithm>
#include <vector>

#define endl "\n";

using namespace std;


struct Coord {
    signed long long int x;
    signed long long int y;
};


signed long long int Distance(Coord a, Coord b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}


int main() {
    ios::sync_with_stdio(0);
    int tests;
    int n_cities, n_major, from, destination;
    vector<Coord> majorCities;
    Coord a, b;
    Coord aux;
    signed long long int minCost, minCost_aToMajor, minCost_bToMajor;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> n_cities >> n_major >> from >> destination;
        majorCities.resize(n_major);
        for (int j = 1; j <= n_cities; j++)
        {
            cin >> aux.x >> aux.y;
            if (j <= n_major)
            {
                majorCities[j-1] = aux;
            }

            if (j == from)
            {
                a = aux;
            }
            else if (j == destination)
            {
                b = aux;
            }
        }


        minCost = Distance(a, b);
        if (n_major > 0)
        {
            minCost_aToMajor = Distance(a, majorCities[0]);
            minCost_bToMajor = Distance(b, majorCities[0]);

            for (int j = 1; j < majorCities.size(); j++)
            {
                minCost_aToMajor = min(minCost_aToMajor, Distance(a, majorCities[j]));
                minCost_bToMajor = min(minCost_bToMajor, Distance(b, majorCities[j]));
            }

            minCost = min(minCost, minCost_aToMajor + minCost_bToMajor);
        }
        cout << minCost << endl;
    }


    return 0;
}