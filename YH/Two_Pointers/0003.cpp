/* 
 * Name:    Longest Substring Without Repeating Characters
 * Tag:     Hash Table, Two Pointers, String 
 * Level:   Medium
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prev=0;
        int check[128]={0};
        
        int ans=0;
        check[s[0]] = 1;
        for(int i=1; i<s.size(); i++) {
            if(!check[s[i]]) {
                check[s[i]] = 1;
            }
            else {
                ans = max(ans, i-prev);
                while(s[prev] != s[i]) {
                    check[s[prev++]] = 0;    
                }
                check[s[prev++]] = 0;
                check[s[i]] = 1;
            }
        }
        ans = max(ans, s.size()-prev);
        return ans;
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
};
