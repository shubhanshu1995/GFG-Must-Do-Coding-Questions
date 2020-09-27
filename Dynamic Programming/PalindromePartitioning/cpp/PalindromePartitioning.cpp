/*
Problem Link GFG : https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
InterviewBit Link : https://www.interviewbit.com/problems/palindrome-partitioning-ii/

Palindromic Partitioning -------------> Variation of MCM

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".

Using Top Down Approach ( Recursion + Memoization )
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

/***** This code is passing all test cases at interviewbit but not in GFG. Something is wrong with GFG test cases ********/

class Solution{
    
private:
    int t[501][501];
    int palindrome[501][501];
public:
    bool isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
                
            i++;
            j--;
        }
        
        return true;
    }
    
    int solve(string s,int i,int j)
    {
        if(i >= j)
            return 0;
            
        if(t[i][j] != -1)
            return t[i][j];
            
        if(palindrome[i][j] == -1)
        {
            if(isPalindrome(s,i,j) == true)
            {
                return palindrome[i][j] = 0;   
            }
        }
        else
            return palindrome[i][j];
            
        int mn = INT_MAX;
        
        for(int k=i;k<j;++k)
        {
            // int temp = 1 + solve(s,i,k) + solve(s,k+1,j);
            
            //optimization for reducing recursive calls
            int left,right;
            
            if(t[i][k] != -1)
                left = t[i][k];
            else
            {
                left = solve(s,i,k);
                t[i][k] = left;
            }
            
            if(t[k+1][j] != -1)
                right = t[k+1][j];
            else
            {
                right = solve(s,k+1,j);
                t[k+1][j] = right;
            }
            
            int temp = 1 + left + right;
            
            if(temp < mn)
                mn = temp;
        }
        return t[i][j] = mn;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        memset(t,-1,sizeof(t));
        memset(palindrome,-1,sizeof(palindrome));
        
        return solve(str,0,str.size()-1);
    }
};