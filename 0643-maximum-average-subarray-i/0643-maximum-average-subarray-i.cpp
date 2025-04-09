class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum= 0;
        double currentSum = 0;

        //Sum of the first 'k' elements
        for(int i =0; i < k; i++){
            currentSum += nums[i];
        }

        maxSum = currentSum;

        //Slide the window across the array
        for(int i =k;i<nums.size();i++){
            currentSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum /k; // Return the maximum average
    }
};