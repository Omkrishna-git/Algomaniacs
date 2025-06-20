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

const int mod = 1e9 + 7;

void omkrishna(int precision) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

void solve() {
    int n, x;
    cin >> n >> x;
    
    if (n == 1) {
        cout << x << endl;
        return;
    }

    int k = 0;
    while ((1LL << k) - 1 <= x) k++;
    
    k--;

    vector<int> a;

    if (k >= n) {
        for (int i = 0; i < n; i++) a.push_back(i); 
    } 
    else {
        for (int i = 0; i < k; i++) a.push_back(i);
        a.push_back(x);
        while (a.size() < n) a.push_back(0);
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
    cout << endl;
}

int32_t main() {
    omkrishna(10);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
