// Author : Shubhanshu Singh
// Date   : 16-06-2020

/************************************Approach 2 using hashing ( Works only for negative numbers also )*******************/
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long N,S;
        
        cin >> N >> S;
        
        vector<long long> vec;
        
        for(long long i=0;i<N;++i)
        {
            long long x;
            cin >> x;
            vec.push_back(x); 
        }
        
        unordered_map<int,int> mp;
        
        long long currSum = 0;
        bool flag = 0;
        for(long long i=0;i<N;++i)
        {
            currSum = currSum + vec[i];
            
            if( currSum == S )
            {
                cout << 1 << " " << i + 1 << endl; 
                flag = 1;
                break;
            }
                
            if( mp.find(currSum - S) != mp.end() )
            {
                cout << mp[currSum - S]+2 << " " << i + 1 << endl; 
                flag = 1;
                break;
            }
            mp[currSum] = i;
        }
        if(!flag)
            cout<< -1 << endl;
    }
	return 0;
}