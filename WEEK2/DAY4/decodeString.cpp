class Solution {
public:
    string decodeString(string s) {
        stack<int> stk1;
        stack<string> stk2;
        string curr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) num = num*10 +(ch-'0');
            else if(ch=='[') {
                stk1.push(num);
                stk2.push(curr);
                num = 0;
                curr = "";
            }
            else if (ch==']') {
                int repeat = stk1.top();
                stk1.pop();
                string prev = stk2.top();
                stk2.pop();

                string temp = prev;
                while (repeat--) temp += curr;
                curr = temp;
            }
            else curr += ch;  
        }
        return curr;
    }
};