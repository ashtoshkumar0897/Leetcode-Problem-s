class Solution {
public:

    const long long INF =1e10;
    bool increasingTriplet(vector<int>& nums) {
        long long dp[3] = {INF,INF,INF};
        for(int i = 0; i< nums.size();i++){
            for(int j =2; j>= 0; j--){
                if(j == 0){
                    dp[j] = min (dp[j],1ll*nums[i]);
                }else{
                    if(nums[i] > dp[j -1]){
                        dp[j] = nums[i];
                    }
                }
            }
        }
        return dp[2] != INF;
    }
};