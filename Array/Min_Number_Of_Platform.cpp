
//greedy 

#include<bits/stdc++.h>


int calculateMinPatforms(int at[], int dt[], int n) {
   int platform=1,result=1;
   int i=1,j=0;
    sort(at, at + n);
    sort(dt, dt + n); 
    
    
    
    while(i<n and j<n){
        if(at[i]<=dt[j]){
            platform++;
            i++;
        }
        else if(at[i]>dt[j]){
            platform--;
            j++;
        }
        
        if(platform>result){
            result=platform;
        }
    }
    return  result;
}