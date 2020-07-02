// Date   : 02-07-2020

/************************************Using Sum of N natural Numbers*******************************************/
// Time Complexity: O(n)
// Space Complexity: O(1)

/***********************************Drawback***************************************
If the sum of numbers goes beyond maximum allowd integer, then there can be integer overflow 
& we may not get correct answer 
****************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> &vec,int n)
{
    int sum_n = 0;
    int sum_vec = 0;
    
    // calculating sum of n numbers
    sum_n = n * (n + 1) / 2;
        
    // calculating sum of vector elements
    for(int i=0;i<vec.size();++i)
        sum_vec = sum_vec + vec[i];
        
    return sum_n - sum_vec;
}

int main()
{
    //t---> no of test cases
    
    int t;
    cin >> t;
    
    while(t--)
    {
        //n----> size of vector
        int n;
        cin >> n;
        
        vector<int> vec;
        for(int i=0;i<n-1;++i)
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        cout<< findMissingNumber(vec,n) << endl;
    }
    
	return 0;
}