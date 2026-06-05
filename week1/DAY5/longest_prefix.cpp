class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string s = strs[0];
        int m = s.size();
        int cnt = 0;
        string ans = "";
        int val = 0;
        while(m > 0){
            val = 0;
            for(int j = 0; j < n; j++)
            {
                string p = strs[j];
                if(p[cnt] ==  s[cnt]){
                    val++;
                }
                else return ans;
                if(j == n-1 && val == n){
                    ans += p[cnt];
                }
            } 
            cnt++;
            m--;
        }
        return ans;
    }
};


