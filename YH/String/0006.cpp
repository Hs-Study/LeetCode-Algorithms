/* 
 * Name:    ZigZag Conversion
 * Tag:     String 
 * Level:   Medium
 */

#include <vector>

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        vector<vector<char>> v(numRows);
        int cur = 1;
        int add = 1;
        v[0].push_back(s[0]);
        for(int i=1; i<s.size(); i++) {
            v[cur].push_back(s[i]);
            if(cur == numRows-1) {
                add = -1;
                cur--;
            }
            else if(cur == 0) {
                add = 1;
                cur++;
            }
            else 
                cur += add;  
        }
        
        char *ans = new char[s.size()+1];
        int idx=0;
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<v[i].size(); j++) {
                ans[idx++] = v[i][j];
            }
        }
        ans[idx] = 0;
        return ans;
    }
};
