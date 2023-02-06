/*
There are one cat, k mice, and one hole on a coordinate line. The cat is located at the point 0,
the hole is located at the point n. All mice are located between the cat and the hole: the i-th mouse
is located at the point xi (0<xi<n). At each point, many mice can be located.

In one second, the following happens. First, exactly one mouse moves to the right by 1.
If the mouse reaches the hole, it hides (i.e. the mouse will not any more move to any point and
will not be eaten by the cat). Then (after that the mouse has finished its move) the cat moves
to the right by 1. If at the new cat's position, some mice are located, the cat eats them (they will not
be able to move after that). The actions are performed until any mouse hasn't been hidden or isn't eaten.

In other words, the first move is made by a mouse. If the mouse has reached the hole, it's saved.
Then the cat makes a move. The cat eats the mice located at the pointed the cat has reached
(if the cat has reached the hole, it eats nobody).

Each second, you can select a mouse that will make a move. What is the maximum number of mice that
can reach the hole without being eaten?

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case consists of two lines. The first line contains two integers n and k (2≤n≤109, 1≤k≤4⋅105).
The second line contains k integers x1,x2,…xk (1≤xi<n) — the initial coordinates of the mice.

It is guaranteed that the sum of all k given in the input doesn't exceed 4⋅105.

Output
For each test case output on a separate line an integer m (m≥0) — the maximum number of mice that
can reach the hole without being eaten.
*/


#include <iostream>
#include <algorithm>
 
using namespace std;
 
 
int LastIndex(int arr[], int arr_length , int wanted);
int FirstIndex(int arr[], int arr_length , int wanted);
 
 
int main(){
    int tests;
    int hole, n_mice;
 
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> hole >> n_mice;
        int mouse[n_mice];
 
        for (int j = 0; j < n_mice; j++)
            cin >> mouse[j];
        sort(mouse, mouse + n_mice);
 
        int cat_position = 0;
        int saved_mice = 0;
        int firstIndex, lastIndex;
        for (int j = n_mice - 1; j >= 0 && cat_position < mouse[j]; j = firstIndex - 1)
        {
            lastIndex = LastIndex(mouse, n_mice, mouse[j]);
            firstIndex = FirstIndex(mouse, n_mice, mouse[j]);
 
            if ((cat_position + ((unsigned long long) lastIndex - firstIndex + 1) * (hole - mouse[j])) < mouse[j])
            {
                saved_mice += lastIndex - firstIndex + 1;
                cat_position += (lastIndex - firstIndex + 1) * (hole - mouse[j]);
            }
            else
            {
                saved_mice += (hole - cat_position - 1) / (hole - mouse[j]);
                cat_position = mouse[j];
            }
        }
 
 
        cout << saved_mice << endl;
    }
 
 
 
    return 0;
}
 
 
int LastIndex(int arr[], int arr_length , int wanted){
    int begin = 0;
    int end = arr_length - 1;
    int middle;
    int lastIndex;
 
    while (begin <= end)
    {
        middle = (begin + end) / 2;
 
        if (arr[middle] == wanted){
            lastIndex = middle;
            begin = middle + 1;
        }
        else if (arr[middle] < wanted){
            begin = middle + 1;
        }
        else { //arr[middle] > wanted
            end = middle - 1;
        }
    }
 
    return lastIndex;
}
 
int FirstIndex(int arr[], int arr_length , int wanted){
    int begin = 0;
    int end = arr_length - 1;
    int middle;
    int firstIndex;
 
    while (begin <= end)
    {
        middle = (begin + end) / 2;
 
        if (arr[middle] == wanted){
            firstIndex = middle;
            end = middle - 1;
        }
        else if (arr[middle] < wanted){
            begin = middle + 1;
        }
        else { //arr[middle] > wanted
            end = middle - 1;
        }
    }
 
    return firstIndex;
}