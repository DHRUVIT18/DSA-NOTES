#include<bits/stdc++.h>



//link-https://www.codingninjas.com/codestudio/problems/min-stack_3843991?topList=striver-sde-sheet-problems&leftPanelTab=1


/*let's say we have to push - 3 4 6 2 1

after pushing all elements 
    arr --> [3,4,6,2,1]
    mini--> [3,3,3,2,1]
*/


class minStack
{
	int topp;
    int size;
    int *mini;
    int *arr;

	public:
	
		
		minStack() 
		{ 
            size=10000001;
            topp=-1;
            arr=new int[size];
            mini=new int[size];
            
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			topp++;
            arr[topp]=num;
            if(topp==0){
                mini[topp]=num;
            }else{
                mini[topp]=min(mini[topp-1],num);
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
           if(topp==-1)return -1;
            else{
                return arr[topp--];
            }
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
		    if(topp==-1)return -1;
            else return arr[topp];
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
		 return  (topp==-1)?-1:mini[topp];
		}
};