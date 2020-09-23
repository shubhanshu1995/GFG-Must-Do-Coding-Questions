/*
Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-substring/0

Using Bottom Up Approach ( Tabulation )

Length of Longest Common Substring ------> Variation of LCS

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubstring(string x,string y,int m,int n)
{
    int t[m+1][n+1];
    
    // Base Case Initialization
    for(int j=0;j<n+1;++j)
        t[0][j] = 0;
        
    for(int i=1;i<m+1;++i)
        t[i][0] = 0;
    
    for(int i=1;i<m+1;++i)
        for(int j=1;j<n+1;++j)
            if(x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = 0; // Change is here
    
    int max_val = INT_MIN;
    
    for(int i=0;i<m+1;++i)
        for(int j=0;j<n+1;++j)
            max_val = max(max_val,t[i][j]);
            
    return max_val;
}

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int m,n;
        cin >> m >> n;
        
        string x,y;
        cin >> x >> y;
        
        int substring_length = LongestCommonSubstring(x,y,m,n);
        cout << substring_length << endl;
    }
	return 0;
}