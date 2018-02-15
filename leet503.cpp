/* Next greater element in a circular array
 * Time : O(n)
 * Sopace : O(n)
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n,0);

        if(!n) return res;

        stack<int> st;

        st.push(nums[n-1]);
        res[n-1] = -1;

        for(int i=n-2;i>=0;i--){
            while( !st.empty() && st.top()<nums[i] ) st.pop();

            if(st.empty())
                res[i]=-1;
            else
                res[i] = st.top();

            st.push(nums[i]);
        }

        for(int i=n-1;i>=0;i--){
            while( !st.empty() && st.top()<=nums[i] ) st.pop();

            if(st.empty())
                res[i]=-1;
            else
                res[i] = st.top();
            st.push(nums[i]);
        }
        return res;
    }
};
