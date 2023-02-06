/*
The School №0 of the capital of Berland has n children studying in it. All the children in this school
are gifted: some of them are good at programming, some are good at maths, others are good at
PE (Physical Education). Hence, for each child we know value ti:

ti = 1, if the i-th child is good at programming,
ti = 2, if the i-th child is good at maths,
ti = 3, if the i-th child is good at PE
Each child happens to be good at exactly one of these three subjects.

The Team Scientific Decathlon Olympias requires teams of three students. The school teachers decided that
the teams will be composed of three children that are good at different subjects. That is, each team must
have one mathematician, one programmer and one sportsman. Of course, each child can be a member of no more
than one team.

What is the maximum number of teams that the school will be able to present at the Olympiad? How should
the teams be formed for that?

Input
The first line contains integer n (1 ≤ n ≤ 5000) — the number of children in the school. The second line
contains n integers t1, t2, ..., tn (1 ≤ ti ≤ 3), where ti describes the skill of the i-th child.

Output
In the first line output integer w — the largest possible number of teams.

Then print w lines, containing three numbers in each line. Each triple represents the indexes of
the children forming the team. You can print both the teams, and the numbers in the triplets in any order.
The children are numbered from 1 to n in the order of their appearance in the input. Each child must
participate in no more than one team. If there are several solutions, print any of them.

If no teams can be compiled, print the only line with value w equal to 0.
*/


#include <iostream>
#include <vector>

using namespace std;


enum { PROGRAMMER, MATHEMATICIAN, SPORTSMAN };


int main(){
    int n_children;
    int children_gift;
    vector< vector<int> > gift(3);
    int max_teams;


    cin >> n_children;
    for (int i = 1; i <= n_children; i++)
    {
        cin >> children_gift;

        if (children_gift == 1) gift[PROGRAMMER].push_back(i);
        else if (children_gift == 2) gift[MATHEMATICIAN].push_back(i);
        else gift[SPORTSMAN].push_back(i);
    }


    max_teams = gift[0].size();
    for (int i = 1; i < gift.size(); i++)
    {
        if (gift[i].size() < max_teams){
            max_teams = gift[i].size();
        }
    }


    cout << max_teams << endl;
    for (int i = 0; i < max_teams; i++)
    {
        cout << gift[PROGRAMMER][i] << " " << gift[MATHEMATICIAN][i] << " " << gift[SPORTSMAN][i] << endl;
    }
    



    return 0;
}