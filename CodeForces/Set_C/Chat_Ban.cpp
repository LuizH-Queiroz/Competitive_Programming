/*
You are a usual chat user on the most famous streaming platform. Of course, there are
some moments when you just want to chill and spam something.

More precisely, you want to spam the emote triangle of size k. It consists of 2k−1 messages.
The first message consists of one emote, the second one — of two emotes, ..., the k-th one — of k emotes,
the k+1-th one — of k−1 emotes, ..., and the last one — of one emote.

For example, the emote triangle for k=3 consists of 5 messages:


Of course, most of the channels have auto moderation. Auto moderator of the current chat will ban you
right after you spam at least x emotes in succession (you can assume you are the only user in the chat).
Now you are interested — how many messages will you write before getting banned? Or maybe you will not
get banned at all (i.e. will write all 2k−1 messages and complete your emote triangle successfully)?
Note that if you get banned as a result of writing a message, this message is also counted.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤104) — the number of test cases.
The next t lines describe test cases.

The only line of the test case contains integers k and x (1≤k≤109;1≤x≤1018).

Output
For each test case, print the number of messages you will write before getting banned for
the corresponding values k and x.
*/


#include <iostream>
 
using namespace std;
 
 
bool PossibleToWrite(unsigned long long n_messages, unsigned long long triangle_size, unsigned long long n_ban);
 
 
int main(){
    int tests;
    unsigned long long triangle_size;
    unsigned long long n_ban;
    unsigned long long max_messages;
 
 
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> triangle_size >> n_ban;
 
        unsigned long long begin = 1;
        unsigned long long end = triangle_size * 2 - 1;
        unsigned long long middle;
 
        while (begin <= end)
        {
            middle = (begin + end) / 2;
 
            if (PossibleToWrite(middle-1, triangle_size, n_ban)){
                max_messages = middle;
                begin = middle + 1;
            }
            else {
                end = middle - 1;
            }
        }
 
 
        cout << max_messages << endl;
    }
 
 
 
    return 0;
}
 
 
bool PossibleToWrite(unsigned long long n_messages, unsigned long long triangle_size, unsigned long long n_ban){
    unsigned long long n_emotes;
 
    if (n_messages <= triangle_size){
        n_emotes = (1 + n_messages) * n_messages / 2;
    }
    else {
        //First part of the triangle: from 1 to triangle_size
        n_emotes = (1 + triangle_size) * triangle_size / 2;

        //Second part of the triangle: from (triangle_size - 1) to 1
        n_emotes +=  ((triangle_size - (n_messages - triangle_size)) + (triangle_size - 1)) * (n_messages - triangle_size) / 2;
    }
 
 
    return n_emotes < n_ban;
}