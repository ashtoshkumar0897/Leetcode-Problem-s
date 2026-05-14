class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int  i = 1; i< nums.size();i++){
            nums[i]= nums[i]+nums[i-1];// arr 1 2 3 4 = 
        }
        return nums;
        
    }
};