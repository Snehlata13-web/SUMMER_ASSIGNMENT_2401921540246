class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int>ans;
       int n = matrix.size();
       int m = matrix[0].size();
       int p1 = 0;
       int p2 = m-1;
       int p3 = n-1;
       int p4 = 0;
       while(p1 <= p2 && p4 <= p3)
       {
            for(int i = p4; i <= p2; i++)
            {
                ans.push_back(matrix[p1][i]);
            }
            p1++;
            for(int j = p1; j <= p3; j++)
            {
                ans.push_back(matrix[j][p2]);
            }
            p2--;

            if(p1 <= p3)
            {
                for(int j = p2; j >= p4; j--)
                {
                    ans.push_back(matrix[p3][j]);
                }
                p3--;
            }
            if(p4 <= p2)
            {
                for(int k = p3; k >= p1; k--)
                {
                    ans.push_back(matrix[k][p4]);
                }
                p4++;
            }
       }
       return ans;
    }
};