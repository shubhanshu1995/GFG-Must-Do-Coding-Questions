// Problem Link : https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

// Using Bottom Up Approach ( Tabulation )

// Count of subsets with sum equal to given Sum --- Variation of Subset Sum & Knapsack
// Time Complexity: O(N*Sum).
// Space Complexity: O(N*Sum).

// e.g. :- arr[] = {2, 3, 5}, Sum = 5
// Possible subsets are {2, 3} & {5}
// output count is 2

#include<bits/stdc++.h>
using namespace std;

long countSubsets(long arr[],long Sum,long n)
{
   long t[n+1][Sum+1]; // 2D array for storing subproblems result
   
   // Base Case initialization
   for(long j=0;j<Sum+1;++j)
    t[0][j] = 0; // subset sum is not possible for empty array

   for(long i=0;i<n+1;++i)
    t[i][0] = 1; // Zero sum possible for empty subset
   
   for(long i=1;i<n+1;++i)
    for(long j=1;j<Sum+1;++j)
    {
        if(arr[i-1] <= j)
            t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
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
       long n,Sum; // no. of items & Sum
       cin >> n >> Sum;
       
       long arr[n];
       
       for(long i=0;i<n;++i)
       {
         cin >> arr[i];
       }
       
       long ans = countSubsets(arr,Sum,n);
       
       cout << ans <<endl;
           
    }
	return 0;
}