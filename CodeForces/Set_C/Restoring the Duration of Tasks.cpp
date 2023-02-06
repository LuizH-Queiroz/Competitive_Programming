/*
Recently, Polycarp completed n successive tasks.

For each completed task, the time si is known when it was given, no two tasks were given at the same time.
Also given is the time fi when the task was completed. For each task, there is an unknown value di (di>0) — duration of task execution.

It is known that the tasks were completed in the order in which they came. Polycarp performed the tasks as follows:

As soon as the very first task came, Polycarp immediately began to carry it out.
If a new task arrived before Polycarp finished the previous one, he put the new task at the end of the queue.
When Polycarp finished executing the next task and the queue was not empty, he immediately took a new task
from the head of the queue (if the queue is empty — he just waited for the next task).
Find di (duration) of each task.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The descriptions of the input data sets follow.

The first line of each test case contains one integer n (1≤n≤2⋅105).

The second line of each test case contains exactly n integers s1<s2<⋯<sn (0≤si≤109).

The third line of each test case contains exactly n integers f1<f2<⋯<fn (si<fi≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each of t test cases print n positive integers d1,d2,…,dn — the duration of each task.
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;



int main() {
    queue<int> receptionTime, completionTime;
    int tests;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int numberOfTasks;
        int val;

        cin >> numberOfTasks;

        // Time the tasks were given
        for (int j = 0; j < numberOfTasks; j++)
        {
            cin >> val;
            receptionTime.push(val);
        }
        // Time the tasks were completed
        for (int j = 0; j < numberOfTasks; j++)
        {
            cin >> val;
            completionTime.push(val);
        }


        // Calculate each task time (and print)
        int prevCompletion = 0;
        for (int j = 0; j < numberOfTasks; j++)
        {
            prevCompletion = max(prevCompletion, receptionTime.front());

            cout << completionTime.front() - prevCompletion;
            if (j < numberOfTasks-1) cout << " ";
            else cout << endl;

            prevCompletion = completionTime.front();

            receptionTime.pop();
            completionTime.pop();
        }
    }



    return 0;
}