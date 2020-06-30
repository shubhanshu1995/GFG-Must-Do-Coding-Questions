// Date   : 30-06-2020

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
        int N;
        cin >> N;
        
        vector<int> vec;
        for(int i=0;i<N;++i)
        {
            int x;
            cin >> x;
            
            vec.push_back(x);
        }
        
        sort(vec.begin(),vec.end());
        
        int cnt = 0;
        for(int i=N-1;i>=0;--i)
        {
            int l = 0;
            int r = i-1;
            
            while(l < r)
            {
                if(vec[l] + vec[r] == vec[i])
                {
                    cnt++;
                    l++;
                    r--;
                    //break;
                }
                else if(vec[l] + vec[r] < vec[i])
                    l++;
                else
                    r--;
            }
        }
        
        if(!cnt)
            cout << -1 << endl;
        else
            cout << cnt << endl;
    }
    return 0;
}