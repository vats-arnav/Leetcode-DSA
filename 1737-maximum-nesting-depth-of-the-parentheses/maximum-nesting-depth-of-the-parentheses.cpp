class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int counter =0;
        for(char c :s){
            if(c=='('){
                counter++;
            ans = max(ans,counter);
            }
            else if(c==')'){
                counter--;
            }
        }
        return ans;
    }
};