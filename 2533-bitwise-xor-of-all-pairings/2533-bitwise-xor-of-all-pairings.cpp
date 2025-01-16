class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //Initialize XOR results for both arrays
        int xor1=0;
        int xor2 =0;

        //Get length of both arrays 
        int len1 = nums1.size();
        int len2 = nums2.size();

        // If nums2 length is odd element is nums1 appears odd time in 
        //final result
        if(len2 % 2 !=0){
            for(int num : nums1){
                xor1^=num;
            }
        }

        // If nums1 length is odd, each element is nums2 appears odd times in 
        //final result
        if(len1 %2 != 0){
            for(int num: nums2){
                xor2 ^= num;
            }
        }
        
        // Return XOR of both results
        return xor1 ^ xor2; 
    }
};