class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = nums.size();
        int v[l];
        int sum = 0;
        for (int i = 0; i < l; i++) {
            if (nums[i] == 0) 
                sum++;
            else
                nums[i-sum] = nums[i];
        }
        for (int i = l-1; i > l-1-sum ; i--)
            nums[i] = 0;
    }
};