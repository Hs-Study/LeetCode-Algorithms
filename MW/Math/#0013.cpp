#include <map>

class Solution {
    
    map<char,int> rti_map;
    
public:
    Solution() {
        rti_map.clear();
        rti_map.insert(make_pair('I',1));
        rti_map.insert(make_pair('V',5));
        rti_map.insert(make_pair('X',10));
        rti_map.insert(make_pair('L',50));
        rti_map.insert(make_pair('C',100));
        rti_map.insert(make_pair('D',500));
        rti_map.insert(make_pair('M',1000));
    }
    
    int romanToInt(string s) {
        int ans=0;
        int prev=0,neg=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];

            auto rti_pair=rti_map.find(ch);
            if(rti_pair!=rti_map.end()){
                int num=rti_pair->second;
                
                if(prev==0){
                    prev=neg=num;
                }else if(prev<num){
                    ans=ans+num-neg;
                    neg=0;
                }else if(prev==num){
                    neg+=num;
                }else if(prev>num){
                    ans+=neg;
                    prev=neg=num;
                }
            }
        }

        if(neg>0){
            ans+=neg;
        }
        
        return ans;
    }
};