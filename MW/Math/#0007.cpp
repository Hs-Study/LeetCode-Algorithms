class Solution {
public:
    int reverse(int x) {
        int mul;
        if (x>=0) {
            mul=1;
        } else {
            mul=-1;
            x=-x;
        }
        if (x < 0) {
            return 0;
        }
        
        int tmp_x = x;
        int cnt = 0;
        int xarr[10] = {0,};
        for (int i = 0; i < 10 && tmp_x; i++) {
            xarr[i]=tmp_x%10;
            cnt++;
            tmp_x/=10;
        }

        if (cnt > 10) {
            return 0;
        } else if (cnt == 10) {
            int arr[] = {2,1,4,7,4,8,3,6,4,8};
            bool exceed = true;
            for (int i = 0; i < 10; i++) {
                if (xarr[i] > arr[i] && exceed) {
                    return 0;
                }
                else if (xarr[i] == arr[i] && exceed) {
                    continue;
                }
                else {
                    exceed = false;
                    break;
                }
            }
            
            if (exceed) //==1<<31
                return 0;
        }

        int digit=1;
        int y = 0;
        for (int i = 0; i < cnt; i++) {
            y += xarr[cnt-i-1]*digit;
            digit*=10;
        }

        return y * mul;
    }
};