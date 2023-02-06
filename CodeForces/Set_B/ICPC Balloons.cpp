/*
In an ICPC contest, balloons are distributed as follows:

Whenever a team solves a problem, that team gets a balloon.
The first team to solve a problem gets an additional balloon.
A contest has 26 problems, labelled A, B, C, ..., Z. You are given the order of solved problems in the contest, denoted as a string s,
where the i-th character indicates that the problem si has been solved by some team. No team will solve the same problem twice.
Determine the total number of balloons that the teams received. Note that some problems may be solved by none of the teams.

Input
The first line of the input contains an integer t (1≤t≤100) — the number of testcases.

The first line of each test case contains an integer n (1≤n≤50) — the length of the string.

The second line of each test case contains a string s of length n consisting of uppercase English letters, denoting the order of solved problems.

Output
For each test case, output a single integer — the total number of balloons that the teams received.
*/


#include <iostream>
#include <set>

using namespace std;


int main() {
    set<char> solved;
    int tests;
    int length;
    string balloons;
    int totalBalloons;
    

    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        totalBalloons = 0;
        cin >> length >> balloons;

        for (char balloon : balloons)
        {
            if (solved.count(balloon) == 0)
            {
                totalBalloons += 2;
                solved.insert(balloon);
            }
            else
            {
                totalBalloons++;
            }
        }

        cout << totalBalloons << endl;
        solved.clear();
    }



    return 0;
}