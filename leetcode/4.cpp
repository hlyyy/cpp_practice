class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        nums3.insert(nums3.end(),nums1.begin(),nums1.end());
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        int l = nums3.size();
        if (l%2 == 1)
            return double(nums3[(l-1)/2.0]);
        else
            return double((nums3[l/2]+nums3[l/2-1])/2.0);
    }
};