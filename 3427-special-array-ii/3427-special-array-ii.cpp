class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> prefix_sum(n,0);
        prefix_sum[0]=1;
        for(int i=1;i<n;++i){
            if((nums[i]&1) == (nums[i-1]&1))
                prefix_sum[i]=1;
            else prefix_sum[i]=1+prefix_sum[i-1];
        }

        vector<bool> ans;
        for(auto& query: queries){
            int start=query[0];
            int end=query[1];
            int size = end-start+1;

            if(prefix_sum[end]>=size)       ans.push_back(true);
            else                            ans.push_back(false);
        }
        return ans;
    }
};
/*
//JAVA
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Boolean> isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] prefixSum = new int[n];
        prefixSum[0] = 1;

        for (int i = 1; i < n; i++) {
            if ((nums[i] & 1) == (nums[i - 1] & 1)) {
                prefixSum[i] = 1;
            } else {
                prefixSum[i] = 1 + prefixSum[i - 1];
            }
        }

        List<Boolean> ans = new ArrayList<>();
        for (int[] query : queries) {
            int start = query[0];
            int end = query[1];
            int size = end - start + 1;

            if (prefixSum[end] >= size) {
                ans.add(true);
            } else {
                ans.add(false);
            }
        }
        return ans;
    }
}

#Python
class Solution:
    def isArraySpecial(self, nums, queries):
        n = len(nums)
        prefix_sum = [0] * n
        prefix_sum[0] = 1

        for i in range(1, n):
            if (nums[i] & 1) == (nums[i - 1] & 1):
                prefix_sum[i] = 1
            else:
                prefix_sum[i] = 1 + prefix_sum[i - 1]

        ans = []
        for query in queries:
            start, end = query
            size = end - start + 1

            if prefix_sum[end] >= size:
                ans.append(True)
            else:
                ans.append(False)

        return ans
*/