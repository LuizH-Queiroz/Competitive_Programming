/*
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0.
Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it,
denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i,
return true if you can visit all the rooms, or false otherwise.
*/


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int visitedCounter;
        queue<int> q;

        q.push(0);
        visited[0] = true;
        visitedCounter = 1;

        while(!q.empty())
        {
            for (int key : rooms[q.front()])
            {
                if (!visited[key])
                {
                    q.push(key);
                    visited[key] = true;
                    visitedCounter++;
                }
            }

            q.pop();
        }


        return visitedCounter == rooms.size();
    }
};