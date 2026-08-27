// Given an array of positive integers nums and a positive integer target, 
// return the minimal length of a subarray whose sum is greater than or equal to target.
//  If there is no such subarray, return 0 instead.

 

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int sum = 0;
        int minimumSubArLeng = 0;
        while (high < nums.size()) {
            sum += nums[high];
            while (sum >= target) {
                minimumSubArLeng = minimumSubArLeng > 0
                                       ? min(minimumSubArLeng, (high - low + 1))
                                       : (high - low + 1);
                sum -= nums[low];
                low++;
            }

            high++;
        }
        return minimumSubArLeng;
    }
};