class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_num = nums[0];
        int maj_count = 0;

        for(int i : nums){
            if(maj_count ==0){
                maj_num = i;
            }
            if(i==maj_num){
                maj_count++;
            }
            else{
                maj_count--;
            }
        }
        return maj_num;
    }
};