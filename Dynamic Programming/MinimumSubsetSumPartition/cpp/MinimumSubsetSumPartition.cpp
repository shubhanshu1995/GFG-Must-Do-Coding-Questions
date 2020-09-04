// Problem Link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0

// Using Bottom Up Approach ( Tabulation )

// Minimum Sum Partition ---- Variation of SubSet Sum Problem
// Time Complexity: O(N*Sum).
// Space Complexity: O(N*Sum).

#include<bits/stdc++.h>
using namespace std;

int SubsetSum(int arr[],int Range,int n)
{
   bool t[n+1][Range+1]; // 2D array for storing subproblems result
   
   // Base Case initialization
   for(int j=0;j<Range+1;++j)
    t[0][j] = false; // subset sum is not possible for empty array

   for(int i=0;i<n+1;++i)
    t[i][0] = true; // Zero sum possible for empty subset
   
   for(int i=1;i<n+1;++i)
    for(int j=1;j<Range+1;++j)
    {
        if(arr[i-1] <= j)
            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        else if(arr[i-1] > j)
            t[i][j] = t[i-1][j];
    }
    
  // S1 will take values that are true in last row.
  // Only last row is important.
  // Filter out candidates for S1 from last row in vector
  // Go till halfway
  
  // Range is arr total sum
  // S2 = Range - S1
  // S2 - S1 -----> minimize or
  // Range - 2*S1 ----> minimize
  
//   vector<int> vec;
  
//   for(int j=0;j<=Range/2;++j)
//     if(t[n][j] == true)
//         vec.push_back(t[n][j]);
    
  int mn = INT_MAX;
  
//   for(int i=0;i<vec.size();++i)
//     mn = min(mn,Range - 2*i);

// More efficient way
  for(int j = Range/2;j>=0;--j)
    if(t[n][j] == true)
    {
        mn = Range - 2*j;
        break;
    }
    
   return mn;
}

int main()
{
    int T; // number of test cases
    cin >> T;
    
    while(T--)
    {
       int n; // no. of items
       cin >> n;
       
       int arr[n];
       
       for(int i=0;i<n;++i)
       {
         cin >> arr[i];
       }
       
       int Range = 0;
       
       for(int i=0;i<n;++i)
       {
         Range = Range + arr[i];
       }
       
       // Range is arr total sum
        
       int ans = SubsetSum(arr,Range,n);
       cout << ans << endl;
    }
	return 0;
}