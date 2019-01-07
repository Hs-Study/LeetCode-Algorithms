/* 
 * Name:    Reverse Integer 
 * Tag:     Math 
 * Level:   Easy
 */

class Solution {
public:
    int reverse(int x) {
        int max = 0x7fffffff;
        int min = -(1<<31);
        bool isMinus = 0;
        if(x < 0) {
            x *= -1;
            isMinus = 1;
        }
        
        long long ans=0LL;
        while(x) {
            ans *= 10LL;
            ans += x%10;
            x /= 10;
        }
        if(isMinus) ans *= -1;
        if(ans < min || ans > max) ans = 0;
        return ans;
    }
};
