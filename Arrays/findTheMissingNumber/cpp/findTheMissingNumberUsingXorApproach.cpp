// Date   : 02-07-2020

/************************************Using XOR*******************************************/
// Time Complexity: O(n)
// Space Complexity: O(1)

/*******************Logic******************************************************************
x1 = A1 ^ A2 ^ A4
x2 = A1 ^ A2 ^ A3 ^ A4

x1 ^ x2 = (A1 ^ A2 ^ A4) ^ (A1 ^ A2 ^ A3 ^ A4)
        = (A1 ^ A1) ^ (A2 ^ A2) ^ (A3) ^ (A4 ^ A4)
        = 0 ^ 0 ^ A3 ^ 0 because {A ^ A = 0}
        = A3

****************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int> &vec,int n)
{
    int xorr1 = 0;
    int xorr2 = 0;
    // calculating xor of n numbers
    for(int i=1;i<=n;++i)
        xorr1 = xorr1 ^ i;
        
    // calculating xor of vector elements
    for(int i=0;i<vec.size();++i)
        xorr2 = xorr2 ^ vec[i];
        
    return xorr1 ^ xorr2;
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