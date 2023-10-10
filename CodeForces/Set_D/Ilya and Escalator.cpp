/*
Ilya got tired of sports programming, left university and got a job in the subway.
He was given the task to determine the escalator load factor.

Let's assume that n people stand in the queue for the escalator. At each second one of the two following
possibilities takes place: either the first person in the queue enters the escalator with probability p,
or the first person in the queue doesn't move with probability (1 - p), paralyzed by his fear of escalators
and making the whole queue wait behind him.

Formally speaking, the i-th person in the queue cannot enter the escalator until people with indices from
1 to i - 1 inclusive enter it. In one second only one person can enter the escalator.
The escalator is infinite, so if a person enters it, he never leaves it, that is he will be standing on
the escalator at any following second. Ilya needs to count the expected value of the number of people
standing on the escalator after t seconds.

Your task is to help him solve this complicated task.

Input
The first line of the input contains three numbers n, p, t (1 ≤ n, t ≤ 2000, 0 ≤ p ≤ 1).
Numbers n and t are integers, number p is real, given with exactly two digits after the decimal point.

Output
Print a single real number — the expected number of people who will be standing on the escalator
after t seconds. The absolute or relative error mustn't exceed 10 - 6.
*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>

#define endl "\n"

using namespace std;


int main() {
    vector<vector<long double>> dp;
    long double p;
    int n, t;

    cin >> n >> p >> t;
    dp = vector<vector<long double>>(n+1, vector<long double>(t+1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= t; i++)
    {
        dp[0][i] = dp[0][i-1] * (1-p);
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (i < n)
            {
                dp[i][j] = dp[i][j-1] * (1-p) + dp[i-1][j-1]*p;
            }
            else
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1]*p;
            }
        }
    }


    long double expectancy = 0;
    for (int i = 1; i <= n; i++)
    {
        expectancy += i * dp[i][t];
    }

    cout << fixed << setprecision(6) << expectancy << endl;


    return 0;
}