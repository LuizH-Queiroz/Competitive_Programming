/*
There is a line that goes through the points p_1=(x_1,y_1) and p_2=(x_2,y_2). There is also a point p_3=(x_3,y_3).
Your task is to determine whether p_3 is located on the left or right side of the line or if it touches the line when
we are looking from p_1 to p_2.

Input
The first input line has an integer t: the number of tests.
After this, there are t lines that describe the tests. Each line has six integers: x_1, y_1, x_2, y_2, x_3 and y_3.

Output
For each test, print "LEFT", "RIGHT" or "TOUCH".
*/
#include <bits/stdc++.h>

#define endl '\n'

typedef long long ll;

using namespace std;


typedef struct Point {
    ll x, y;
};

/*
co * na = no * ca
*/
typedef struct Line {
    Point a, b;

    Line() {
        a = b = {0, 0};
    }

    Line(Point first, Point second) {
        a = first;
        b = second;
    }

    bool isAbove(Point p) {
        return ((p.y - a.y) * (b.x - a.x) > (b.y - a.y) * (p.x - a.x));
    }

    bool isOn(Point p) {
        return ((p.y - a.y) * (b.x - a.x) == (b.y - a.y) * (p.x - a.x));
    }
};



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ////////////////////////
    int tests;
    Line line;
    Point p;


    cin >> tests;
    while(tests--)
    {
        cin >> line.a.x >> line.a.y >> line.b.x >> line.b.y >> p.x >> p.y;

        if (line.isAbove(p))   cout << "LEFT" << endl;
        else if (line.isOn(p)) cout << "TOUCH" << endl;
        else                   cout << "RIGHT" << endl;
    }


    return 0;
}