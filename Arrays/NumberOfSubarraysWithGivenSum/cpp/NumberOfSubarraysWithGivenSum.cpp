// Author : Shubhanshu Singh
// Date   : 17-06-2020

/************************************using hashing ( Works for negative numbers also )*******************/
// Time Complexity: O(n)
// Space Complexity: O(n)


/***************NEVER GIVE UP :) **********************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        long long N,Sum;
        
        cin >> N;
        
        vector<long long> vec;
        
        for(long long i=0;i<N;++i)
        {
            long long x;
            cin >> x;
            vec.push_back(x); 
        }
        
        cin >> Sum;
        
        unordered_map<int,int> mp;
        
        long long currSum = 0;
        long long cnt = 0;
        for(long long i=0;i<N;++i)
        {
            currSum = currSum + vec[i];
            
            if( currSum == Sum )
                cnt++;  
                
            if( mp.find(currSum - Sum) != mp.end() )
                cnt += mp[currSum - Sum];
            
            mp[currSum]++;
        }
        cout << cnt << endl;
    }
	return 0;
}