#include <iostream>
using namespace std;
#include <vector>


//           Q1 => Fibonacci series using dp



int fibMemo(int n,vector<int> &dp){
        // base case
        if( n==0 || n==1 ){
            return n;
        }

        // check for this n is function already call if called then return their value
        if(dp[n] != -1){
            return dp[n];
        }

        // 1 case -> store value in dp array for particular value of n
        dp[n] = fibMemo(n-1,dp) + fibMemo(n-2,dp);

        return dp[n];

    }

    int fibUsingTab(int n){
        // create a dp array
        vector<int> dp(n+1,-1);

        // base case ko dp array mn dalo
        dp[0] = 0;
        if(n==0){
            return 0;
        }
        dp[1] = 1;

        // aage ka ans nikalo using recursive relation
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }


    int fibUsingTabSCO(int n){
        // create a dp array
        // vector<int> dp(n+1,-1);

        // base case ko dp array mn dalo
        // dp[0] = 0;
        int prev = 0;
        if(n==0){
            return 0;
        }
        // dp[1] = 1;
        int curr = 1;
        if(n==1){
            return 1;
        }

        int ans;
        // aage ka ans nikalo using recursive relation
        for(int i=2;i<=n;i++){
            ans = prev + curr;
            prev = curr;
            curr = ans;
        }
        return ans;
    } 

    int fib(int n) {
        // making an array of size n initialize with -1
        // vector<int> dp(n+1,-1);
        // int ans = fibMemo(n,dp);
        // return ans;

        // int ans = fibUsingTab(n);
        // return ans;

        int ans = fibUsingTabSCO(n);
        return ans;

    }
};