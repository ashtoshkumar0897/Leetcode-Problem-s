#include <vector>
#include <algorithm> // for std::min and std::max

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0; // Pointer to the start of the array
        int right = height.size() - 1; // Pointer to the end of the array
        int maxArea = 0; // Variable to store the maximum area

        // Loop until the two pointers meet
        while (left < right) {
            // Calculate the current area
            int area = std::min(height[left], height[right]) * (right - left);
            // Update the maximum area
            maxArea = std::max(maxArea, area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++; // Move left pointer to the right
            } else {
                right--; // Move right pointer to the left
            }
        }

        return maxArea; // Return the maximum area
    }
};