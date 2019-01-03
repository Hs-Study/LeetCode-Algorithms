/*
 * Name:    Two Sum
 * Tag:     Array, Hash Table
 * Level:   Easy
 */

#include <map>

using namespace std;

class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_map;

        for (int i = 0; i < nums.size(); i++) {
            int compliment = target - nums[i];
            
            auto p = nums_map.find(compliment);
            if (p == nums_map.end()) {
                nums_map.insert(make_pair(nums[i], i));
            } else {
                int v = p->second;
                vector<int> ans;
                ans.push_back(v);
                ans.push_back(i);
                return ans;
            }

        }
        
    }
};