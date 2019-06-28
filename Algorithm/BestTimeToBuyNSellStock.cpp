/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int i = 0;
        int j = i+1;
        int maxP = 0;
        int l = prices.size();
        
        while(j < l){
            if(prices[i] <= prices[j]){
                int t = prices[j] - prices[i];
                if(t > maxP){
                    maxP = t;
                }
                
                if(j != l-1){
                    if(prices[i] > prices[j+1]){
                        i = j+1;
                        j = i+1;
                    } else {
                        j++;
                    }
                } else break;
            } else{
                i++;
                j++;
            }
        }
        return maxP;
    }
};
