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

bool is(string &s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (is(s)) {
        cout << 0 << endl; 
        return;
    }
    
    int zero = 0;
    for (char c : s) {
        if (c == '0') zero++;
    }
    
    if (n % 2 == 0) {
        int target = n / 2;
        if (zero == target) cout << 1 << endl;
        else if (abs(zero - target) == 1) cout << 2 << endl;
        else cout << 3 << endl;
    } 
    else {
        int a = n / 2;
        int b = n - a;
        if (zero == a || zero == b) cout << 1 << endl;
        else if (abs(zero - a) == 1 || abs(zero - b) == 1) cout << 2 << endl;
        else cout << 3 << endl;
    }
}

int32_t main() {
    omkrishna(10);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}