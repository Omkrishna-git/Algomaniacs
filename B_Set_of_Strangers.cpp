#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
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

priority_queue<int, vector<int>, greater<int>> minheap;
priority_queue<int> maxheap;

const int mod = 1e9 + 7;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
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

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m));
    umap<int, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;

            if (!mp.count(a[i][j])) mp[a[i][j]] = 0;
            mp[a[i][j]] = max(mp[a[i][j]], (int)1);

            if ((i > 0 && a[i][j] == a[i - 1][j]) || (j > 0 && a[i][j] == a[i][j - 1])) {
                mp[a[i][j]] = 2;
            }
        }
    }
    
    int sum = 0, maxi = 0;
    // for(auto &i : mp){
    //     DEBUG(i.first);
    //     DEBUG(i.second);
    // }
    for (auto &i : mp) {
        sum += i.second;
        maxi = max(maxi, i.second);
    }

    int ans = sum - maxi;
    cout << ans << endl;
}

int32_t main()
{
    omkrishna(10);

    int T = 1;
    cin >> T;
    
    while (T--) {
        solve();
    }

    return 0;
}
