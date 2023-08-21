/*
Insertion Sort
Sort an array in ascending order using insertion sort algorithm.
Time Complexity --> (worst/average): n^2
Time Complexity --> (best): n ( if array is already sorted then while loop condition never match
                                and the loop never execute. Only outer loop will execute)
Space Complexity: 1 
*/

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr, int  &n){
    for(int i=1; i<n; i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            // swap(arr[j], arr[j-1])
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp; 
            j--;
        }
    }
}
int main(){
    vector<int> arr = {14, 56, 37, 96, 11, 40};
    int n = arr.size();
    insertion_sort(arr, n);
    // print sorted array
    for(int i=0; i<=n-1; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

