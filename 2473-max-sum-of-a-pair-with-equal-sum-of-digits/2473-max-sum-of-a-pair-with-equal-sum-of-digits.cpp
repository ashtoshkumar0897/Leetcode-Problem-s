class Solution {
public:
    int maximumSum(vector<int>& nums){
       /* ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);*/

        if(nums.size()==1) return -1;

        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        int maxSum=-1;

        for(auto &num :nums){
            int sum=0,x=num;

            while(x){
                sum+=(x%10);
                x/=10;
            }

            if(mp.find(sum) == mp.end() || mp[sum].size()<2){
                mp[sum].push(num);
            }

            else if(num>mp[sum].top()){
                auto &minHeap=mp[sum];

                minHeap.pop();
                minHeap.push(num);
            }
        }

        for(auto &it : mp){
            auto &minHeap=it.second;

            if(minHeap.size()==2){
                int currSum=0;

                while(!minHeap.empty()){
                    currSum+=minHeap.top();
                    minHeap.pop();
                }

                maxSum=max(maxSum,currSum);
            }
        }

        return maxSum;
    }
};