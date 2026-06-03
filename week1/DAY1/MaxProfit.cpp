class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi =prices[0];
        int prof=0;
        for(int i =1;i<prices.size();i++){
            int curr  = prices[i]-maxi;
            prof = max(curr,prof);
            maxi = min(prices[i],maxi);
        }
        return prof;

    }
};