#include<bits/stdc++.h>
class Stack {
    
public:
      int topp;
    int arr[10000];
    int size;
    Stack(int capacity) {
        topp=-1;
        size=capacity;
    }

    void push(int num) {
        if(topp>=size){
            return;
        }
        arr[++topp]=num;
    }

    int pop() {
        if(topp!=-1){
            return arr[topp--];
        }
        return -1;
    }
    
    int top() {
        if(topp!=-1 and topp<size){
            return arr[topp];
        }
        return -1;
    }
    
    int isEmpty() {
     if(topp==-1)return 1;
        return 0;
    }
    
    int isFull() {
        if(topp>=size)return 1;
        return 0;
    }
    
};