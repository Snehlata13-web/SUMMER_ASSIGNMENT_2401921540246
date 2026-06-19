class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            int currHeight=(i==n)?0:heights[i];
            while(!st.empty() &&currHeight<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                ans=max(ans,h*width);
            }
            st.push(i);
        }
        return ans;
    }
};