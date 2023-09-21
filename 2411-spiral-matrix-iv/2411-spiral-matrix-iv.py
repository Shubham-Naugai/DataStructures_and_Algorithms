# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        mat = [[-1 for i in range(n)] for _ in range(m)]
        
        left, right = 0, n
        top, bottom = 0, m
        while left < right and top < bottom:
            # put value in the top row
            for i in range(left, right):
                mat[top][i] = head.val
                if not head.next:
                    return mat
                head = head.next
            top += 1
            
            # put value in the right col
            for i in range(top, bottom):
                mat[i][right-1] = head.val
                if not head.next:
                    return mat
                head = head.next
            right -= 1
            
            for i in range(right-1, left-1, -1):
                mat[bottom-1][i] = head.val
                if not head.next:
                    return mat
                head = head.next
            bottom -= 1
            
            # put value in the left col
            for i in range(bottom-1, top-1, -1):
                mat[i][left] = head.val
                if not head.next:
                    return mat
                head = head.next
            left += 1
        return mat