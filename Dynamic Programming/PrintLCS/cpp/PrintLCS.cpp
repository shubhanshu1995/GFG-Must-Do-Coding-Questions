/*
Problem Link: https://www.geeksforgeeks.org/printing-longest-common-subsequence/

Printing Longest Common Subsequence

Using Bottom Up Approach ( Tabulation )

Eg:

1
6 7
AGGTAB
GXTXAYB

output:
LCS of AGGTAB and GXTXAYB is GTAB

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

void LCS(string x,string y,int m,int n)
{
    // int t[m+1][n+1];
    
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
}

void PrintLCS(string x,string y,int m,int n)
{
    int i=m,j=n;
    string lcs = "";
    
    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            lcs.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;
        }
    }
    
    reverse(lcs.begin(),lcs.end());
    
    // Print the lcs 
    cout << "LCS of " << x << " and " << y << " is " << lcs;
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
        
        LCS(x,y,m,n);
        PrintLCS(x,y,m,n);
    }
	return 0;
}