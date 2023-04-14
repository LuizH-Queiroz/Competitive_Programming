/*
Polycarpus has a ribbon, its length is n. He wants to cut the ribbon in a way that fulfils the following two conditions:

    After the cutting each ribbon piece should have length a, b or c.
    After the cutting the number of ribbon pieces should be maximum. 

Help Polycarpus and find the number of ribbon pieces after the required cutting.
Input

The first line contains four space-separated integers n, a, b and c (1 ≤ n, a, b, c ≤ 4000) — the length of the original ribbon and
the acceptable lengths of the ribbon pieces after the cutting, correspondingly. The numbers a, b and c can coincide.
Output

Print a single number — the maximum possible number of ribbon pieces. It is guaranteed that at least one correct ribbon cutting exists.
*/
#include <iostream>
#include <algorithm>

using namespace std;



int main() {
    int ribbon_size, size[3];

    cin >> ribbon_size >> size[0] >> size[1] >> size[2];
    int max_pieces[ribbon_size+1] = {0};

    for (int i = ribbon_size-1; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i + size[j] < ribbon_size && max_pieces[i + size[j]] != 0) || (i + size[j] == ribbon_size))
                max_pieces[i] = max(max_pieces[i], 1 + max_pieces[i + size[j]]);
        }
    }

    cout << max_pieces[0] << endl;


    return 0;
}