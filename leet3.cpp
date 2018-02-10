/*  Longest Substring without repeating characters
/*  Using map and 2-pointers
    Time: O(n)
    Space: O(n)
    */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;

        int start=0, end=1;
        int map[256];
        int max_length=1;

        for(int i=0;i<256;i++)
            map[i] = -1;

        map[s[0]] = 0;

        while(end<s.length()){

            if(map[s[end]]==-1)
                map[s[end]] = end;
            else {
                if(map[s[end]]+1>start)
                    start = map[s[end]]+1;


                map[s[end]] = end;
            }
             cout<<start<<"  "<<end<<endl;
            if(max_length<end-start+1)
                max_length = end-start+1;
            end++;
        }
        return max_length;
    }
};
