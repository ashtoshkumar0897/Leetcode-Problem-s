class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 +7;
        int count = 0,prefixsum =0;
        //evenCount starts as 1 since the initial sum (0) is even
        int oddCount = 0,evenCount = 1;

        for(int num : arr){
            prefixsum += num;
            //if current prefix sum is even,add the number of odd subarrays 
            if(prefixsum %2==0){
                count += oddCount;
                evenCount++;
            }else{
                //If current prefix sum is aodd, add the number of even
                //subarrays
                count +=evenCount;
                oddCount++;
            }
            count %=MOD;//to handle larger results
        }
        return count;
    }
};