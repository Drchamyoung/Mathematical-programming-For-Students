class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(0);
        
        int size = prices.size();
        if(size == 0) return 0;

        int first_buy = INT_MIN , first_sell = 0;
        int sec_buy = INT_MIN , sec_sell = 0;

        for(int i : prices) {
            first_buy = max(first_buy,-i);
            first_sell = max(first_sell,i + first_buy);

            sec_buy = max(sec_buy,first_sell - i);
            sec_sell = max(sec_sell,sec_buy + i);
        }

        return sec_sell;
    }
};