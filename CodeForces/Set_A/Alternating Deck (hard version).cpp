/*
This is a hard version of the problem. In this version, there are two colors of the cards.

Alice has n
 cards, each card is either black or white. The cards are stacked in a deck in such a way that the card colors alternate,
 starting from a white card. Alice deals the cards to herself and to Bob, dealing at once several cards from the top of the
 deck in the following order: one card to herself, two cards to Bob, three cards to Bob, four cards to herself, five cards to herself,
 six cards to Bob, seven cards to Bob, eight cards to herself, and so on. In other words, on the i
-th step, Alice deals i
 top cards from the deck to one of the players; on the first step, she deals the cards to herself and then alternates the players
 every two steps. When there aren't enough cards at some step, Alice deals all the remaining cards to the current player,
 and the process stops.

First Alice's steps in a deck of many cards.
How many cards of each color will Alice and Bob have at the end?

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤200
). The description of the test cases follows

The only line of each test case contains a single integer n
 (1≤n≤106
) — the number of cards.

Output
For each test case print four integers — the number of cards in the end for each player — in this order: white cards Alice has,
black cards Alice has, white cards Bob has, black cards Bob has.
*/

#include <iostream>

using namespace std;


struct AmountOfCards {
    int white;
    int black;
};


int main() {
    AmountOfCards alice, bob;
    int cards, tests;


    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> cards;

        alice.white = 1; // Alice starts with one white card
        alice.black = bob.white = bob.black = 0;
        cards--; // Alice already got one card

        bool aliceTurn = false;
        int white = 2, black = 3;
        while (cards - (white + black) >= 0)
        {
            if (aliceTurn)
            {
                alice.white += white;
                alice.black += black;
            }
            else
            {
                bob.white += white;
                bob.black += black;
            }

            aliceTurn = !aliceTurn;
            cards -= white + black;

            if (white > black)
            {
                black += 3;
                white += 1;
            }
            else
            {
                white += 3;
                black += 1;
            }
        }

        bool whiteTurn = white > black;
        while (cards > 0)
        {
            if (aliceTurn)
            {
                if (whiteTurn) alice.white++;
                else alice.black++;
            }
            else
            {
                if (whiteTurn) bob.white++;
                else bob.black++;
            }

            whiteTurn = !whiteTurn;
            cards--;
        }


        cout << alice.white << " " << alice.black << " " << bob.white << " " << bob.black << endl;
    }



    return 0;
}