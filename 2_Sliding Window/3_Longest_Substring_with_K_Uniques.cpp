// You are given a string s consisting only lowercase alphabets and an integer k. 
// Your task is to find the length of the longest substring that contains exactly k distinct characters.

// Note : If no such substring exists, return -1. 

// Examples:

// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.


class Solution {
	public:
	int longestKSubstr(string &s, int k) {
		int low = 0;
		int high = 0;
		int longestSubstring = -1;
		unordered_map<char, int> freqMap;
		while (high < s.size()) {
			freqMap[s[high]]++;
			
			if (freqMap.size() == k) {
				longestSubstring = max(longestSubstring, high - low + 1);
			}
			
			
			while (freqMap.size() > k) {
				freqMap[s[low]]--;
				if (freqMap[s[low]] == 0) {
					freqMap.erase(s[low]);
				}
				low++;
			}
			high++;
		}
		return longestSubstring;
		
	}
};
