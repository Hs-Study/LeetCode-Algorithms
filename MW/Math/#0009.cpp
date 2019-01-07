class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int i = 0;
        int tmp_x = x;
        int arr[10]={0,};
        while (tmp_x) {
            arr[i]=tmp_x%10;
            i++;
            tmp_x/=10;
        }

        for (int j = 0; j < i/2; j++) {
            if (arr[j] != arr[i-j-1])
                return false;
        }
        return true;
    }
};