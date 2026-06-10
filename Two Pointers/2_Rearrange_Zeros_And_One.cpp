class Solution {
	public:
	void segregate0and1(vector<int> &arr) {
		int pointer1 = 0;
		int pointer2 = arr.size() - 1;
		while (pointer1 < pointer2) {
			if (arr[pointer1] == 0) {
				pointer1++;
			}
			else if (arr[pointer1] == 1 && arr[pointer2] == 0) {
				arr[pointer2] = 1;
				arr[pointer1] = 0;
				pointer1++;
				pointer2 --;
			}
			else if (arr[pointer1] == 1 && arr[pointer2] == 1) {
				pointer2--;
			}
		}
	}
};
