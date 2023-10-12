/*
(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.
If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.
Also, any solutions that attempt to circumvent the judge will result in disqualification.
*/


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int summit = summitIndex(mountainArr);
        int ans = bsearch_asc(0, summit, target, mountainArr);
        if (ans == -1)
            ans = bsearch_desc(summit, mountainArr.length()-1, target, mountainArr);
        
        return ans;
    }


    int bsearch_asc(int start, int end, int target, MountainArray &arr) {
        int middle;
        int val;

        while(start <= end)
        {
            middle = (start + end)/2;
            val = arr.get(middle);

            if (val < target)
                start = middle+1;
            else if (val > target)
                end = middle-1;
            else
                return middle;
        }

        return -1;
    }


    int bsearch_desc(int start, int end, int target, MountainArray &arr) {
        int middle;
        int val;

        while(start <= end)
        {
            middle = (start + end)/2;
            val = arr.get(middle);

            if (val > target)
                start = middle+1;
            else if (val < target)
                end = middle-1;
            else
                return middle;
        }

        return -1;
    }


    int summitIndex(MountainArray &arr) {
        int start = 0;
        int end = arr.length()-2;
        int middle;
        int summit = -1;
        int diff;

        while(start <= end)
        {
            middle = (start + end)/2;
            diff = arr.get(middle) - arr.get(middle+1);

            if (diff > 0)
            {
                summit = middle;
                end = middle-1;
            }
            else // diff < 0
            {
                start = middle+1;
            }
        }

        return summit;
    }
};