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

const int N = 100005, P = 10007;

int T, n;
int h[N], L[N], R[N], a[N], b[N], c[N];

bool judge(int l, int r, int u, int v) {
	if (l < 0 || v >= n) return 0;
	int t1, t2;
	if (l == 0) t1 = a[r] * c[n - 1 - r];
	else t1 = (a[r] - a[l - 1]) * c[n - 1 - r];
	if (v == n - 1) t2 = b[u] * c[u];
	else t2 = (b[u] - b[v + 1]) * c[u];
	return t1 == t2;
}

int main() {
	int ans, l, r, mid;
	c[0] = 1;
	FOR (i, 1, 100002) c[i] = c[i - 1] * P;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		rep (i, n) scanf("%d", &h[i]);
		L[0] = 1, a[0] = h[0];
		FOR (i, 1, n - 1) {
			if (h[i] >= h[i - 1]) L[i] = L[i - 1] + 1;
			else L[i] = 1;
			a[i] = a[i - 1] + h[i] * c[i];
		}
		R[n - 1] = 1, b[n - 1] = h[n - 1]; 
		FORD (i, n - 2, 0) {
			if (h[i] >= h[i + 1]) R[i] = R[i + 1] + 1;
			else R[i] = 1;
			b[i] = b[i + 1] + h[i] * c[n - 1 - i];
		}
		ans = 0;
		rep (i, n) {
			l = 1, r = min(L[i], R[i]);
			while (l != r) {
				mid = (l + r) / 2 + 1;
				if (judge(i - mid + 1, i, i, i + mid - 1)) l = mid;
				else r = mid - 1;
			} 
			ans = max(ans, l * 2 - 1);
		}
		rep (i, n - 1) {
			if (h[i] != h[i + 1]) continue;
			l = 1, r = min(L[i], R[i + 1]);
			while (l != r) {
				mid = (l + r) / 2 + 1;
				if (judge(i - mid + 1, i, i + 1, i + mid)) l = mid;
				else r = mid - 1;
			}
			ans = max(ans, l * 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}
