// Problem Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

// Using Bottom Up Approach ( Tabulation )

// Time Complexity: O(N*W).
// where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
// Space Complexity: O(N*W).
// The use of 2-D array of size ‘N*W’.

#include<bits/stdc++.h>
using namespace std;

long long knapsack(long wt[],long val[],long W,long n)
{
   long long t[n+1][W+1]; // 2D array for storing subproblems result
   
   // Base Case initialization for W=0
   for(long long i=0;i<n+1;++i)
    t[i][0] = 0;
    
   // Base Case initialization for n=0
   for(long long i=0;i<W+1;++i)
    t[0][i] = 0;
   
   for(long long i=1;i<n+1;++i)
    for(long long j=1;j<W+1;++j)
    {
        if(wt[i-1] <= j)
            t[i][j] = max((val[i-1] + t[i-1][j-wt[i-1]]),t[i-1][j]);
        else if(wt[i-1] > j)
            t[i][j] = t[i-1][j];
    }
    
   return t[n][W];
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    while(T--)
    {
       long n; // no. of items
       cin >> n;
       long W; // Knapsack capacity
       cin >> W;
       
       long wt[n]; // weight array
       long val[n]; //value array
       
       for(long i=0;i<n;++i)
        cin >> val[i];
        
       for(long i=0;i<n;++i)
        cin >> wt[i];
        
       long long max_possible_val = knapsack(wt,val,W,n);
        
        cout << max_possible_val << endl;
    }
	return 0;
}
