/*
Finally, the exhausting exams are behind you, and the time has come to relish a well-deserved vacation away
from the college hustle. With your bags neatly packed, you set out for an adventure to explore one of the
most renowned mountains in your region – a destination you've been dreaming of visiting for a considerable
period.

This majestic mountain boasts impressive dimensions and offers a plethora of hiking options. Comprising a
total of N landmarks, each uniquely identified by a number ranging from 1 to N,
the mountain presents a captivating network of N−1 interconnected paths. These pathways ensure that you
can effortlessly traverse from any landmark to another, connecting the entire mountain in a seamless web.

Each landmark, denoted by the index i, possesses an associated score, aptly named vi.
This score reflects the expected number of likes your social media post of that landmark would attract.
Brimming with enthusiasm, you've decided to infuse an extra layer of excitement into your hike by embracing
the "photos hype challenge". In this challenge, your objective is nothing short of extraordinary: capture and
post photos in a manner that guarantees each successive photo garners more likes than its predecessor.

The rules of this challenge dictate your journey to unfold as follows:

You commence your hike from landmark 1.
Progressing along the available paths, you navigate through the landmarks, always moving forward and never
backtracking.
At each landmark you visit, you are presented with the choice of capturing a photo and posting it on your
social media platform.
As your journey unfolds, you're curious about the potential outcomes. Specifically, for every landmark i,
you seek to determine the maximum number of photos that can be posted if you initiate the hike from
landmark 1 and conclude at landmark i (although you not necessarily took a photo of landmark i).
The challenge is to strategically select the landmarks to capture photos, ensuring that each photo
outshines its predecessor in terms of expected likes.

Your task is to calculate this maximum number of photos for each landmark. Can you rise to the challenge
and uncover the most captivating and likable path through this mountain?

Input
The first line contains an integer N (1≤N≤105), representing the number of landmarks in the mountain.
The second line contains N−1 integers p2,p3,…,pN (1≤pi≤N), where pi represents that there is a path between
the landmarks i and pi. The third line contains N integers v1,v2,…,vN (1≤vi≤109), where vi
represents the expected number of likes a photo of the i-th landmark would get.

Output
Output a single line with N−1 integers, where the i-th integer represents the maximum number of photos
you can post if you start the hike on landmark 1 and finish on landmark (i+1).
*/
#include <bits/stdc++.h>

#define endl '\n'
#define MAXN 100'000

using namespace std;


vector<vector<int>> adjacencyList;
vector<bool> visited;
vector<int> likes;
vector<int> vertexMax;

//Declara a segtree. O parâmetro 'MAXN' deve ser substituído pelo tamanho do array
//que dará origem à segTree
int t[4*MAXN];


//retorna a soma dos elementos no intervalo l e r do array original
int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm))
           , query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


//faz um update no equivalente de segTree ao índice 'pos' no array
//original com o valor 'new_val'
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}


void compress() {
    set<int> s;
    map<int, int> m;

    for (int i = 1; i < likes.size(); i++)
        s.insert(likes[i]);

    int nextVal = 1;
    for (auto it = s.begin(); it != s.end(); it++)
        m[*it] = nextVal++;

    for (int i = 1; i < likes.size(); i++)
        likes[i] = m[likes[i]];
}


void dfs(int vertex, int tempMax) {
    visited[vertex] = true;
    int prevVal = query(1, 1, likes.size()-1, likes[vertex], likes[vertex]);


    update(1, 1, likes.size()-1, likes[vertex], max(prevVal, 1 + query(1, 1, likes.size()-1, 1, likes[vertex]-1)));
    tempMax = max(tempMax, query(1, 1, likes.size()-1, likes[vertex], likes[vertex]));
    vertexMax[vertex] = tempMax;

    for (int adjacent : adjacencyList[vertex])
    {
        if (!visited[adjacent])
        {
            dfs(adjacent, tempMax);
        }
    }


    update(1, 1, likes.size()-1, likes[vertex], prevVal);
}


int main() {
    ios::sync_with_stdio(0);
    ////////////////////////
    int landmarks;
    int vertex;


    cin >> landmarks;

    adjacencyList.resize(landmarks+1);
    visited.resize(landmarks+1, false);
    likes.resize(landmarks+1);
    vertexMax.resize(landmarks+1);

    for (int i = 2; i <= landmarks; i++)
    {
        cin >> vertex;
        adjacencyList[i].push_back(vertex);
        adjacencyList[vertex].push_back(i);
    }

    for (int i = 1; i <= landmarks; i++)
    {
        cin >> likes[i];
    }
    compress();

    dfs(1, 0);
    for (int i = 2; i <= landmarks; i++)
    {
        cout << vertexMax[i] << " ";
    }
    cout << endl;


    return 0;
}