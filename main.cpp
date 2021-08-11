//===================================================
// File: main.cpp
//===================================================
// Programmer: Shannon Liou
// Date: 04/25/2021
// Class: CSCI 133 ("Data Structures Using C++")
// Project: HeapSort
//
// Description:
//      This program uses HeapSort to sort an array // in an descending order.
//
//===================================================

#include <iostream>
using namespace std;
  
// ==== MinHeap =====================================
//
// This is the function that heapifies the tree or 
// subtree to a MinHeap so that HeapSort (descending 
// order) can be performed.
//
// Input:
//     arr[]  [IN]  -- An int array to be heapified
//     n      [IN]  -- An int value representing the size of arr[]
//     r      [IN]  -- The position of the root node     
//
// Output:
//     void
//
// =================================================
void MinHeap(int arr[], int n, int r)
{
    // set the position of the current smallest value as 
    // the root node's position
    int smallPos = r;
    //set the left child's position and the right child's position
    int left = 2 * r + 1;
    int right = 2 * r + 2;
  
    // repeatedly swap the just-moved value (root value)
    // with the smaller of its 2 children until the value
    // is <= both children

    // check if left child is smaller than current root
    if (left < n && arr[left] < arr[smallPos])
    {    
        // change current smallPos to left child's pos
        smallPos = left;    
    }
  
    // check if right child is smaller than current root 
    // or left child, whichever is the smallest
    if (right < n && arr[right] < arr[smallPos])
    {
        smallPos = right;
    }
  
    // swap the just-moved value (root value)
    // with the smaller of its 2 children (smallPos)
    // if smallPos is not the root position
    if (smallPos != r) {
        swap(arr[r], arr[smallPos]);
  
        // repeatedly swap until the just-moved 
        // value (root value) is <= both children
        MinHeap(arr, n, smallPos);
    }
}


// ==== MaxHeap =====================================
//
// This is the function that heapifies the tree or 
// subtree to a MaxHeap so that HeapSort (ascending
// order) can be performed.
//
// Input:
//     arr[]  [IN]  -- An int array to be heapified
//     n      [IN]  -- An int value representing the size of arr[]
//     r      [IN]  -- The position of the root node     
//
// Output:
//     void
//
// =================================================
void MaxHeap(int arr[], int n, int r)
{
    // set the position of the current largest value // as the root node's position
    int largePos = r;
    //set the left child's position and the right child's position
    int left = 2 * r + 1;
    int right = 2 * r + 2;
  
    // repeatedly swap the just-moved value (root value)
    // with the larger of its 2 children until the value
    // is >= both children

    // check if left child is larger than current root
    if (left < n && arr[left] > arr[largePos])
    {    
        // change current smallPos to left child's pos
        largePos = left;    
    }
  
    // check if right child is larger than current root 
    // or left child, whichever is the largest
    if (right < n && arr[right] > arr[largePos])
    {
        largePos = right;
    }
  
    // swap the just-moved value (root value)
    // with the smaller of its 2 children (smallPos)
    if (largePos != r) 
    {
        swap(arr[r], arr[largePos]);
  
        // repeatedly swap until the just-moved 
        // value (root value) is <= both children
        MaxHeap(arr, n, largePos);
    }
}

  

// ==== heapSort =====================================
//
// This is the function that performs HeapSort,
// which is the objective of the program.
//
// Input:
//     arr[]  [IN]  -- An int array to be sorted using HeapSort
//     n      [IN]  -- An int value representing the size of arr[]
//
// Output:
//     void
//
// =================================================
void heapSort(int arr[], int n, int type)
{
    // Step 1: Convert array to MinHeap
    for (int curNode = n / 2 - 1; curNode >= 0; curNode--)
    {
        // focus on the subtree rooted at curNode
        // heapify subtree to MinHeap
        //type == 0 -> ascending order, MaxHeap
        if(type == 0)
        {
            MaxHeap(arr, n, curNode);
        }
        else
        {
            //type == 1 -> descending, MinHeap
            MinHeap(arr, n, curNode);
        }
    }
  
    // Step 2
    // "rb" is the right-most node in the bottom-most row 
    // (aka the last node) that doesn't include 
    // the extracted and re-inserted nodes
    for (int rb = n - 1; rb >= 0; rb--) 
    {
        // Extract the root node (smallest value)
        int ext = arr[0];
        // Move the value of rb to the root node
        arr[0] = arr[rb];

        // heapify (MinHeap) from the root node to the node before rb
        // if type == 0, ascending, MaxHeap
        if(type == 0)
        {
            MaxHeap(arr, rb, 0);
        }
        else
        {
            //type == 1, descending, MinHeap
            MinHeap(arr, rb, 0);
        }
        // Insert the extracted value into the freed up slot
        arr[rb] = ext;
    }
}
  

// ==== printArr =====================================
//
// This is the function that displays all the elements
// of the input array.
//
// Input:
//     arr[]  [IN]  -- An int array to be displayed
//     n      [IN]  -- An int value representing the size of arr[]
//
// Output:
//     void
//
// =================================================
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
  

int main()
{
    int size = 10;
    int maxOrMin;
    
    cout << "Enter amount of numbers in your list: ";
    cin >> size;

    int array[size];

    cout << "Please enter one number at a time.\n";

    for(int i = 0; i < size; i++)
    {
        cout << "Enter item number " << i+1 << ": ";
        cin >> array[i];
    }

    cout << "Here's your list of numbers.\n";
    printArr(array, size);
    
    while(maxOrMin != 0 && maxOrMin != 1)
    {
        cout << "Enter 0 to sort in ascending order.\n";
        cout << "Enter 1 to sort in descending order. \n";
        cin >> maxOrMin;
    }

  
    heapSort(array, size, maxOrMin);
    cout << "Here's the sorted list of numbers\n";
    printArr(array, size);
}
