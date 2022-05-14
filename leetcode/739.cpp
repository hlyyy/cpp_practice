class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int l = temperatures.size();
        vector<int> res(l,0);
        for (int i = l-2; i >= 0; i--) {
            int index = 1;
            while(index + i < l) {
                if (temperatures[i] < temperatures[i+index]) 
                    break;
                else if (res[i+index]) 
                    index += res[i+index];
                else {
                    index = 0;
                    break;
                }
            }
            res[i] = index;
        }
        return res;
    }
};