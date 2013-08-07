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

const int N = 205;

int T, n;
int h[N], a[N], b[N];
int dp[N][N];

int main() {
	int ans, w;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		FOR (i, 1, n) scanf("%d", &h[i]);
		memcpy(a, h, sizeof(h));
		memcpy(b, h, sizeof(h));
		reverse(b + 1, b + n + 1);
		FOR (i, 1, n) {
			w = 0;
			FOR (j, 1, n) {
				dp[i][j] = dp[i - 1][j];
				if (a[i] > b[j]) w = max(w, dp[i - 1][j]);
				if (a[i] == b[j]) dp[i][j] = w + 1;
			}
		}
		ans = 0;
		FOR (i, 1, n) FOR (j, 1, n + 1 - i) {
			if (i + j == n + 1) ans = max(ans, dp[i][j] * 2 - 1);
			else ans = max(ans, dp[i][j] * 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}
