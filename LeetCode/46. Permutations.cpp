/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/


class Solution {
public:
    vector<vector<int>> permutations;

    vector<vector<int>> permute(vector<int>& nums) {
        Rpermute(nums, 0);
        return permutations;
    }

    /*
    Recursively find all permutations.
    */
    void Rpermute(vector<int>& nums, int index) {

        // There's no more permutations but this one to include
        if (index == nums.size()-1)
        {
            permutations.push_back(nums);
            return;
        }

        // Find all permutations in which nums[index] value is actually swapped with nums[i], for i >= index.
        // This is how we can find all permutations when nums[index], nums[index-1], ..., nums[0]
        // have fixed values
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums, index, i);
            Rpermute(nums, index+1);
            swap(nums, index, i);
        }
    }

    void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
};