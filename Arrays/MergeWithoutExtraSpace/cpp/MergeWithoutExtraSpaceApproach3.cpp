/************************************ Using Min Heap from scratch (No STL)*******************************************/

// Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
// Time Complexity: O(n+m)log(m)
// Space Complexity: O(1) 

// I'm implementing iterative version of heapify so space complexity will be O(1).

/*

Algorithm:
-Iterate through first array
-If second[0] < first[counter]:
-swap second[0] and first[counter]
-heapify the second array
-When iteration finished sort the second array

Cost:
- Iteration through the first array takes linear time
- Heapifying takes log(m) time
- Sorting the second array takes m*log(m) time

Therefore:
O(n) = n * log(m) + m * log(m)
     = (n+m) * log(m)
*/

/****************************************NEVER GIVE UP :)*****************************************/

//User function template for C++
class Solution{
public:

    // rearranging array elements to make min heap
    //Iterartive approach takes O(log(m)) Time Complexity & O(1) Space Complexity
    void heapify(int arr2[],int m,int i)
    {
        while(i < m)
        {
            int rootSmallest = i;
            int leftNode = 2 * i + 1;
            int rightNode = 2 * i + 2;
            
            if(leftNode < m && arr2[leftNode] < arr2[rootSmallest])
                rootSmallest = leftNode;
        
            if(rightNode < m && arr2[rightNode] < arr2[rootSmallest])
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
    void merge(int arr1[], int arr2[], int n, int m) {
        // code here
        for(int i=0;i<n;++i)
        {
            if(arr1[i] > arr2[0])
            {
                swap(arr1[i],arr2[0]);
                
                //calling heapify on arr2 with new root
                heapify(arr2,m,0);
            }
        }
        
        sort(arr2,arr2+m); // O(mlogm)
    }
};