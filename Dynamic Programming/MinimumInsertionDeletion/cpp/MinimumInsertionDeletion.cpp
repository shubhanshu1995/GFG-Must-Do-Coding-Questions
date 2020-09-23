/*
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

Minimum number of deletions and insertions.

Using Bottom Up Approach ( Tabulation )

Input: str1 = "heap", str2 = "pea"
Output: 3

Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning.

Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/

class Solution{
		

	public:
	
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
    
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    int length_of_LCS = LCS(str1,str2,m,n);
	    
	    int no_of_insertions = m - length_of_LCS;
	    int no_of_deletions = n - length_of_LCS;
	    
	    int total = no_of_insertions + no_of_deletions;
	    
	    return total;
	} 
};