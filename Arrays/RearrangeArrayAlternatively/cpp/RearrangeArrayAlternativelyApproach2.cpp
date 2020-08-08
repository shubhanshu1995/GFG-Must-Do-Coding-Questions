/***************NEVER GIVE UP :) **********************************/
// Author : Shubhanshu Singh

// Date   : 08-08-2020

/************************************Using Auxiliary Vector*******************************************/
// Time Complexity: O(n)
// Space Complexity: O(1)

/****************** Logic Used ******************************************/

/**
    Here, We will store both new value and old value at same position.

    Here, We will use the formula Dividend = Divisor * Quotient + Remainder
    where Divisor = max_element
    Quotient = New number at index i after rearrangement
    Remainder = Old Number at index i before rearrangement
    Dividend = The number stored at index i

    Let's talk about this expression : vec[i] = vec[i] + ( vec[max_index] % max_elem ) * max_elem;

    The purpose of this expression is to store two elements at vec[i]. 
    vec[max_index] is stored as multiplier and “vec[i]” is stored as remainder.

    For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at index 0. 
    With 91, we can get original element as ( 91%10 ) and new element as ( 91/10 ).
**/

#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<long> &vec,long n)
{
    long min_index = 0;
    long max_index = n-1;
    
    long max_elem = vec[max_index] + 1;
    
    
    for(long i=0;i<n;++i)
    {
        if(i%2 == 0){
            vec[i] = vec[i] + ( vec[max_index] % max_elem ) * max_elem;
            max_index--;
        }    
        else{
            vec[i] = vec[i] + ( vec[min_index] % max_elem ) * max_elem;
            min_index++;
        }            
    }
    
    for(long i=0;i<n;++i)
    {
        vec[i] = vec[i] / max_elem;
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