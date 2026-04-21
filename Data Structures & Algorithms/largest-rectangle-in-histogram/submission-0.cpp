class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;

        for(int i = 0; i < n; i++) {
            int left = i;
            int right = i;
            // expand left
            while(left >= 0 && heights[left] >= heights[i]) {
                left--;
            }

            // expand right
            while(right < n && heights[right] >= heights[i]) {
                right++;
            }

            int width = right - left - 1;
            int area = width * heights[i];

            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};