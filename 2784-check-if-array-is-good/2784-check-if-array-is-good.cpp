class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n,0);

        for(int x : nums){
            if(x >= n) return false;   // out of range element
            freq[x]++;             
        }

        // check 1 to n-2 appear exactly once
        for(int i = 1; i < n-1; i++){
            if(freq[i] != 1) return false;
        }

        // last element (n-1) should appear twice
        return freq[n-1] == 2;
    }
};
