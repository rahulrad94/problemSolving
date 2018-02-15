/* Longest consecutive sequence
 * Time: O(n)
 * Space : O(n)
 * Using Set
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;

        int maxlen=-1;
        set<int> s;
        for(int i=0;i<n;i++)
            s.insert(nums[i]);

        for(int i=0;i<n;i++){

            if(s.count(nums[i])!=0){
                s.erase(nums[i]);

                int temp = nums[i];
                temp++;
                int counter_l=0;
                while(s.count(temp)!=0){
                    counter_l++;
                    s.erase(temp);
                    temp++;
                }

                temp = nums[i];
                temp--;
                int counter_r=0;
                while(s.count(temp)!=0){
                    counter_r++;
                    s.erase(temp);
                    temp--;
                }

                if(maxlen<counter_r+counter_l+1)
                    maxlen=counter_r+counter_l+1;
            }
        }

        return maxlen;
    }
};
