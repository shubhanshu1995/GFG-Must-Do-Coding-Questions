/************************************ Using Min Heap in STL *******************************************/

// Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
// Time Complexity: O(n+m)log(m)
// Space Complexity: O(1)

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

class Solution{
public:
    void merge(int arr1[], int arr2[], int n, int m) {
        // code here
        for(int i=0;i<n;++i)
        {
            if(arr1[i] > arr2[0])
            {
                //replaces minimum element with last leaf node & shortens heap range by 1
                pop_heap(arr2,arr2+m,greater<int>()); 
                swap(arr1[i],arr2[m-1]);
                
                //pushes new element & increases heap range by 1
                push_heap(arr2,arr2+m,greater<int>()); //log(m)
            }
        }
        
        sort(arr2,arr2+m); // O(mlogm)
    }
};