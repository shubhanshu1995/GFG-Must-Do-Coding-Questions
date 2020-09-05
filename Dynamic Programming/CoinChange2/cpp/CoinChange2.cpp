// Problem Link: https://practice.geeksforgeeks.org/problems/number-of-coins/0

// Using Bottom Up Approach ( Tabulation )

// Minimum Number of Coins ------> Variation of Unbounded Knapsack

// Time Complexity: O(N*W).
// where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
// Space Complexity: O(N*W).
// The use of 2-D array of size ‘N*W’.

#include<bits/stdc++.h>
using namespace std;

long long MinimumNumberOfCoins(long CoinsVal[],long Sum,long n)
{
   long long t[n+1][Sum+1]; // 2D array for storing subproblems result
   
   // Base Case initialization for n=0
   for(long long j=0;j<Sum+1;++j)
    t[0][j] = INT_MAX - 1;
    
   // Base Case initialization for Sum=0
   for(long long i=1;i<n+1;++i)
    t[i][0] = 0;
    
   // 2nd row initialization
  for(long long j=1;j<Sum+1;++j)
    if( (j % CoinsVal[0]) == 0)
        t[1][j] = j/CoinsVal[0];
    else
        t[1][j] = INT_MAX - 1;
   
   for(long long i=2;i<n+1;++i)
    for(long long j=1;j<Sum+1;++j)
    {
        if(CoinsVal[i-1] <= j)
            t[i][j] = min(t[i][j-CoinsVal[i-1]] + 1,t[i-1][j]);
        else if(CoinsVal[i-1] > j)
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
       long V; // value of cents
       cin >> V;
       long N; // number of coins
       cin >> N;
      
       long CoinsVal[N]; // Coins value array
       
       for(long i=0;i<N;++i)
        cin >> CoinsVal[i];
        
       long long min_possible_val = MinimumNumberOfCoins(CoinsVal,V,N);
       
       if(min_possible_val == INT_MAX -1)
        cout << -1 << endl; 
       else 
        cout << min_possible_val << endl;
    }
	return 0;
}