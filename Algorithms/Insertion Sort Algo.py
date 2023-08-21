"""
Insertion Sort
Sort an array in ascending order using insertion sort algorithm.
Time Complexity --> (worst/average): n^2
Time Complexity --> (best): n ( if array is already sorted then while loop condition never match
                                and the loop never execute. Only outer loop will execute)
Space Complexity: 1
"""


def insertion_sort(arr, n):
    for i in range(1, n):
        j = i
        while j>0 and arr[j-1] > arr[j]:
            arr[j], arr[j-1] = arr[j-1], arr[j]
            j -= 1

if __name__ == '__main__':

    arr = [14, 56, 37, 96, 11, 40]
    n = len(arr)

    insertion_sort(arr, n)
    print(arr)
