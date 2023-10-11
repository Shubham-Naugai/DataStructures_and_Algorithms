class Solution:
    def search(self, arr: List[int], x: int) -> int:
        n = len(arr)
        l = 0
        h = n-1
        while l<=h:
            mid = (l+h)//2
            if x == arr[mid]:
                return mid
            elif (x > arr[mid]):
                l = mid + 1
            else:
                h = mid - 1

        return -1