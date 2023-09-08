class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>roman={{'I',1},{'V',5}, {'X',10}, {'L',50},{'C',100}, {'D',500}, {'M',1000}};
        int ans=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(roman.find(s[i])!=roman.end()){
                if(roman[s[i+1]]>roman[s[i]]){
                    ans-=roman[s[i]];
                }else{
                ans+=roman[s[i]];
                    
                }
            }
        }
        return ans;
    }
};