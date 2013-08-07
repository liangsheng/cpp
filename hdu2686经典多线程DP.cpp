#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()

using namespace std;
int chh;

typedef long long LL;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;

const int N = 35;

int n;
int g[N][N], dp[N << 1][N][N];

int max(int a, int b, int c, int d) {
    return max(max(max(a, b), c), d);
}

int main() {
    int ans;
    while (~scanf("%d", &n)) {
        FOR (i, 1, n) FOR (j, 1, n) scanf("%d", &g[i][j]);
        memset(dp, 0, sizeof(dp));
        dp[1][1][2] = dp[1][2][1] = g[1][2] + g[2][1];
        FOR (k, 2, 2 * n - 3) {
            FOR (i, 1, k + 1) FOR (j, 1, k + 1) {
                if (i == j || i > n || j > n) continue;
                dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - 1][j] , dp[k - 1][i][j - 1] , dp[k - 1][i - 1][j - 1]);
                dp[k][i][j] += g[i][k + 2 - i] + g[j][k + 2 - j];
            }
        }
        dp[2 * n - 2][n][n] = max(dp[2 * n - 3][n][n - 1], dp[2 * n - 3][n - 1][n]) + g[1][1] + g[n][n];
        cout << dp[2 * n - 2][n][n] << endl;
    }
    return 0;
}
