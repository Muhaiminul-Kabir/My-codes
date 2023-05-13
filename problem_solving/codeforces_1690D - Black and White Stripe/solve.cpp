#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; i++)
            w[i] = w[i - 1] + int(s[i - 1] == 'W');
        int result = INT_MAX;
        for (int i = k; i <= n; i++)
            result = min(result, w[i] - w[i - k]);
        cout << result << endl;
    }
}
