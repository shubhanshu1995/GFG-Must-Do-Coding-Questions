// Problem Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

// Using Bottom Up Approach ( Tabulation )

// Equal Sum Partition --- Variation of Knapsack
// Time Complexity: O(N*Sum).
// Space Complexity: O(N*Sum).

#include<bits/stdc++.h>
using namespace std;

bool isSubsetSumEqual(long arr[],long Sum,long n)
{
   bool t[n+1][Sum+1]; // 2D array for storing subproblems result
   
   // Base Case initialization
   for(long j=0;j<Sum+1;++j)
    t[0][j] = false; // subset sum is not possible for empty array

   for(long i=0;i<n+1;++i)
    t[i][0] = true; // Zero sum possible for empty subset
   
   for(long i=1;i<n+1;++i)
    for(long j=1;j<Sum+1;++j)
    {
        if(arr[i-1] <= j)
            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        else if(arr[i-1] > j)
            t[i][j] = t[i-1][j];
    }
    
   return t[n][Sum];
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    while(T--)
    {
       long n; // no. of items
       cin >> n;
       
       long arr[n];
       
       for(long i=0;i<n;++i)
       {
         cin >> arr[i];
       }
       
       long Sum = 0;
       
       for(long i=0;i<n;++i)
       {
         Sum = Sum + arr[i];
       }
        
       if(Sum % 2 != 0)
        cout << "NO" << endl;
       else
       {
           bool ans = isSubsetSumEqual(arr,Sum/2,n);
           
           if(ans == true)
            cout << "YES" << endl;
           else
            cout << "NO" << endl;
           
       }
    }
	return 0;
}