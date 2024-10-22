class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> isGreatest;
        int n=candies.size();
        int maxx=INT_MIN;
        for(int i=0;i<n;i++){
            if(candies[i]>maxx){
                maxx=candies[i];
            }
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxx){
                isGreatest.push_back(true);
            }else{
                isGreatest.push_back(false);
            }
        }
            return isGreatest;
    }

};