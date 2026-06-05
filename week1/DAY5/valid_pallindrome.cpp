class Solution {
public:
    bool isPalindrome(string s) {
       string ans = "";
       for(int i = 0; i < s.size(); i++){
            if(s[i] >= 65 && s[i] <= 90 ){
                ans += s[i] + 32;
            }
            else if(s[i] >= 97 && s[i] <= 122 || (s[i] >= '0' && s[i] <= '9')){
                ans += s[i];
            }
       }
       cout<<ans<<endl;
       int n = ans.size();
       for(int i = 0; i < n/2; i++)
       {
            if(ans[i] != ans[n-i-1])return false;
       }
       return true;
    }
};