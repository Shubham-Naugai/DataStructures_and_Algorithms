/* Given a sorted array of n integers and a target value, determine if the target exists in
the array in logarithmic time using the binary search algorithm. If target exists in the
array, print the index of it.
Input:
 
nums[] = [2, 3, 5, 7, 9]
target = 7
 
Output: Element found at index 3
 
 
Input:
 
nums[] = [1, 4, 5, 8, 9]
target = 2
 
Output: Element not found

*/


/*
In C++, STL library has std::binary_search function defined in the header “algorithm”.
It takes the iterators to the starting and ending positions of a sorted sequence and 
returns true if the target value is found; otherwise, returns false. This search 
operation takes O(log(n)) time and is very efficient even for large sorted arrays.

#include <iostream>
#include <algorithm>
 
// C++ program to demonstrate working of `std::binary_search` algorithm
int main()
{
    int arr[] = { 4, 6, 8, 10, 15 };
    int target = 10;
 
    if (std::binary_search(std::begin(arr), std::end(arr), target))
    {
        std::cout << "Element found in the array";
    }
    else {
        std::cout << "Element not found in the array";
    }
 
    return 0;
}

*/




// ***********Iterative approach***********

#include <iostream>  
using namespace std;  
int main (){  
    // declaration of the variables and array
    int arr[100], st, mid, end, i, num, tgt;

    cout << " Define the size of the array: " << endl;
    cin >> num; // get size
      
    // enter only sorted array
        cout << " Enter the values in sorted array either ascending or descending order: " << endl;  
    // use for loop to iterate values 
    for (i = 0; i < num; i++)
    {  
        cout << " arr [" << i << "] = ";  
        cin >> arr[i];  
    }  
      
    // initialize the starting and ending variable's values  
    st = 0;  
    end = num - 1; // size of array (num) - 1  
      
    // define the item or value to be search  
    cout << " Define a value to be searched from sorted array: " << endl;  
    cin >> tgt;  
      
    // use while loop to check 'st', should be less than equal to 'end'.  
    while ( st <= end)  
    {  
        // get middle value by splitting into half  
        mid = ( st + end ) / 2;  
        /* if we get the target value at mid index, print the position and exit from the program. */  
        if (arr[mid] == tgt)  
        {  
            cout << " Element is found at index " << (mid + 1);  
            exit (0); // use for exit program the program  
        }  
        // check the value of target element is greater than the mid element' value  
        else if ( tgt > arr[mid])  
        {  
            st = mid + 1; // set the new value for st variable  
        } 
          
        // check the value of target element is less than the mid element' value
        else if ( tgt < arr[mid])
        {
            end = mid - 1; // set the new value for end variable
        }
    }
    cout << " Element not found. " << endl;
    return 0;
}





// ***********Recursive approach***********


#include <iostream>
using namespace std;
// define a function
int binary_search (int [], int, int, int);
int main (){
    // declaration of the variables
    int i, arr[100], tgt, num, ind, st, end;
    cout << " Define the size of an array: ";
    cin >> num;
    cout << " Enter " << num << " elements in ascending order: " << endl;
    // use for loop to ieterate the number 
    for ( i = 0; i < num; i++)
    {
        cout << " arr [" << i << "] = "; 
        cin >> arr[i];
    }
    // define the element to be search
    cout << " \n Enter an element to be searched in ascending array: ";
    cin >> tgt;
    // ind define the index number
    ind = binary_search (arr, 0, num - 1, tgt);
    // check for existemce of the specified element
    if (ind == 0)
        cout << "element not Found";
    else
        cout << tgt << " is available at position " << ind << endl;
    return 0;
}
// function defnition
int binary_search (int arr[], int st, int end, int tgt)
{
    int mid;
    // check st is greater than end
    if (st > end)
    {
        return 0;
    }
    mid = (st + end) / 2; // get middle value of the sorted array
      
    // check middle value is equal to target number
    if (arr[mid] == tgt)
    {
        return (mid + 1);
    }
    // check mid is greater than target number
    else if (arr[mid] > tgt)
    {
        binary_search (arr, st, mid - 1, tgt);
    }
    // check mid is less than target number
    else if (arr [mid] < tgt)
    {
        binary_search (arr, mid + 1, end, tgt);
    }
}




/*
We know that at each step of the algorithm, our search space reduces to half. That means if initially, our search space contains n elements, then after one iteration it contains n/2, then n/4 and so on…

n —> n/2 —> n/4 —> … —> 1
Suppose our search space is exhausted after k steps. Then,

n/2k = 1
n = 2k
k = log2n
Therefore, the time complexity of the binary search algorithm is O(log2n), which is very efficient. The auxiliary space required by the program is O(1) for iterative implementation and O(log2n) for recursive implementation due to call stack.
*/