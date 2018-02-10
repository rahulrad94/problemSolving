/*  Next permutation
    Time: O(n)
    */

class Solution {
public:
    void reverse(vector<int> &nums, int start, int end){
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }

    int findCeil(vector<int>nums, int low, int high, int ele){
            if(ele > nums[low])
                return -1;

            if(ele < nums[high])
                return high;

            int mid = (high+low)/2;

            if(nums[mid]<=ele){
                //left side
                if(low<=mid-1 && nums[mid-1]>ele)
                    return mid-1;
                else
                    return findCeil(nums, low, mid-1, ele);

            } else{
                //right side
                if(mid+1<=high && nums[mid+1]<=ele){
                   return mid;
                }
                else
                    return findCeil(nums,mid+1,high,ele);
            }
        }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),i;

        for(i=n-2;i>=0;i--)
            if(nums[i]<nums[i+1])
                break;

        if(i==-1){
            reverse(nums,0,n-1);
            return;
        }

       int index = findCeil(nums,i+1,n-1,nums[i]);
       swap(nums[i],nums[index]);
       reverse(nums,i+1,n-1);
    }
};
