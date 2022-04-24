class Solution {
public:
    vector<string> res;
    string s;
    map<char,string> m{
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    void DFS(int i,string digits,int l) {
        if (i == l) {
            res.push_back(s);
            return;
        }
        string str = m[digits[i]];
        for (int j = 0; j < str.size(); j++) {
            s += str.substr(j,1);
            DFS(i+1,digits,l);
            s = s.substr(0,s.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        int l = digits.size();
        if (l == 0)
            return res;
        DFS(0,digits,l);
        return res;
    }
};