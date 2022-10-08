/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
*/




// Recursion 

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
            return n;
        return fib(n-1)+fib(n-2);
    }
};





// Naive Approach

class Solution {
public:
    int fib(int n) {
        // Naive Approch
        
        if(n==1 || n==0){
            return n;
        }
        int i = 0;
        int j = 1;
        int fibo =0;
        for(int m=2; m<=n; m++){
            fibo = i+j;
            i = j;
            j = fibo;
        }
        return fibo;
    }
};
