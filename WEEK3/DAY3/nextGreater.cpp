#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        for (int i =0;i<=n;i++) {
            if (i==n || s[i]==' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
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
class Solution {
public:
    vector<string> ans;
    void backtrack(string curr, int open, int close, int n) {
        if (curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n) {
            backtrack(curr+"(",open+1,close,n);
        }
        if(close<open) {
            backtrack(curr+")",open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str:strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto &it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
        string s ="";
        int cnt =1;
        for(int i = 1;i<chars.size();i++){
            if(chars[i]!=chars[i-1]){
                s+=chars[i-1];
                if(cnt>1) s += to_string(cnt);
                cnt=1;
                
            }
            else cnt++;
        }
        s += chars.back();
        if (cnt > 1) s += to_string(cnt);
        for (int i = 0; i < s.size(); i++) chars[i] = s[i];
        return s.size();
        
    }
};

class Solution {
public:
    string expand(string &s, int left, int right) {
        while (left>= 0 && right<s.size() && s[left]==s[right]) {
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }

    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }

        string maxStr = s.substr(0, 1);
        for (int i = 0; i < s.size() - 1; i++) {
            string odd = expand(s,i,i);
            string even = expand(s,i,i+1);

            if(odd.size()>maxStr.size()) {
                maxStr = odd;
            }
            if(even.size()>maxStr.size()) {
                maxStr = even;
            }
        }

        return maxStr;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow==fast) return true;
        }
        return false;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;

        for(int i=0;i<=n;i++) fast = fast->next;

        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy.next;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }

        int l=0,r=v.size()-1;
        while(l<r){
            if(v[l++]!=v[r--]) return false;
        }

        return true;
    }
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else{
                if(st.empty()) return false;
                if(c==')' && st.top()!='(') return false;
                if(c=='}' && st.top()!='{') return false;
                if(c==']' && st.top()!='[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
class MinStack {
public:
    stack<int> st,minSt;
    MinStack() {}
    void push(int val) {
        st.push(val);
        if(minSt.empty() || val<=minSt.top()) minSt.push(val);
    }

    void pop() {
        if(st.top()==minSt.top()) minSt.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1,vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i])st.pop();
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int x:nums1) ans.push_back(mp[x]);

        return ans;
    }
};