class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> res;
        for (int i = 1; i < nums[0]; i++) 
            res.push_back(i);
        for (int i = 0; i < l-1; i++) {
            if (nums[i+1] - nums[i] > 1) {
                for (int j = nums[i]+1; j < nums[i+1]; j++)
                    res.push_back(j);
            }
        }
        for (int i = nums[l-1]+1; i <= l; i++) 
            res.push_back(i);
        return res;
    }
};