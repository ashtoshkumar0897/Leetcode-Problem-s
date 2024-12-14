class Solution {
public:
    
    bool check(multiset<int>&mt){
        int a=*(mt.rbegin());
        int b=*(mt.begin());
        if(abs(a-b)>2){
            return true;
        }
        return false;
    }
    
    
    long long continuousSubarrays(vector<int>& arr) {
        long long int ans=0;
        int n=arr.size();
        
        int i=0;
        int j=0;
        multiset<int>mt;
        while(j<n){
            mt.insert(arr[j]);
            while(check(mt)){
                mt.erase(mt.find(arr[i]));
                i+=1;
            }
            ans+=(j-i+1);
            j+=1;
        }
        return ans;
        
        
        
    }
};