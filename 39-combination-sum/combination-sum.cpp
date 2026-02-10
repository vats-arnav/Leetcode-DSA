class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> data;
        sort(candidates.begin(),candidates.end());
        int sum =0;
        recr(0,candidates,result,data,target,0);
        return result;
    }

    void recr(int index,vector<int>& candidates,vector<vector<int>> &result,vector<int>& data, int target,int sum){
        if(target==sum){
            result.push_back(data);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(sum+candidates[i]>target){
                break;
            }
            sum+=candidates[i];
            data.push_back(candidates[i]);
            recr(i,candidates,result,data,target,sum);
            sum-=candidates[i];
            data.pop_back();
        }

    }
};