class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1){
            return 'a';
        }

        int n = operations.size();
        long long len = 1;
        long long newk = -1;
        int operationType =-1;

        for(int i =0;i<n;i++){
            len *=2;//"a","aa","aabb"

            if(len >=k){
                operationType = operations[i];
                newk = k -len/2;
                break;
            }
        }

        char ch = kthCharacter(newk,operations);
        if(operationType ==0){
            return ch;
        }
        return ch =='z' ? 'a' : ch +1;
        
        
    }
};