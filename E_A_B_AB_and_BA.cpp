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

void solve() {
    string s;
    cin >> s;

    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;

    vector<int> AB_groups, BA_groups;
    int singleA = 0, singleB = 0, totalAB = 0, totalBA = 0;

    int n = s.size();
    int i = 0;

    while (i < n) {
        if (s[i] == 'A') {
            int j = i;
            while (j < n && s[j] == 'A') j++;
            int length = j - i;
            if (length == 1) singleA++;
            else {
                no;
                return;
            }
            i = j;
        } 
        else if (s[i] == 'B') {
            int j = i;
            while (j < n && s[j] == 'B') j++;
            int length = j - i;
            if (length == 1) singleB++;
            else {
                no;
                return;
            }
            i = j;
        } 
        else {
            int j = i;
            string type;
            while (j + 1 < n && (s[j] == 'A' && s[j + 1] == 'B' || s[j] == 'B' && s[j + 1] == 'A')) {
                type += s[j];
                j++;
            }
            type += s[j];

            if (type[0] == 'A' && type.back() == 'B') AB_groups.push_back(type.size() / 2);
            else if (type[0] == 'B' && type.back() == 'A') BA_groups.push_back(type.size() / 2);
            
            i = j + 1;
        }
    }

    if (singleA > a || singleB > b) {
        no;
        return;
    }

    totalAB = totalBA = 0;
    for (int x : AB_groups) totalAB += x;
    for (int x : BA_groups) totalBA += x;

    if (totalAB > ab || totalBA > ba) {
        no;
        return;
    }

    yes;
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
