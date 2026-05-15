class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
         int l = 0, r =n -1;

         while(l < r){
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]){ // godbad
                l = mid +1; // move right
            } else{
                r =mid;
            }
         }
         return nums[r];
    }
};