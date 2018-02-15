/* Product of all the numbers without self
 * Time: O(n)
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n==0) return res;

        res.assign(n,1);

        for(int i=n-2;i>=0;i--)
            res[i] = res[i+1] * nums[i+1];

        int left=1;
        for(int i=1;i<n;i++){
            left*=nums[i-1];
            res[i]*=left;
        }
        return res;
    }
};
