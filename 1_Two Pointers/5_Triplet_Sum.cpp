
//1. Triplet Sum to Zero (medium)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            int j= i+1;
            int k = nums.size() - 1;
            int remainingSumRequired = -nums[i];
        if(i > 0 && nums[i-1] == nums[i]){
             continue;
            }
               while(j < k) {
              int sum = nums[j] + nums[k];
              if(sum == remainingSumRequired){
                result.push_back({nums[i], nums[j], nums[k]});

                while(j<k && nums[j+1] == nums[j]){
                    j++;
                }

                while(j<k && nums[k-1] == nums[k]){
                    k--;
                }

                j++;
                k--;
              }
              else if (sum < remainingSumRequired) {
                j++;
              }
              else{
                k--;
              }
            }
        }  
        
        return result;
    }
};

//2. Triplet Sum Close to Target (medium)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int resSum = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (abs(target - sum) < closest) {
                    closest = abs(target - sum);
                    resSum = sum;
                }

                if (sum == target) {
                    return resSum;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return resSum;
    }
};


//3. Triplet Sum Smaller than Target (medium)

class Solution {
	public:
	int countTriplets(int sum, vector<int>& arr) {
	    sort(arr.begin(), arr.end());
		int count = 0;
		for (int i = 0; i< arr.size() - 2; i++) {
			int j = i + 1;
			int k = arr.size() - 1;
			while (j < k) {
				int calculatedSum = arr[i] + arr[j] + arr[k];
				if (calculatedSum < sum) {
					count += k - j;
					j++;
				}
				
			    else {
					k--;
				}
			}
		}
		return count;
	}
};
 