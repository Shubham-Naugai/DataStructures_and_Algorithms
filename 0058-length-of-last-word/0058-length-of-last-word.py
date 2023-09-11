class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ptr1 = 0
        ptr2 = 0
        n = len(s)

        for i in range(n-1,-1,-1):
            if s[i].isalpha():
                ptr1 = i+1
                break
        
        for i in range(ptr1-1,-1,-1):
            if s[i] == " ":
                ptr2 = i
                break
            if i==0:
                ptr2 = i-1
                break
        
        result = ptr1-ptr2-1
        return result