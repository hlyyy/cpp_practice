class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size();
        if (l == 1)
            return;
        int i = l-1,j = 0,k = l-1;
        int swap = 0;
        for (;i > 0; i--) {
            if (nums[i-1] < nums[i]) 
                break;
            if (i == 1) {
                sort(nums.begin(),nums.end());
                return;
            }
        }
        j = i-1;
        for (; k > j; k--) {
            if (nums[k] > nums[j]) {
                swap = nums[k];
                nums[k] = nums[j];
                nums[j] = swap;
                break;
            }
        }
        vector<int>::iterator it = nums.begin();
        it += i;
        sort(it,nums.end());
    }
};