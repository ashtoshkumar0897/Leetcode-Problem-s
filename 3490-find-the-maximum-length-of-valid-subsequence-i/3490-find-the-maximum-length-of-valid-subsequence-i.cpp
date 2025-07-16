class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int n =nums.size();

        int countEven =0;// length of even numbers subsequence 
        int countOdd = 0;//length of odd numbers subsequence

        for(int &num:nums){
            if(num%2==0){ //even
                countEven++;
            }else{
                countOdd++;
            }
        }

        int parity = nums[0]%2;
        int alternating = 1;//length of althernating parity numbers subsequence

        for(int i =1;i<n;i++){
            int currParity = nums[i]%2;
            if(currParity != parity){ // althernating parity
                alternating++;
                parity = currParity;

            }
        }
        return max({countEven,countOdd,alternating});
    }
};