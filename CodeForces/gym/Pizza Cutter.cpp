/*
Grandpa Giuseppe won a professional pizza cutter, the kind of type reel and, to celebrate, baked a
rectangle pizza to his grandchildren! He always sliced his pizzas into pieces by making cuts over continuous
lines, not necessarily rectilinear, of two types: some begin at the left edge of the pizza, follow
continuously to the right and end up in the right edge; other start on lower edge, follow continuously
up and end up on the top edge. But Grandpa Giuseppe always followed a property: two cuts of the same type
would never intersect. Here is an example with 4 cuts, two of each type, in the left part of the figure,
which divide the pizza in 9 pieces.


It turns out that Grandpa Giuseppe simply loves geometry, topology, combinatorics and stuff; so, he decided
to show to his grandchildren who could get more pieces with the same number of cuts if cross cuts of the
same type were allowed. The right part of the figure shows, for example, that if the two cuts of the type
that go from left to right could intercept, the pizza would be divided into 10 pieces.

Grandpa Giuseppe ruled out the property, but will not make random cuts.
In addition to being one of the two types, they will comply with the following restrictions:

Two cuts have at most one intersection point and, if they have, it is because the cuts cross each other
at that point;
Three cuts do not intersect in a single point;
Two cuts do not intersect at the border of the pizza;
A cut does not intercept a pizza corner.
Given the start and end points of each cut, your program should compute the number of resulting pieces
from the cuts of Grandfather Giuseppe.

Input
The first line of the input contains two integers X and Y, (1≤X,Y≤109), representing the coordinates (X,Y)
of the upper-right corner of the pizza. The lower left corner has always coordinates (0,0).
The second line contains two integers H and V, (1≤H,V≤105),
indicating, respectively, the number of cuts ranging from left to right and the number of cuts ranging
from bottom to top. Each of the following lines H contains two integers Y1 and Y2,
a cut that intercepts the left side with y-coordinate Y1 and the right side at y-coordinate Y2.
Each of the following V lines contains two integers X1 and X2,
a cut that intercept the bottom side at x-coordinate X1 and the upper side at x-coordinate X2.
*/
#include <bits/stdc++.h>

#define endl '\n'
#define llu unsigned long long

#define MAXVAL 100'000

using namespace std;

///////////////////////////////////////////////////////////
llu BIT[MAXVAL + 1];


void update(int x, llu delta) //add "delta" at index "x"
{
    for(; x <= MAXVAL + 1; x += x&-x)
        BIT[x] += delta;
}


llu query(int x)//returns the sum of first x elements in given array a[]
{
     llu sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}
///////////////////////////////////////////////////////////


vector<pair<llu, llu>> points;
llu solve() {
    llu sol = 0;

    memset(BIT, 0, sizeof BIT);
    // cout << "BIT[0] = " << BIT[0] << endl;
    // cout << "BIT[1] = " << BIT[1] << endl;
    // cout << "BIT[2] = " << BIT[2] << endl;
    for (int i = 0; i < points.size(); i++)
    {
        sol += query(MAXVAL) - query(points[i].second);

        update(points[i].second, 1);
    }

    return sol;
}


void compress() {
    set<llu> s;
    map<llu, llu> m;

    for (int i = 0; i < points.size(); i++)
    {
        s.insert(points[i].second);
    }

    llu nextVal = 1;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        m[*it] = nextVal;
        nextVal++;
    }

    for (int i = 0; i < points.size(); i++)
    {
        points[i].second = m[points[i].second];
    }
}


int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    pair<llu, llu> upperRight;
    llu numHorizontal, numVertical;
    llu pieces = 0;


    cin >> upperRight.first >> upperRight.second;
    cin >> numHorizontal >> numVertical;

    pieces = (numHorizontal+1LLU) * (numVertical+1LLU);

    points.resize(numHorizontal);
    for (int i = 0; i < numHorizontal; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    compress();
    pieces += solve();

    points.resize(numVertical);
    for (int i = 0; i < numVertical; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    compress();
    pieces += solve();

    cout << pieces << endl;

    return 0;
}