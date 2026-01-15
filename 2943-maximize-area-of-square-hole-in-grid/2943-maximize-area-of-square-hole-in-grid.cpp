//Approach (Sort and process)
//T.C : O(vlogv + hlogh), v = vBars.size(), h = hBars.size()
//S.C : O(1)
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& VBars) {
        // 1st Step : sort the inputs
        sort(begin(hBars),end(hBars));
        sort(begin(VBars),end(VBars));

        int maxConsecutiveHBars = 1;
        int maxConsecutiveVBars = 1;

        // first find length of largest consecutive horizontal bars
        int currConsecutiveHBars =1;
        for(int i =1;i<hBars.size();i++){
            if(hBars[i] - hBars[i-1] == 1){
                currConsecutiveHBars++;
            }else{
                currConsecutiveHBars =1;
            }
            maxConsecutiveHBars = max(maxConsecutiveHBars, currConsecutiveHBars);
        }

        // Simialrl, find length of longest consecutive vertical bars
        int currConsecutiveVBars =1;
        for(int i =1; i< VBars.size();i++){
            if(VBars[i] - VBars[i-1] == 1){
                currConsecutiveVBars++;
            }else {
                currConsecutiveVBars =1;
            }
             maxConsecutiveVBars = max(maxConsecutiveVBars,currConsecutiveVBars);

        }
        // square width ansd hight must be same . We can reduce the larger one to match the smaller one
        //so, take the minimum of them.
        int side = min(maxConsecutiveHBars,maxConsecutiveVBars)+1;

        return side * side;
       
    }
};