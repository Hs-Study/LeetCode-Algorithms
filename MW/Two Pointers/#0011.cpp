class Solution {
    
    int get_area(vector<int>& height, int start, int end) {
        int a=height[start],b=height[end];
        return ((a<b)?a:b)*(end-start);
    }
    
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for(int i = 0; i < height.size()-1; i++){
            for(int j = i+1; j < height.size(); j++){
                int area = get_area(height, i, j);
                if (max<area) max=area;
            }
        }
        return max;
    }
};