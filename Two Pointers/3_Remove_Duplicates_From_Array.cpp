/**
Leetcode 26. Remove Duplicates from Sorted Array
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pointer1 = 0;
        int pointer2 = 1;
        int k = 1;
        while(pointer2 < nums.size()){
           if(nums[pointer2] > nums[pointer1])
            {
                int temp = nums[pointer2];
                nums[pointer2] =  nums[pointer1 + 1];
                nums[pointer1 + 1] = temp;
                pointer1++;
                pointer2++;
                k++;
            }
            else { 
                pointer2++;
            }
        }
        return k;
    }
};

/**
Leetcode 80. Remove Duplicates From Sorted Array With 2 repitions (medium)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pointer1 = 0;
        int pointer2 = 1;
        int count = 1;
        int ele = 1;
        while (pointer2 < nums.size()) {
            if (nums[pointer2] == nums[pointer1] && count == 1) {
                int temp = nums[pointer2];
                nums[pointer2] = nums[pointer1 + 1];
                nums[pointer1 + 1] = temp;
                pointer1++;
                ele++;
                count++;
            } else if (nums[pointer2] > nums[pointer1]) {
                int temp = nums[pointer2];
                nums[pointer2] = nums[pointer1 + 1];
                nums[pointer1 + 1] = temp;
                pointer1++;
                ele++;
                count = 1;
            }
            pointer2++;
        }
        return ele;
    }
};