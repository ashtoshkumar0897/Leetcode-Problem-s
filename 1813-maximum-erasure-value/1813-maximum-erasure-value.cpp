class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        int i=0;
        int j=0;
        int sum=0;
        int result=0;

        while(j<n){
            if(!st.count(nums[j])){
                sum += nums[j];
                result = max(result,sum);
                st.insert(nums[j]);
                j++;
            }else{ // we have seen this nums[j].So time to shrink the window
            
                while(i<n && st.count(nums[j])){
                    sum -= nums[i];
                    st.erase(nums[i]);//0(1)
                    i++;
                }
            }
    
        }
        return result;
        
    }
};