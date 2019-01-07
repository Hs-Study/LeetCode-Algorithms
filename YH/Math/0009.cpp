/* 
 * Name:    Palindrome Number
 * Tag:     Math 
 * Level:   Esay
 */

#include <stack>
#include <queue>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        stack<int> s;
        queue<int> q;
        while(x) {
            int k = x%10;
            s.push(k);
            q.push(k);
            x /= 10;
        }
        
        while(!q.empty()) {
            if(q.front() != s.top())
                return 0;
            q.pop(); s.pop();
        }
        return 1;
    }
};
