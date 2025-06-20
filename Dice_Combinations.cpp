#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void omkrishna(int precision)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

int helper(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];
    int count = 0;

    for (int i = 1; i <= 6; i++){
        count = (count + helper(n - i, dp)) % mod;
    }

    dp[n] = count;

    return dp[n];
}

int tabulation(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;

    for (int i = n; i >= 0; ++i)
    {
        int count = 0;

        for (int i = 1; i <= 6; i++)
        {
            count = (count + dp[n - i]) % mod;
        }
    }

    return dp[0];
}

void solve()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    // cout << helper(n, dp) << endl;

    cout << tabulation(n) << endl;
    // for(auto &i : dp) cout<<i<<" ";
}

int32_t main()
{

    omkrishna(10);

    int T = 1;
    // cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}