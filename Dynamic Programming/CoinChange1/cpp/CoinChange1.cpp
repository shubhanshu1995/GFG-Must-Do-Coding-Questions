// Problem Link : https://practice.geeksforgeeks.org/problems/coin-change/0
// Using Bottom Up Approach ( Tabulation )

// Coin Change Problem ( Maximum Number of Ways ) ------> Variation of Unbounded Knapsack & Count of Subsets
// Time Complexity: O(N*Sum).
// Space Complexity: O(N*Sum).

// e.g. :- coinVal[] = {1, 2, 3}, Sum = 5

// We have unlimited supply of coins
// 2 + 3 = 5
// 1 + 2 + 2 = 5
// 1 + 1 + 3 = 5
// 1 + 1 + 1 + 1 + 1 = 5
// 1 + 1 + 1 + 2 = 5

// Maximum number of ways : 5

#include<bits/stdc++.h>
using namespace std;

long CoinChangeWays(long coinsVal[],long Sum,long n)
{
   long t[n+1][Sum+1]; // 2D array for storing subproblems result
   
   // Base Case initialization
   for(long j=1;j<Sum+1;++j)
    t[0][j] = 0; // Not possible to make coins sum because of empty coinsVal array

   for(long i=0;i<n+1;++i)
    t[i][0] = 1; // Zero sum possible for empty array
   
   for(long i=1;i<n+1;++i)
    for(long j=1;j<Sum+1;++j)
    {
        if(coinsVal[i-1] <= j)
            t[i][j] = t[i][j-coinsVal[i-1]] + t[i-1][j];
        else if(coinsVal[i-1] > j)
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
       long n,Sum; // n is size of coin value arr
       cin >> n ;
       
       long coinsVal[n];
       
       for(long i=0;i<n;++i)
       {
         cin >> coinsVal[i];
       }
       
       cin >> Sum;
       
       long ans = CoinChangeWays(coinsVal,Sum,n);
       
       cout << ans <<endl;
           
    }
	return 0;
}