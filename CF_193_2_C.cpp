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

const int N = 100005;

int n, p, k;
int f[N];
vector<pair<pair<int, int>, int> > q;
set<pair<pair<int, int>, int>  > s;

int main() {
	int a, b;
    while (~scanf("%d %d %d", &n, &p, &k)) {
		q.clear();
		rep (i, n) {
			scanf("%d %d", &a, &b);
			q.pb(mp(mp(-b, a), i + 1));
		}
		sort(ALL(q));
	//	rep (i, n) printf("%d %d\n", q[i].X.Y, -q[i].X.X);
		s.clear();
		rep (i, k) s.insert(mp(mp(q[i].X.Y, -i), q[i].Y));
		FOR (i, k, n - p + k - 1) {
			s.insert(mp(mp(q[i].X.Y, -i), q[i].Y));
			s.erase(s.begin());
		}
	//	repit (it, s) printf("%d\n", (*it).Y);
		memset(f, 0, sizeof(f));
		repit (it, s) printf("%d\n", (*it).Y), f[(*it).Y] = 1;
		a = -1;
		rep (i, n) {
			if (f[q[i].Y]) a = i;
		}
		FOR (i, a + 1, a + p - k) printf("%d\n", q[i].Y);
    }
	return 0;
}
