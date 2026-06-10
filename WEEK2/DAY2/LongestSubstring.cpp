
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0, l = 0, n = s.size(), ans = 0;
        vector<int> hash(256, -1);
        while(r<n) {
            if(hash[s[r]]!= -1 && hash[s[r]]>=l) {
                l = hash[s[r]] + 1;
            }
            ans = max(ans, r-l+1);
            hash[s[r]]=r;
            r++;
        }
        return ans;
    }
};