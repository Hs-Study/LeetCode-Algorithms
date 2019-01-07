/* 
 * Name:    Longest Palindromic Substring
 * Tag:     String, DP 
 * Level:   Medium
 */

int d[1005][1005];

class Solution {
public:
    
    void init(int n) {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                d[i][j] = -1;
    }
    
    bool isP(string &str, int s, int e) {
        if(s >= e) return 1;
        if(d[s][e] != -1) return d[s][e];
        return d[s][e] = str[s] == str[e] ? isP(str, s+1, e-1) : 0; 
    }
    
    string longestPalindrome(string str) {
        int n = str.size();
        init(n);
        
        int s=0, e=0, max=0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(d[i][j] == -1) {
                    d[i][j] = isP(str, i, j);
                    if(d[i][j] == 1) {
                        if(max < j-i+1) {
                            max = j-i+1;
                            s = i;
                            e = j;
                        }
                    }
                }
            }
         }
        
        str[e+1]=0;
        return &str[s];
        
    }
};
