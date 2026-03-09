class Solution {
public:
    int numberOfSubstrings(string s) {
    // Stores the last seen index of 'a', 'b', and 'c'
    vector<int> lastSeen(3, -1); 
    int count = 0;
    
    for (int i = 0; i < s.length(); i++) {
        lastSeen[s[i] - 'a'] = i;
        
        // If we have seen all three characters at least once
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            // The number of valid substrings ending at 'i' is bounded by the smallest last seen index
            count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
    }
    
    return count;
    }

         
};

