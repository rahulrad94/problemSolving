/*  H-Index
    Time: O(nlog(n))
*/

class Solution {
public:
    static bool helper(int a, int b){
        return a>b;
    }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), helper);
        int n = citations.size(),i;

        for(i=0;i<n;i++){
            if(i >= citations[i])
                return i;
        }
        return i;
    }
};
