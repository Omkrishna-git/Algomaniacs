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


void helper(int idx, string &s, set<string> &ans) {
    if (idx == s.length()) {
        ans.insert(s);
        return;
    }

    unordered_set<char> used;

    for (int i = idx; i < s.length(); i++) {

        if (used.count(s[i]) > 0) continue;
        
        used.insert(s[i]);

        swap(s[idx], s[i]);
        helper(idx + 1, s, ans);
        swap(s[idx], s[i]); 
    }
}

void solve1() {
    string s;
    cin >> s;

    sort(s.begin(), s.end()); 
    set<string> ans;
    helper(0, s, ans);

    cout << ans.size() << endl;
    for (auto &i : ans) {
        cout << i << endl;
    }
}

vector<string>allString;

void backtrack(int idx,int size,vector<int>&freq,string curr){
    if(idx == size){
        allString.push_back(curr);
        return;
    }

    for(int i = 0 ; i < 26 ; ++i){
        if(freq[i] > 0){
            freq[i]--;
            backtrack(idx+1,size,freq,(curr+char(i+'a')));
            freq[i]++;
        }
    }
}

void solve(){
    string s; cin>>s;
    vector<int>freq(26);
    for(auto &i : s) freq[i-'a']++;

    backtrack(0,s.length(),freq,"");

    cout<<allString.size()<<endl;
    for(auto &i : allString) cout<<i<<endl;
}

int32_t main() {
    omkrishna(10);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
