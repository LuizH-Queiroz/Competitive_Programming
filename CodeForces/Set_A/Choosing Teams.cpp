/*
The Saratov State University Olympiad Programmers Training Center (SSU OPTC) has n students. For each student you know the number of times
he/she has participated in the ACM ICPC world programming championship. According to the ACM ICPC rules, each person can participate in the
world championship at most 5 times.

The head of the SSU OPTC is recently gathering teams to participate in the world championship. Each team must consist of exactly three people,
at that, any person cannot be a member of two or more teams. What maximum number of teams can the head make if he wants each team to participate
in the world championship with the same members at least k times?

Input

The first line contains two integers, n and k (1 ≤ n ≤ 2000; 1 ≤ k ≤ 5). The next line contains n integers: y1, y2, ..., yn (0 ≤ yi ≤ 5),
where yi shows the number of times the i-th person participated in the ACM ICPC world championship.

Output

Print a single number — the answer to the problem.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    int students;
    int participations;
    int teams = 0;
    vector<int> vec;


    cin >> students >> participations;
    vec.resize(students);
    for (int i = 0; i < students; i++)
        cin >> vec[i];

    
    sort(vec.begin(), vec.end());
    for (int i = 2; i < students; i += 3)
    {
        if ((vec[i] + participations) <= 5)
            teams++;
        else
            break;
    }

    cout << teams << endl;



    return 0;
}