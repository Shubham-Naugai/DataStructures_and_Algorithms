class Solution {
public:
    int lengthOfLastWord(string s) {
        int ptr1 = 0;
        int ptr2 = 0;
        int n = s.size();

        for(int i=n-1; i>=0; i--){
            if(isalpha(s[i])){
                ptr1 = i+1;
                break;
            }
        }
        
        for(int i=ptr1-1; i>=0; i--){
            if(s[i] == ' '){
                ptr2 = i;
                break;
            }
            if(i==0){
                ptr2 = i-1;
                break;
            }
        }
        int result = ptr1-ptr2-1;
        return result;
    }
};