class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occur;
        
        for(int num:arr){
            occur[num]++;
        }
        unordered_set<int> dup;
        for(const auto& pair : occur){
            if(dup.count(pair.second)){
                return false;
            }
            else{
                dup.insert(pair.second);
            }
        }

        return true;
    }
};