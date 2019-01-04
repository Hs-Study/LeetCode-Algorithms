/*
 * Name:    Longest Substring Without Repeating Characters
 * Tag:     Hash Table, Two Pointers, String
 * Level:   Medium
 */

class Solution {
    string memory = "";
    
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[129] = {0,};
        int max_len = 0;
        int len = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.at(i);
            if (alpha[ch] == 0) {
                alpha[ch]++;
                len++;
            } else {
                if (max_len < len)
                    max_len = len;
                int pos = 0;
                char target = memory.at(0);
                while (target != ch) {
                    pos++;
                    alpha[target]--;
                    target = memory.at(pos);
                } //pos: ch 와 같은 문자에 대한 인덱스
                memory = memory.substr(pos+1); //pos+1 부터 끝까지
                len = memory.length()+1;
            }
            memory.push_back(ch);
        }
        if (max_len < len)
            max_len = len;

        return max_len;
    }
};