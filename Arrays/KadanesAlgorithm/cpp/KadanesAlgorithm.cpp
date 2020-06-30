// Date   : 30-06-2020

/************************************Using Dynamic Programming*******************************************/
// Time Complexity: O(n)
// Space Complexity: O(1)

/***************NEVER GIVE UP :) **********************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,N;
    // T : Number of test cases
    // N: Number of elements in array
    cin >> T;
    
    while(T--)
    {
        int N;
        cin >> N;
        
        vector<int> A;
    
        for(int i=0;i<N;++i)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        
        int max_sum = A[0];
        //int min_sum = A[0];
        
        int curr_max_sum = A[0];
        //int curr_min_sum = A[0];
        
        //int total_sum = A[0];
            
        for(int i=1;i<A.size();++i)
        {
            curr_max_sum = max(A[i],curr_max_sum + A[i]);
            max_sum = max(max_sum,curr_max_sum);
            
            //curr_min_sum = min(A[i],curr_min_sum + A[i]);
            //min_sum = min(min_sum,curr_min_sum);
            
            //total_sum += A[i]; 
        }
        
        //logic for maximum sum in circular subarray
        //max_sum > 0 ? cout<< max(max_sum,total_sum - min_sum):cout<<max_sum;
        cout<<max_sum<<endl;     
    }
     return 0;
}