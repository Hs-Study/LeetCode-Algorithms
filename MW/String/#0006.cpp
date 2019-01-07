class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string ans;
        int tot_inc = 2*numRows-2;
        int slen = s.length();

        for (int i = 0; i < numRows; i++) {
            int j = i;
            int inc1 = (numRows-i)*2-2;
            int inc2 = tot_inc-inc1;
            bool mod = true;

            if (inc1 && inc2) {
                while (j < slen) {
                    ans.push_back(s[j]);
                    j += (mod) ? inc1 : inc2;
                    mod = !mod;
                }
            } else {
                int inc = (inc1) ? inc1 : inc2;
                while (j < slen) {
                    ans.push_back(s[j]);
                    j += inc;
                }
            }
        }

        return ans;
    }
};