/*
Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

Longest Repeating Subsequence


Example:

Input:
2 ---> Test Cases

3 ---> string length
abc

5
axxxy

Output:
0
2

Using Bottom Up Approach ( Tabulation )
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;

int LRS(string x,string y,int m,int n) //same code as that of LCS
{
    int t[m+1][n+1];
    
    // Base Case Initialization
    for(int j=0;j<n+1;++j)
        t[0][j] = 0;
        
    for(int i=1;i<m+1;++i)
        t[i][0] = 0;
    
    for(int i=1;i<m+1;++i)
        for(int j=1;j<n+1;++j)
            if(x[i-1] == y[j-1] && i != j) // Change is here
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max( t[i][j-1],
                               t[i-1][j] );
    
    return t[m][n];
}

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int m,n;
        cin >> m;
        
        string x,y;
        cin >> x ;
        
        y = x;
        n = m;
        
        int length_of_LRS = LRS(x,y,m,n);
        cout << length_of_LRS << endl;
    }
	return 0;
}