//// Problem Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

// Using Top Down Approach ( Recursion with Memoization )

// Time Complexity: O(N*W).
// As redundant calculations of states are avoided.
// Space Complexity: O(N*W).
// The use of 2D array data structure for storing intermediate states

#include<bits/stdc++.h>
using namespace std;

long long t[1001][1001]; // 2D array for storing subproblems result

long long knapsack(long wt[],long val[],long W,long n)
{
   if(n==0 || W== 0)
    return 0;
    
   if(t[n][W] != -1)
    return t[n][W];
    
   if(wt[n-1] <= W)
    return t[n][W] = max((val[n-1] + knapsack(wt,val,W-wt[n-1],n-1)),
                         knapsack(wt,val,W,n-1));
   else if(wt[n-1] > W)
    return t[n][W] = knapsack(wt,val,W,n-1);
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    while(T--)
    {
       memset(t,-1,sizeof(t));
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