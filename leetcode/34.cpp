class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = nums.size();
        int low = 0,high = l-1;
        int mid;
        vector<int> v;
        if (l == 0 || nums[0]>target || nums[l-1]<target) {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        while (low < high) {
            mid = (low+high)/2;
            if (nums[mid] < target) 
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid -1;
            else 
                break;
        }
        if (low == high) {
            if (nums[low] != target){
                v.push_back(-1);
                v.push_back(-1);
                return v;
            }
            else {
                v.push_back(low);
                v.push_back(low);
                return v;
            }
        }
        while (nums[low] != target && low <= l-1)
            low++;
        while (nums[high] != target && high >= 0)
            high--;
        v.push_back(low);
        v.push_back(high);
        return v;
    }
};