// Date   : 04-07-2020

/************************************ Using Min Heap without STL *******************************************/
// Time Complexity: O(mlogn) + O(nlogn)
// Space Complexity: O(1)

/****************************************NEVER GIVE UP :)*****************************************/



/************Using Min Heap & Sorting******************************/
// Time Complexity: O(m + n)log(n)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

// rearranging array elements to make min heap
// Recursive approach takes O(log(n)) Time Complexity & O(logn) Space Complexity
// void heapify(long arr2[],long n,long i)
// {
//     long rootSmallest = i;
//     long leftNode = 2 * i + 1;
//     long rightNode = 2 * i + 2;
    
//     if(leftNode < n && arr2[leftNode] < arr2[i])
//         rootSmallest = leftNode;
    
//     if(rightNode < n && arr2[rightNode] < arr2[i])
//         rootSmallest = rightNode;
        
//     if(rootSmallest != i)
//     {
//         swap(arr2[i],arr2[rootSmallest]);
        
//         //calling heapify on reduced array with root as rootSmallest
//         heapify(arr2,n,rootSmallest);
//     }
// }

// rearranging array elements to make min heap
// Iterartive approach takes O(log(n)) Time Complexity & O(1) Space Complexity
void heapify(long arr2[],long n,long i)
{
    while(i < n)
    {
        long rootSmallest = i;
        long leftNode = 2 * i + 1;
        long rightNode = 2 * i + 2;
        
        if(leftNode < n && arr2[leftNode] < arr2[i])
            rootSmallest = leftNode;
    
        if(rightNode < n && arr2[rightNode] < arr2[i])
            rootSmallest = rightNode;
            
        if(rootSmallest != i)
        {
            swap(arr2[i],arr2[rootSmallest]);
            
            i = rootSmallest;
        }
        else
            break;
    }
}

// void buildMinHeap(long arr2[],long n)
// {
//     for(long i=n/2-1;i>=0;--i)
//         heapify(arr2,n,i);
// }

int main()
{
    long t; // number of test case
    scanf("%ld",&t);
    
    while(t--)
    {
        long m; // m---> number of elements in first array
        long n; // n---> number of elements in second array
        
        scanf("%ld %ld",&m,&n);
        
        long arr1[m],arr2[n];
        
        for(long i=0;i<m;++i)
            scanf("%ld",&arr1[i]);
            
        for(long j=0;j<n;++j)
            scanf("%ld",&arr2[j]);
        
        // Making Min Heap of second array
        //buildMinHeap(arr2,n); // O(n) Time Complexity
        
        //No need to build heap as sorted array is already a min heap
        
        
        //Iterating the first array
        for(long i=0;i<m;++i) // m*log(n) Time Complexity
        {
            if(arr1[i] > arr2[0])
            {
                swap(arr1[i],arr2[0]);
                
                //calling heapify on arr2 with new root
                heapify(arr2,n,0);
            }
        }
        
        // Now sort the Min Heap (second array)
        sort(arr2,arr2 + n); // O(n*log(n)) Time Complexity
        
        // Printing the answers
        for(long i=0;i<m;++i)
            printf("%ld ",arr1[i]);
            
        for(long j=0;j<n;++j)
            printf("%ld ",arr2[j]);
        printf("\n");
    }
    
	return 0;
}