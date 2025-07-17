class Solution {
public:
    int numDecodings(string s) {
        const int MOD = 1000000007;
        int n = s.length();
        
        if (n == 0) return 0;
        
        // dp[i] represents number of ways to decode s[0...i-1]
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // Empty string has 1 way
        
        // Handle first character
        if (s[0] == '*') {
            dp[1] = 9; // Can be 1-9
        } else if (s[0] != '0') {
            dp[1] = 1; // Valid single digit
        } else {
            dp[1] = 0; // '0' cannot be decoded alone
        }
        
        for (int i = 2; i <= n; i++) {
            char curr = s[i-1];
            char prev = s[i-2];
            
            // Single character decoding
            if (curr == '*') {
                dp[i] = (dp[i] + dp[i-1] * 9) % MOD;
            } else if (curr != '0') {
                dp[i] = (dp[i] + dp[i-1]) % MOD;
            }
            
            // Two character decoding
            if (prev == '1') {
                if (curr == '*') {
                    dp[i] = (dp[i] + dp[i-2] * 9) % MOD; // 11-19
                } else {
                    dp[i] = (dp[i] + dp[i-2]) % MOD; // 10-19
                }
            } else if (prev == '2') {
                if (curr == '*') {
                    dp[i] = (dp[i] + dp[i-2] * 6) % MOD; // 21-26
                } else if (curr >= '0' && curr <= '6') {
                    dp[i] = (dp[i] + dp[i-2]) % MOD; // 20-26
                }
            } else if (prev == '*') {
                if (curr == '*') {
                    dp[i] = (dp[i] + dp[i-2] * 15) % MOD; // 11-19 (9) + 21-26 (6) = 15
                } else if (curr >= '0' && curr <= '6') {
                    dp[i] = (dp[i] + dp[i-2] * 2) % MOD; // 1x + 2x where x is 0-6
                } else if (curr >= '7' && curr <= '9') {
                    dp[i] = (dp[i] + dp[i-2]) % MOD; // Only 1x where x is 7-9
                }
            }
        }
        
        return dp[n];
    }
};