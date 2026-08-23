// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700
// Explanation: arr2 + arr3 = 700, which is maximum.


class Solution {
	public:
	int maxSubarraySum(vector<int>& arr, int k) {
		int low = 0;
		int high = k - 1;
		int max = 0;
		
		for (int i = low; i <= high; i++) {
			max += arr[i];
		}
		
		int currentWindowSum = max;
		
		while (high < arr.size() - 1) {
			low++;
			high++;
			int newWindowSum = currentWindowSum - arr[low - 1] + arr[high];
			if (newWindowSum > max) {
				max = newWindowSum;
			}
			currentWindowSum = newWindowSum;
		}
		return max;
	}
};
