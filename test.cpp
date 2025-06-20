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
#define DEBUG(x) cerr << #x << ": " << x << endl
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



int helper1(int n, vector<int>& dp) {
    dp[1] = 1 ; dp[2] = 2;
    if (dp[n] != -1) return dp[n];
    return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
}

int helper(int n , vector<int>&dp){
    // dp[0] = 0; dp[1] = 1;
    if(n == 0) return 0;
    if(n == 1) return 1;

    if(dp[n] != -1) return dp[n];
    for(int i = 2 ; i < n ; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}



int helperGrid(int i, int j, int n, int m, vector<vector<int>> &dp, vector<vector<int>> &arr) {
    if (i >= n || j >= m) return INT_MAX;
    if (i == n - 1 && j == m - 1) return arr[i][j];
    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = arr[i][j] + min(helperGrid(i + 1, j, n, m, dp, arr), helperGrid(i, j + 1, n, m, dp, arr));
    return dp[i][j];
}

void solve2() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    
    cout << "Minimum Path: " << helperGrid(0, 0, n, m, dp, arr) << endl;
}

void solve() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << helper(n, dp) << endl;
    for(auto &i : dp) cout<<i<<" ";
    cout<<endl;

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