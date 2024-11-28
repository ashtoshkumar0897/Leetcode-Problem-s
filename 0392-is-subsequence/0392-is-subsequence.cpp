class Solution {
public:
    bool isSubsequence(string str1, string str2) {
        // Initialize pointers for both strings
        int i = 0;
        int j = 0;

        while (i < str1.length() && j < str2.length()) {
            // Compare characters, increment both pointers if the same
            if (str1[i] == str2[j]) {
                i++;
                j++;
            } else {
                j++; // Only increment the second pointer
            }
        }

        // If it is a subsequence, 'i' will have traveled the full
        // length of string 'str1'. Return true if i equals str1 length.
        return (i == str1.length());
    }
};
