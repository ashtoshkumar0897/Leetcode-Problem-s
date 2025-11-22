class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int opperations =0;
        for(int &num : nums){
            if(num%3 != 0)
            opperations++;
        }
        return opperations++;
        
    }
};