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

const int N = 200005;
const LL MOD = 1000000007;

int n, m, g;
LL c[N];

LL extend_gcd(LL a, LL b, LL &x, LL &y) {
    LL t, ret;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ret = extend_gcd(b, a % b, x, y);
        t = x;
        x = y;
        y = t - a / b * y;
        return ret;
    }
}

LL cal(LL n, LL m) {
    LL x, y, z;
	if (m == 0 || n == m) return 1;
    z = c[m] * c[n - m] % MOD;
    extend_gcd(z, MOD, x, y);
    if (x < 0) x += (-x) / MOD * MOD;
    while (x < 0) x += MOD;
    return c[n] * x % MOD;
}

LL get(int n, int m) {
	LL ans = 0;
	if (n == 0 && (m <= 1)) return 1;
	if (n == 0 && m == 1) return 1;
	if (n > 0 && m > 0 && n + m > 2) {
		ans = (ans + cal(n + m - 2, n - 1)) % MOD;
	}
	if (n >= 2) ans = (ans + get(n - 2, m)) % MOD;
	return ans;
}

int main() {
	LL ans, tmp;
	c[1] = 1;
	FOR (i, 2, 200000) c[i] = c[i - 1] * i % MOD;
	while (~scanf("%d %d %d", &n, &m, &g)) {
		ans = get(n, m);
		if (g == 1) cout << ans << '\n';
		else {
			tmp = cal(n + m, n);
			cout << (tmp + MOD - ans) % MOD << '\n';
		}
	}
    return 0;
}
