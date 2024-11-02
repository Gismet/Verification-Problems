/**
 * @file minimumDivisor.cpp 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-11-03
 * Problem source: Degree of freedom codeforces 1826 C
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>



using namespace std;

const int N = 1e6 + 100;
vector<int> min_div(N);

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (n == 1 || min_div[n] > m ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    for (int d = 2; d * d < N; ++d) {
        if (min_div[d] == 0) {
            min_div[d] = d;
            for (int i = d * d; i < N; i += d) {
                if (min_div[i] == 0) {
                    min_div[i] = d;
                }
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        if (min_div[i] == 0) {
            min_div[i] = i;
        }
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}