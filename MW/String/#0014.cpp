class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)return "";
        int pos=0;
        string ans="";
        bool running=true;
        while(running){
            int ascii[128]={0};
            for(string str:strs){
                if(str.length()==pos) {
                    running=false;
                    break;
                }
                ascii[str[pos]]++;
            }
            char ch=strs[0][pos];
            if(ascii[ch]==n) {
                pos++;
                ans.push_back(ch);
            }else{
                break;
            }
        }
        return ans;
    }
};