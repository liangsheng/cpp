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
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))

#define bug(x) cout << #x" = " << x << endl
#define bug2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl
#define bug3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl
#define bug4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 105;

int n;
int g[N][N];
int f[N], w[N];

int find(int x) {
	if (f[x] == x) return f[x];
	int p = find(f[x]);
	w[x] ^= w[f[x]];
	return f[x] = p;
}

int main() {
	cout << "Hell" << endl;
	file_r("in.txt");
	int u, v;
	while (~scanf("%d", &n)) {
		memset(g, 0, sizeof(g));
		rep (i, n) {
			while (~scanf("%d", &u)) {
				if (u == 0) break;
				g[i + 1][u] = 1;
			}
		}
		bool flag = 1;
		FOR (i, 1, n) f[i] = i, w[i] = 0;
		FOR (i, 1, n) {
			if (!flag) break;
			FOR (j, i + 1, n) {
				if (g[i][j] && g[j][i]) continue;
				u = find(i), v = find(j);
				if (u == v) {
					if (w[i] == w[j]) {
						flag = 0;
						break;
					}
				} else {
					f[v] = u;
					w[v] = 1 - w[i] ^ w[j];
				}
	    	}
		}
		puts(flag ? "YES" : "NO");
	}
    return 0;
}
