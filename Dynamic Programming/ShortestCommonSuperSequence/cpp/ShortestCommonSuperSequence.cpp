/*
Problem Link: https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0

Using Bottom Up Approach ( Tabulation )

Example:
Input:
2
abcd xycd
efgh jghi

Output:
6
6

Constraints:
1 <= T <= 100
1<= |str1|, |str2| <= 100

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string x,string y,int m,int n)
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
        
        string x,y;
        cin >> x >> y;
        
        m= x.size();
        n = y.size();
        
        int length_of_LCS = LCS(x,y,m,n);
        
        //printing length of shortest common SuperSequence
        cout << m + n - length_of_LCS << endl;
    }
	return 0;
}