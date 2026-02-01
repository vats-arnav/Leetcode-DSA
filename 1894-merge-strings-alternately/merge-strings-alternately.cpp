class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str;
        int i;
        for( i=0;i<min(word1.length(),word2.length());i++){
            str = str + word1[i] + word2[i];
        }
        if(i<word1.length()){
            str = str + word1.substr(i);
        }
        if(i<word2.length()){
            str = str + word2.substr(i);
        }

        return str;
    }
};