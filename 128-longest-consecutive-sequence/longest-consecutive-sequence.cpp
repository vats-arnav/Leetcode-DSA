class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int l = 1;
        unordered_set<int> st;
        for(auto x : nums){
            st.insert(x);
        }
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                int temp =1;
                int tv = x;
                while(st.find(tv+1)!=st.end()){
                    tv++;
                    temp++;
                }

                l = max(l,temp);
        }   
        }

        return l;
    }
};