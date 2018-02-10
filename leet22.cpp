/* Generate parentheses */
/* Simple recursive solution */

class Solution {
public:
    void calc(int n, int open, int close, vector<string>& result, int index, string str){
        if(close>=n){
            result.push_back(str);
            return;
        }

        if(open<n){
            str[index] = '(';
            calc(n,open+1,close,result,index+1,str);
        }

        if(close<open){
            str[index] = ')';
            calc(n, open, close+1, result, index+1, str);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str(2*n,'  ');
        calc(n,0,0,result,0,str);
        return result;
    }
};
