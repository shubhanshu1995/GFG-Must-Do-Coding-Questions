// Problem Link: https://practice.geeksforgeeks.org/problems/rod-cutting/0

// Using Bottom Up Approach ( Tabulation )

// Rod Cutting ------> Variation of Unbounded Knapsack

// Time Complexity: O(N*W).
// where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
// Space Complexity: O(N*W).
// The use of 2-D array of size ‘N*W’.

#include<bits/stdc++.h>
using namespace std;

int rodCutting(int L, int n, int length[], int price[])
{
   // t[sizeofarray+1][lengthofrod+1]    
   int t[n+1][L+1]; // 2D array for storing subproblems result
   
   // Base Case initialization for L=0
   for(int i=0;i<L+1;++i)
    t[i][0] = 0;
    
   // Base Case initialization for n=0
   for(int j=0;j<n+1;++j)
    t[0][j] = 0;
   
   for(int i=1;i<n+1;++i)
    for(int j=1;j<L+1;++j)
    {
        if(length[i-1] <= j)
            t[i][j] = max((price[i-1] + t[i][j-length[i-1]]),t[i-1][j]);
        else if(length[i-1] > j)
            t[i][j] = t[i-1][j];
    }
    
   return t[n][L];
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    while(T--)
    {
       int L; // lenght of rod
       cin >> L;
       
       int length[L]; //length array
       int price[L]; //price array
       
       for(int i=0;i<L;++i)
       {
           length[i]=i+1;
           cin >> price[i];
       }
        
       int max_possible_val = rodCutting(L, L, length, price);
        
       cout << max_possible_val << endl;
    }
  return 0;
}