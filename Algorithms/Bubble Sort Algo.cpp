/*
Bubble Sort
Sort an array in ascending order using bubble sort algorithm.
Time Complexity --> (worst/average): n^2
Time Complexity --> (best): n ( if array is already sorted then we have no swaping in first iteration of outer loop,
                                so we will stop the further iterations)
Space Complexity: 1 
*/

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr, int  &n){
    for(int i=n-1; i>=1; i--){
        int didSwap = 0;
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                // swap(arr[j], arr[j+1])
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0){
            break;
        }
    }
}
int main(){
    vector<int> arr = {14, 56, 37, 96, 11, 40};
    int n = arr.size();
    bubble_sort(arr, n);
    // print sorted array
    for(int i=0; i<=n-1; i++){
        cout << arr[i] << " ";
    }
    return 0;
}