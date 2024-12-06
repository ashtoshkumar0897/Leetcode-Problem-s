class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> map;
        for (int i = 0; i < banned.size(); i++) {
            map[banned[i]] = 1;
        }
        int sum = 0, count = 0;
        for (int i = 1; i <= n; i++) {
            if (map.find(i) == map.end()){
                if (sum + i > maxSum) {
                    break; 
                }
                sum += i;
                count++;
            }
        }
        
        
        return count;
    }
};