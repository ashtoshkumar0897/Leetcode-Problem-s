class Solution {
public:
    int minimizedMaximum(int stores, vector<int>& qty) {
        int low {1},high = *max_element(qty.begin(),qty.end());
        while(low < high){
            int mid =(low +high)/2,needed {0};
            for (int q : qty) needed += (q + mid - 1) / mid;
            if(needed <= stores ) high =mid;
            else low =mid +1;        
        }
        return low;
    }
   
};
auto io_opt =[] { ios::sync_with_stdio(false); cin.tie(nullptr);return 0;}();