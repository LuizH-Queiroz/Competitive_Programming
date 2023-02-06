/*
Businessman Divan loves chocolate! Today he came to a store to buy some chocolate. Like all businessmen,
Divan knows the value of money, so he will not buy too expensive chocolate. At the same time, too cheap
chocolate tastes bad, so he will not buy it as well.

The store he came to has n different chocolate bars, and the price of the i-th chocolate bar is ai dollars.
Divan considers a chocolate bar too expensive if it costs strictly more than r dollars. Similarly,
he considers a bar of chocolate to be too cheap if it costs strictly less than l dollars. Divan will not
buy too cheap or too expensive bars.

Divan is not going to spend all his money on chocolate bars, so he will spend at most k dollars
on chocolates.

Please determine the maximum number of chocolate bars Divan can buy.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100).
Description of the test cases follows.

The description of each test case consists of two lines. The first line contains integers
n, l, r, k (1≤n≤100, 1≤l≤r≤109, 1≤k≤109) — the lowest acceptable price of a chocolate, the highest
acceptable price of a chocolate and Divan's total budget, respectively.

The second line contains a sequence a1,a2,…,an (1≤ai≤109) integers — the prices of chocolate bars
in the store.

Output
For each test case print a single integer — the maximum number of chocolate bars Divan can buy.
*/


#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    short int tests;
    short int n_chocolate_bars;
    int lowest_price, highest_price;
    int divan_money;
    int can_buy; //Number of chocolate bars Divan can buy in each test case


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> n_chocolate_bars >> lowest_price >> highest_price >> divan_money;

        can_buy = 0;
        int bar_price[n_chocolate_bars];

        for (int j = 0; j < n_chocolate_bars; j++)
            cin >> bar_price[j];
        sort(bar_price, bar_price + n_chocolate_bars);


        for (int j = 0; j < n_chocolate_bars; j++)
        {
            if (bar_price[j] <= divan_money && lowest_price <= bar_price[j] && bar_price[j] <= highest_price)
            {
                divan_money -= bar_price[j];
                can_buy++;

                if (divan_money == 0) break;
            }
        }


        cout << can_buy << endl;
    }



    return 0;
}