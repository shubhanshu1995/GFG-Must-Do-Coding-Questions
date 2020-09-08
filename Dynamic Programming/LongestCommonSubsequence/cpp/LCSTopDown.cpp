/*
Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

Using Top Down Approach ( Recursion + Memoization )

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;

int t[101][101];

int LCS(string x,string y,int m,int n)
{
    if(m == 0 || n==0)
        return 0;
        
    if(t[m][n] != -1)
        return t[m][n];
        
    if(x[m-1] == y[n-1])
        return t[m][n] = 1 + LCS(x,y,m-1,n-1);
    else
        return t[m][n] = max( LCS(x,y,m,n-1),
                              LCS(x,y,m-1,n));
}

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        memset(t,-1,sizeof(t));
        int m,n;
        cin >> m >> n;
        
        string x,y;
        cin >> x >> y;
        
        int lenght_of_LCS = LCS(x,y,m,n);
        cout << lenght_of_LCS << endl;
    }
	return 0;
}