class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = nums.size();
        int n = 0;
        while(n < l && nums[n] == 0) 
            n++;
        for (int i = l-1; i > n; i--) {
            if (nums[i] == 0) {
                nums[i] += nums[n];
                nums[n] = nums[i] - nums[n];
                nums[i] -= nums[n];
                while(nums[n] == 0) 
                    n++;
            }
        }
        while(n < l &&nums[n] == 1) 
            n++;
        for (int i = l-1; i > n; i--) {
            if (nums[i] == 1) {
                nums[i] += nums[n];
                nums[n] = nums[i] - nums[n];
                nums[i] -= nums[n];
                while(nums[n] == 1) 
                    n++;
            }
        }
    }
};