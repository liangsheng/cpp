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

const int N = 100005, E = N * 2, INF = ~0U >> 2;

int n, m, d, e;
int head[N], pnt[E], nxt[E];

void init() {
	e = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v) {
	pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

int f[N];
int dd[N][2], du[N];

void get_max(int x, int &y, int &z) {
	if (x > y) z = y, y = x;
	else if (x > z) z = x;
}

void dfs1(int p, int fa) {
	int v;
	if (f[p]) dd[p][0] = 0;
	else dd[p][0] = -INF;
	dd[p][1] = -INF;
	repe (i, p) {
		v = pnt[i];
		if (v == fa) continue;
		dfs1(v, p);
		get_max(dd[v][0] + 1, dd[p][0], dd[p][1]);
	}
}

void dfs2(int p, int fa) {
	int v;
	du[p] = -INF;
	if (fa != -1) {
		if (dd[fa][0] != dd[p][0] + 1) du[p] = max(du[p], dd[fa][0] + 1);
		else  du[p] = max(du[p], dd[fa][1] + 1);
		du[p] = max(du[p], du[fa] + 1);
	}
	repe (i, p) {
		v = pnt[i];
		if (v == fa) continue;
		dfs2(v, p);
	}
}

int main() {
	int x, y, u, ans;
	while (~scanf("%d %d %d", &n, &m, &d)) {
		memset(f, 0, sizeof(f));
		rep (i, m) {
			scanf("%d", &x);
			f[x] = 1;
		}
		init();
		rep (i, n - 1) {
			scanf("%d %d", &x, &y);
			add_edge(x, y), add_edge(y, x);
		}
		dfs1(1, -1);
		dfs2(1, -1);
		ans = 0;
		FOR (i, 1, n) {
			u = max(dd[i][0], du[i]);
			if (u >= 0 && u <= d) ans++;
		}
		printf("%d\n", ans);
	}
    return 0;
}
