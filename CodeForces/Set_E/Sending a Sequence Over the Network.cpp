/*
The sequence a is sent over the network as follows:

sequence a is split into segments (each element of the sequence belongs to exactly one segment, each segment
is a group of consecutive elements of sequence);
for each segment, its length is written next to it, either to the left of it or to the right of it;
the resulting sequence b is sent over the network.
For example, we needed to send the sequence a=[1,2,3,1,2,3].
Suppose it was split into segments as follows: [1]+[2,3,1]+[2,3]. Then we could have the following sequences:

b=[1,1,3,2,3,1,2,3,2],
b=[1,1,3,2,3,1,2,2,3],
b=[1,1,2,3,1,3,2,2,3],
b=[1,1,2,3,1,3,2,3,2].
If a different segmentation had been used, the sent sequence might have been different.

The sequence b is given. Could the sequence b be sent over the network? In other words, is there
such a sequence a that converting a to send it over the network could result in a sequence b?

Input
The first line of input data contains a single integer t (1≤t≤104) — the number of test cases.

Each test case consists of two lines.

The first line of the test case contains an integer n (1≤n≤2⋅105) — the size of the sequence b.

The second line of test case contains n integers b1,b2,…,bn (1≤bi≤109) — the sequence b itself.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case print on a separate line:

YES if sequence b could be sent over the network, that is, if sequence b could be obtained from
some sequence a to send a over the network.
NO otherwise.
You can output YES and NO in any case (for example, strings yEs, yes, Yes and YES will be recognized as
positive response).
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int tests;
    int size;
    vector<int> arr;
    vector<bool> possible;


    cin >> tests;
    while(tests--)
    {
        cin >> size;

        arr.resize(size);
        possible = vector<bool>(size, false);

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }


        for (int i = arr.size()-1; i >= 0; i--)
        {            
            if (i+arr[i] < arr.size() && ((i+arr[i]+1) >= arr.size() || possible[i+(arr[i]+1)]))
                possible[i] = true;
            
            if ((i+1 >= arr.size() || possible[i+1]) && i-arr[i] >= 0)
                possible[i-arr[i]] = true;
        }

        if (possible[0])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    return 0;
}