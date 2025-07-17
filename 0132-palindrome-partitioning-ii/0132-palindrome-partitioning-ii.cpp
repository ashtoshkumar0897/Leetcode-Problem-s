class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        
        // Step 1: Precompute palindrome information
        // isPalindrome[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            isPalindrome[i][i] = true;
        }
        
        // Check for palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
            }
        }
        
        // Check for palindromes of length 3 and more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                }
            }
        }
        
        // Step 2: DP to find minimum cuts
        // dp[i] = minimum cuts needed for s[0...i]
        vector<int> dp(n, INT_MAX);
        
        for (int i = 0; i < n; i++) {
            // If s[0...i] is already a palindrome, no cuts needed
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                // Try all possible cuts
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        
        return dp[n - 1];
    }
};