class Solution {
public:
    vector<int> findAnagrams(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> ans;
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0;i<n;i++) {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if (freq1 == freq2)ans.push_back(0);
        
        for (int i = n;i<m;i++) {
            freq2[s2[i]-'a']++;
            freq2[s2[i-n]-'a']--;
            if (freq1==freq2)ans.push_back(i-n+1);
        }

        return ans;
    }
};