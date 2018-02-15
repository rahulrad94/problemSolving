/* Best time to buy and sell stock
 * Time: O(n)
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int localMax=prices[0],localMin=prices[0],maxInd=0,minInd=0, finalMax=0;

        for(int i=1;i<prices.size();i++){
            if(prices[i]>localMax){
                localMax = prices[i];
                maxInd = i;
            }

            if(prices[i]<localMin){
                localMin = prices[i];
                minInd = i;
            }

            if(maxInd<minInd){
                maxInd=-1;
                localMax=-1;
            } else {
                finalMax = max(finalMax, prices[maxInd]-prices[minInd]);
            }
        }
        return finalMax;
    }
};
