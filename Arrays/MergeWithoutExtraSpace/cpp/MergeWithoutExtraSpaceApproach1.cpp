// Date   : 04-07-2020

/************************************Using two pointers*******************************************/
// Time Complexity: O(m) + O(n) + O(nlogn) + O(mlogm)
// Space Complexity: O(1)

/****************************************NEVER GIVE UP :)***************************************/

//User function template for C++
class Solution{
public:
    void merge(int arr1[], int arr2[], int n, int m) {
        // code here
        int p = n-1;
        int q = 0;
        
        while(p>=0 && q<m) // O(min(n,m))
        {
            if(arr1[p] > arr2[q])
                swap(arr1[p],arr2[q]);
            else
                break;
            
            p--;
            q++;
        }
        
        sort(arr1,arr1+n);   // O(n*log(n)) Time Complexity
        sort(arr2,arr2 + m); // O(m*log(m)) Time Complexity
    }
};