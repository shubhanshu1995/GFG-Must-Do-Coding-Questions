/***************NEVER GIVE UP :) **********************************/
// Author : Shubhanshu Singh
// Date   : 08-08-2020

/************************************Using Auxiliary Vector*******************************************/
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<long> &vec,long n)
{
    long l = 0,r = n-1;
    
    bool flag = true;
    
    vector<long> auxvec(n,0);
    
    for(long i=0;i<n;++i)
    {
        if(flag){
            auxvec[i] = vec[r];
            r--;
        }    
        else{
            auxvec[i] = vec[l];
            l++;
        }            
        flag = !flag;
    }
    
    for(long i=0;i<n;++i)
    {
        vec[i] = auxvec[i];
    }
    
    for(long i=0;i<n;++i)
    {
        cout << vec[i] << " ";
    }
    cout<<endl;
    
}

int main()
{
    int t; //test cases
    scanf("%d",&t);
    
    while(t--)
    {
        long n; // number of elems in array
        scanf("%ld",&n);
        
        vector<long> vec(n,0);
        
        for(long i=0;i<n;++i){
            cin >> vec[i];
        }
        
        rearrange(vec,n);
    }
    
	return 0;
}