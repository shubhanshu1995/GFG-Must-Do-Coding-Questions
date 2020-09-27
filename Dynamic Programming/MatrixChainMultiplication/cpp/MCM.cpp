/*
Problem Link: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

Matrix Chain Multiplication

Using Top Down Approach ( Recursion + Memoization )

Given a sequence of matrices, 
find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, 
but merely to decide in which order to perform the multiplications.

Input: p[] = {10, 20, 30, 40, 30} 
Output: 30000 
There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

int solve(int arr[],int i,int j)
{
    if(i >= j)
        return 0;
        
    if(t[i][j] != -1)
        return t[i][j];
        
    int mn = INT_MAX;
    
    for(int k=i;k<j;++k)
    {
        int temp = solve(arr,i,k) + solve(arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]);
        
        if(temp < mn)
            mn = temp;
    }
    return t[i][j] = mn;
}

int main()
{
    memset(t,-1,sizeof(t));
    
    int arr[] = { 10, 20, 30, 40, 30 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications are "<< solve(arr, 1, n - 1); 
	return 0;
}