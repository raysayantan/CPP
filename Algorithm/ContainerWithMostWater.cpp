/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int area = 0;
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while(left != right){
            area = (right - left)*minVal(height[left], height[right]);
            if(area > maxArea) maxArea = area;
            
            if(height[left] <= height[right]){
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
    
    int minVal(int a, int b){
        return((a > b)? b:a);
    }
};
