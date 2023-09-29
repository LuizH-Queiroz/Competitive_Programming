/*
By now you have probably heard that there is a spectacular stone sculp- ture featuring four famous U.S.
presidents at Mount Rushmore. How- ever, very few people know that this monument contains a secret chamber.
This sounds like something out of a plot of a Hollywood movie, but the chamber really exists.
It can be found behind the head of Abraham Lincoln and was designed to serve as a Hall of Records to
store impor- tant historical U.S. documents and artifacts. Historians claim that the construction of
the hall was halted in 1939 and the uncompleted cham- ber was left untouched until the late 1990s,
but this is not the whole truth.

In 1982, the famous archaeologist S. Dakota Jones secretly visited the monument and found that the
chamber actually was completed, but it was kept confidential. This seemed suspicious and after some
poking around, she found a hidden vault and some documents inside. Unfortu- nately, these documents
did not make any sense and were all gibberish. She suspected that they had been written in a code,
but she could not decipher them despite all her efforts.

Earlier this week when she was in the area to follow the ACM-ICPC World Finals, Dr. Jones finally
discovered the key to deciphering the documents, in Connolly Hall of SDSM&T. She found a document that
contains a list of translations of letters. Some letters may have more than one translation,
and others may have no translation. By repeatedly applying some of these translations to individual
letters in the gibberish documents, she might be able to decipher them to yield historical U.S.
documents such as the Declaration of Independence and the Constitution. She needs your help.

You are given the possible translations of letters and a list of pairs of original and deciphered words.
Your task is to verify whether the words in each pair match. Two words match if they have the same
length and if each letter of the first word can be turned into the corresponding letter of the second
word by using the available translations zero or more times.

Input
The first line of input contains two integers m (1 ≤ m ≤ 500) and n (1 ≤ n ≤ 50),
where m is the number of translations of letters and n is the number of word pairs.
Each of the next m lines contains two distinct space-separated letters a and b, indicating that
the letter a can be translated to the letter b. Each ordered pair of letters (a, b) appears at most once.
Following this are n lines, each containing a word pair to check. Translations and words use only
lowercase letters ‘a’–‘z’, and each word contains at least 1 and at most 50 letters.

Output
For each pair of words, display "yes" if the two words match, and "no" otherwise.
*/
#include <iostream>
#include <vector>
#include <string>

#define endl "\n"

using namespace std;


vector<vector<bool>> validTranslation;
vector<vector<char>> entryList;
vector<bool> visited;


int Hash(char c) {
    return (c - 'a');
}


void dfs(char c, char translation) {
    visited[Hash(c)] = true;
    validTranslation[Hash(c)][Hash(translation)] = true;

    for (char entryAdjacent : entryList[Hash(c)])
    {
        if (!visited[Hash(entryAdjacent)])
        {
            dfs(entryAdjacent, translation);
        }
    }
}


bool match(string& word1, string& word2) {
    if (word1.size() != word2.size())
    {
        return false;
    }

    for (int i = 0; i < word1.size(); i++)
    {
        if (!validTranslation[Hash(word1[i])][Hash(word2[i])])
        {
            return false;
        }
    }

    return true;
}


int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int numTranslations, numWords;
    char a, b;
    string word1, word2;


    cin >> numTranslations >> numWords;
    validTranslation = vector<vector<bool>>(26, vector<bool>(26, false));
    entryList = vector<vector<char>>(26);

    for (int i = 0; i < numTranslations; i++)
    {
        cin >> a >> b;
        entryList[Hash(b)].push_back(a);
    }

    for (int i = 0; i < 26; i++)
    {
        visited = vector<bool>(26, false);
        dfs('a' + i, 'a' + i);
    }

    for (int i = 0; i < numWords; i++)
    {
        cin >> word1 >> word2;
        if (match(word1, word2))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }


    return 0;
}