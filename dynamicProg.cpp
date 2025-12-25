#include <bits/stdc++.h>
using namespace std;

//recursion and memoization

int fib(int n , vector<int> &dp){
    if(n <=1)
    return n;

    //step 2
    dp[n] = fib(n-1 , dp) + fib(n-2 , dp);

    return dp[n];

}

//tabulation 

int fib(int n , vector<int> &dp){
    if(n <=1)
    return n;

    //step 2
    for(int i = 2 ; i <= n ; i++){
    dp[n] = dp[n-1] + dp[n-2];

    return dp[n];
    }

}

int main() {
    int n;
    cin >>n;
    // step 1 , creating dp array
    vector<int> dp(n +1);
    for(int i = 0; i<=n ; i++){
        dp[i] = -1;
         cout << fib(n , dp) << endl;

         return 0;
    }
}