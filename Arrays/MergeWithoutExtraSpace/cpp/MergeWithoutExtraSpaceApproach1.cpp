// Date   : 04-07-2020

/************************************Using two pointers*******************************************/
// Time Complexity: O(m) + O(n) + O(nlogn) + O(mlogm)
// Space Complexity: O(1)

/****************************************NEVER GIVE UP :)***************************************/



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
        
        
        int p = m-1;
        int q = 0;
        
        while(p>=0 && q<n) // O(m+n)
        {
            if(arr1[p] > arr2[q])
                swap(arr1[p],arr2[q]);
            else
                break;
            
            p--;
            q++;
        }
        
        sort(arr1,arr1+m);   // O(m*log(m)) Time Complexity
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