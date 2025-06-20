#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define uint unsigned long long
#define umap unordered_map
#define endl '\n'
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define oneCount(n) __builtin_popcountll(n)
#define clz(n) __builtin_clz(n)
#define clzLL(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctz(n)
#define ctzLL(n) __builtin_ctzll(n)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// *A.find_by_order(index): Returns iterator to the k-th largest element (0-based index).
// A.order_of_key(key): Returns the count of elements strictly smaller than key.
// *A.lower_bound(key): Iterator to the first element not less than key.
// *A.upper_bound(key): Iterator to the first element greater than key.
// insert: Insert an element.
// erase: Erase an element.

priority_queue<int, vector<int>, greater<int>> minheap;
priority_queue<int> maxheap;

const int mod = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void omkrishna(int precision) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

int helper(int i,int j,int n,int m,vector<vector<int>>arr){
    // Base case
    if(i == n-1 && j == m-1) return arr[i][j];

    if(i < n-1){
        if(j < m-1){
            int right = helper(i,j+1,n,m,arr) + arr[i][j];
            int down = helper(i+1,j,n,m,arr) + arr[i][j];
            return max(right,down);
        }
        else{
            return helper(i+1,j,n,m,arr) + arr[i][j];
        }
    }
    else{
        return helper(i,j+1,n,m,arr) + arr[i][j];
    }
}

void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>arr(n,vector<int>(m));
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            cin>>arr[i][j];
        }
    }

    cout<<helper(0,0,n,m,arr);
}

int32_t main(){

    omkrishna(10);
    
    int T = 1;
    //cin >> T; 
    
    while (T--) {
        solve();
    }

    return 0;
}