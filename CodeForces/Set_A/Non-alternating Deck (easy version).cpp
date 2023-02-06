/*
This is an easy version of the problem. In this version, all cards have the same color.

Alice has n
 cards, each card is white, and the cards are stacked in a deck. Alice deals the cards to herself and to Bob,
 dealing at once several cards from the top of the deck in the following order: one card to herself, two cards to Bob,
 three cards to Bob, four cards to herself, five cards to herself, six cards to Bob, seven cards to Bob, eight cards to herself,
 and so on. In other words, on the i
-th step, Alice deals i
 top cards from the deck to one of the players; on the first step, she deals the cards to herself and then alternates the players
 every two steps. When there aren't enough cards at some step, Alice deals all the remaining cards, and the process stops.

First Alice's steps in a deck of many cards.
How many cards will Alice and Bob have at the end?

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤200
). The description of the test cases follows

The only line of each test case contains a single integer n
 (1≤n≤106
) — the number of cards.

Output
For each test case print two integers — the number of cards in the end for each player — in this order:
cards Alice has, cards Bob has.
*/

#include <iostream>

using namespace std;


int main() {
    int alice, bob, cards;
    int tests;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> cards;
        
        alice = 1; // Alice starts with 1 card
        bob = 0;
        cards--; // Reduce number of cards by one because Alice already got one

        bool aliceTurn = false;
        for (int j = 5; (cards - j) >= 0; j += 4) // amount of cards gained is always increased by 4
        {
            if (aliceTurn) alice += j;
            else bob += j;

            aliceTurn = !aliceTurn;
            cards -= j;
        }
        
        if (cards > 0)
        {
            if (aliceTurn) alice += cards;
            else bob += cards;
        }


        cout << alice << " " << bob << endl;
    }



    return 0;
}