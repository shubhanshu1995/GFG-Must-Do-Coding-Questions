// Author : Shubhanshu Singh
// Date   : 16-06-2020

/************************************Approach 1 using Sliding Window ( Works only for positive numbers )*******************/
// Time Complexity: O(n)
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long N,Sum;
        
        cin >> N >> Sum;
        
        vector<long long> vec;
        
        for(long long i=0;i<N;++i)
        {
            long long x;
            cin >> x;
            vec.push_back(x); 
        }
            
        long long start = 0;
        
        long long curr_sum = 0;
        
        bool flag = 0;
  
        for (long long i = 0; i < N; i++) { 
            curr_sum = curr_sum + vec[i];
            
            while (curr_sum > Sum ) { 
                curr_sum = curr_sum - vec[start]; 
                start++; 
            } 
      
            if (curr_sum == Sum) { 
                cout << start + 1 << " " << i + 1 << endl; 
                flag = 1;
                break;
            } 
        } 
        
        if( !flag )
            cout << -1 << endl;
        
    }
    return 0;
}