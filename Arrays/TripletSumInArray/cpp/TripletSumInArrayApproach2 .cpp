// Author : Shubhanshu Singh
// Date   : 17-06-2020

/************************************Approach 2 using hashing*******************************************/
// Time Complexity: O(n^2)
// Space Complexity: O(n)

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
        
        bool flag = 0;
        for(int i=0;i<N-2;++i)
        {
            // Find pair in subarray vec[i+1..n-1] 
            // with sum equal to Sum - vec[i]
            
            unordered_set<int> s; 
            int curr_sum = Sum - vec[i];
            for(int j=i+1;j<N;++j)
            {
              if(s.find(curr_sum-vec[j]) != s.end())
              {
                  flag = 1;
                  break;
              }  
              s.insert(vec[j]);
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