// Author : Shubhanshu Singh
// Date   : 17-06-2020

/************************************Approach 1 using two-pointer technique*******************************************/
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/***************NEVER GIVE UP :) **********************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int N,Sum;
        cin >> N >> Sum;
        
        vector<int> vec;
        for(int i=0;i<N;++i)
        {
            int x;
            cin >> x;
            
            vec.push_back(x);
        }
        
        sort(vec.begin(),vec.end());
        
        bool flag = 0;
        for(int i=0;i<N-2;++i)
        {
            int l = i+1;
            int r = N-1;
            
            while(l < r)
            {
                if(vec[i] + vec[l] + vec[r] == Sum)
                {
                    flag = 1;
                    break;
                }
                else if(vec[i] + vec[l] + vec[r] < Sum)
                    l++;
                else
                    r--;
            }
            
            if(flag)
            {
                cout << 1 <<endl;
                break;
            }
        }
        
        if(!flag)
            cout << 0 << endl; 
    }
	return 0;
}