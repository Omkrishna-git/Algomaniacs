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

bool isPunish(int num) {
    int square = num * num;
    string s = to_string(square);
    int n = s.length();

    for (int i = 0; i < (1 << (n - 1)); ++i) {
        int sum = 0, part = 0;
        for (int j = 0; j < n; ++j) {
            part = part * 10 + (s[j] - '0');

            if (i & (1 << j) || j == n - 1) {
                sum += part;
                part = 0;
            }
        }
        if (sum == num) return true;
    }
    return false;
}

bool partition(int num){
    int sqrt = num * num;
    string s = to_string(sqrt);
    int n = s.length();
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (isPunish(i)) {
            ans += (i * i);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    omkrishna(10);
    
    int T = 1;
    
    while (T--) {
        solve();
    }

    return 0;
}
