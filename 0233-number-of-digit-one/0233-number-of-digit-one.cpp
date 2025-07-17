class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        
        int count = 0;
        long long digit = 1; // Current digit position (1, 10, 100, ...)
        
        while (digit <= n) {
            // Calculate higher, current, and lower parts
            long long higher = n / (digit * 10);
            long long current = (n / digit) % 10;
            long long lower = n % digit;
            
            if (current == 0) {
                // If current digit is 0, count depends only on higher digits
                count += higher * digit;
            } else if (current == 1) {
                // If current digit is 1, we get:
                // - All combinations from higher digits: higher * digit
                // - Plus current partial cycle: lower + 1
                count += higher * digit + lower + 1;
            } else {
                // If current digit > 1, we get:
                // - All combinations from higher digits: higher * digit
                // - Plus one complete cycle from current digit: digit
                count += (higher + 1) * digit;
            }
            
            digit *= 10;
        }
        
        return count;
    }
};