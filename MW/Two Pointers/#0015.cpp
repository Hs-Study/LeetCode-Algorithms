#include <algorithm>
#include <map>

class Solution {
    bool search(vector<int>& nums, int target, int start, int end) {
        if (start > end) return false;

        int mid = (start+end)/2;
        if (target < nums[mid]) {
            return search(nums, target, start, mid - 1);
        } else if (nums[mid] < target) {
            return search(nums, target, mid + 1, end);
        } else {
            return true;
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nsize = nums.size();
        vector<vector<int>> ans;
        if (nsize < 3) return ans;

        sort(nums.begin(), nums.end());

        map<pair<int,int>, int> nums_map;
        for (int i = 0; i < nsize - 2; i++) {
            int& first = nums[i];
            if (first > 0) return ans;

            for (int j = i + 1; j < nsize - 1; j++) {
                int& second = nums[j];
                int comp = -(first + second);
                if (comp < second) break;

                if (search(nums, comp, j + 1, nsize - 1)) {
                    pair<int,int> nums_pair = make_pair(first, second);
                    if (nums_map.find(nums_pair) == nums_map.end()) {
                        nums_map.insert(make_pair(nums_pair, 0));
                        ans.push_back({first, second, comp});
                    }
                }
            }
        }

        return ans;
    }
};