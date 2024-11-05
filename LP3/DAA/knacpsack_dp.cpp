#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

int solve(vi &weight, vi&value, int index, int capacity, vvi& dp){
    if(index==0){
        if(weight[index]<=capacity){
            return value[index];
        }
        else return 0;
    }

    if(dp[index][capacity] !=-1) return dp[index][capacity];
    int include=0,exclude=0;
    if(weight[index]<=capacity){
        include = value[index] + solve(weight,value,index-1,capacity-weight[index],dp);
    }
    exclude = solve(weight,value,index-1,capacity,dp);

    return dp[index][capacity] = max(include,exclude);
}

int main()
{
    vi weight = {2,4,6,9};
    vi value = {10,10,12,18};
    int capacity=15;
    vvi dp(weight.size(),vi(capacity+1,-1));
    int ans = solve(weight,value,weight.size()-1,capacity,dp);
    cout<<ans<<'\n';
    return 0;
}