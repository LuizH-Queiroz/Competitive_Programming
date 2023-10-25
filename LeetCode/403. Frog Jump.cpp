/*
A frog is crossing a river. The river is divided into some number of units, and at each unit,
there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross
the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first
jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can
only jump in the forward direction.
*/


class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;

        set<long long> position;
        set<pair<long long, int>> cannot;

        function<bool(int, int)> possible;
        possible = [&](int pos, int k) {
            if (pos == stones.back())
                return true;
            else if (cannot.find({pos, k}) != cannot.end())
                return false;

            
            for (auto it = position.lower_bound(pos+(k-1)); it != position.end() && (*it) <= (pos+(k+1)); it++)
            {
                if ((*it) != pos && possible((*it), (*it) - pos))
                {
                    return true;
                }
            }

            cannot.insert({pos, k});
            return false;
        };


        for (int i = 1; i < stones.size(); i++)
            position.insert(stones[i]);
        
        return possible(1, 1);
    }
};