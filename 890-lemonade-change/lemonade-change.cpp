class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        vector<int> change(3,0);
        for(int i =0;i<n;i++){
            if(bills[i]==5){
                change[0]++;
            }
            if(bills[i]==10){
                change[1]++;
                if(change[0]>0){
                change[0]--;}
                else{
                    return false;
                }
            }
            if(bills[i]==20){
                change[2]++;
                if(change[1]>0 && change[0]>0 ){
                    change[1]--;
                    change[0]--;
                }
                else if(change[0]>2){
                    change[0]-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};