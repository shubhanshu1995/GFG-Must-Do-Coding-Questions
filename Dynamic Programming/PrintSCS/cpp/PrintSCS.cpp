/*
Problem Link: https://www.geeksforgeeks.org/print-shortest-common-supersequence/

Printing Shortest Common SuperSequence

Using Bottom Up Approach ( Tabulation )

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y

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

void PrintSCS(string x,string y,int m,int n)
{
    int i=m,j=n;
    string scs = "";
    
    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            scs.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1] > t[i-1][j])
            {
               scs.push_back(y[j-1]);
               j--; 
            }
            // to avoid infinite loop, ccheck for equal to condition also
            else if(t[i-1][j] >= t[i][j-1]) 
            {
                scs.push_back(x[i-1]);
                i--;
            }
        }
    }
    
    while(i>0)
    {
        scs.push_back(x[i-1]);
        i--;
    }
    
    while(j>0)
    {
        scs.push_back(y[j-1]);
        j--;
    }
    reverse(scs.begin(),scs.end());
    
    // Print the scs 
    cout << "SCS of " << x << " and " << y << " is " << scs <<endl;
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
        
        m = x.size();
        n = y.size();
        
        LCS(x,y,m,n);
        PrintSCS(x,y,m,n);
    }
	return 0;
}