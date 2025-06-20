#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void omkrishna(int precision) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    // Read directed edges representing election constraints
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    // Topological Sorting using Kahn's Algorithm (BFS)
    queue<int> q;
    vector<int> order;

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : adj[node]) {
            if (--in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If topological sorting doesn't include all nodes, cycle exists
    if ((int)order.size() != n) {
        no;
        return;
    }

    // Generate votes using cyclic shifts of the topological order
    yes;
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << order[(i + j) % n] << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    omkrishna(10);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
