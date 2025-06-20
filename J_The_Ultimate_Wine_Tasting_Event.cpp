#include <iostream>
#include <string>
using namespace std;

bool canRearrange(int n, const string& s) {
    int count_W_first_n = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            count_W_first_n++;
        }
    }
    return count_W_first_n == (n - count_W_first_n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (canRearrange(n, s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}