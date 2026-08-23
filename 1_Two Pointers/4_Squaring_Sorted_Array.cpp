/**
977. Squares of a Sorted Array
Solved
Easy
Topics
premium lock icon
Companies
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.


Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> negVec;
        vector<int> posVec;
        for (int num : nums) {
            if (num >= 0) {
                posVec.push_back(num);
            } else {
                negVec.push_back(num);
            }
        }
        vector<int> finalVec;
        if (negVec.size() == 0) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = nums[i] * nums[i];
            }
            return nums;
        }

        else if (posVec.size() == 0) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i] = nums[i] * nums[i];
            }
            reverse(nums.begin(), nums.end());
            return nums;
        }

        else {
            int p1 = 0;
            int p2 = 0;
            int negSize = negVec.size();
            int posSize = posVec.size();
            reverse(negVec.begin(), negVec.end());
            while (p1 < negSize && p2 < posSize) {
                int sqp1 = negVec[p1] * negVec[p1];
                int sqp2 = posVec[p2] * posVec[p2];
                if (sqp1 < sqp2) {
                    finalVec.push_back(sqp1);
                    p1++;
                } else {
                    finalVec.push_back(sqp2);
                    p2++;
                }
            }

            while (p1 < negSize) {
                finalVec.push_back(negVec[p1] * negVec[p1]);
              p1++;
            }

            while (p2 < posSize) {
                finalVec.push_back(posVec[p2] * posVec[p2]);
                p2++;
            }
        }
        return finalVec;
    }
};