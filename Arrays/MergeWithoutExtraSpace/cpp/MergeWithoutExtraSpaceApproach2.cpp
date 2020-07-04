// Date   : 04-07-2020

/************************************ Using Min Heap in STL *******************************************/
// Time Complexity: O(mlogn) + O(nlogn)
// Space Complexity: O(1)

/****************************************NEVER GIVE UP :)*****************************************/


#include<bits/stdc++.h>
using namespace std;


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
        
        //not required as arr2 is already sorted (min heap)
        //make_heap(arr2,arr2+n,greater<long>());
        
        for(long i=0;i<m;++i)
        {
            if(arr1[i] > arr2[0])
            {
                //replaces minimum element with last leaf node & shortens heap range by 1
                pop_heap(arr2,arr2+n,greater<long>()); 
                swap(arr1[i],arr2[n-1]);
                
                //pushes new element & increases heap range by 1
                push_heap(arr2,arr2+n,greater<long>()); //log(n)
            }
        }
        
        
        //Converting into max_heap b'coz sort_heap() on min heap sorts the array in decreasing order
        //This step is O(n)
        //make_heap(arr2,arr2+n); //It's a max_heap
 
	    //This step is O(nlogn)
    	//sort_heap(arr2,arr2+n); //Produces array in increasing order
        
        // O(nlogn)
        sort(arr2,arr2+n);
        
        //Printing the answers
        for(long i=0;i<m;++i)
            printf("%ld ",arr1[i]);
            
        for(long j=0;j<n;++j)
            printf("%ld ",arr2[j]);
        printf("\n");
    }
    
	return 0;
}