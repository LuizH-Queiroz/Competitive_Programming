/*
Given an array of integers arr, return true if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i + 1 < j with (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ...
+ arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])
*/


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = vectorSum(arr);
        if (totalSum % 3 != 0)
            return false;

        int currentSum = 0;
        int counter = 0;


        for (int i = 0; i < arr.size(); i++)
        {
            currentSum += arr[i];
            if (currentSum == totalSum/3)
            {
                currentSum = 0;
                counter++;
            }
        }

        return (counter >= 3);
    }

    int vectorSum(vector<int>& arr) {
        int sum = 0;

        for (int i = 0; i < arr.size(); i++)
            sum += arr[i];

        return sum;
    }
};