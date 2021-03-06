// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	int n;
	cin >> n;
	int a[n - 1];
	For(i,0,n-1) cin >> a[i];
	For(i,0,(n-1)/2) swap(a[i], a[n - 2 - i]);
	int deg[n + 1];
	For(i,0,n+1) deg[i] = 1;
	deg[0] = 0;
	// La raiz tendra una unidad mas de grado al estar conectada  a la fuente
	For(i,0,n-1) deg[a[i]]++;
	std::priority_queue<int, std::vector<int>, std::greater<int> > hojas;
	vii ans;
	// Pusheo las hojas de menor a mayor, pues la ultima arista es la de menor suma
	For(i,0,n+1) if (deg[i] == 1) hojas.push(i);
	For(i,0,n-1) {
		int u = a[i];
		int v = hojas.top();
		hojas.pop();
		ans.pb({u, v});
		deg[u]--;
		deg[v]--;
		if (deg[u] == 1) hojas.push(u);
	}
	cout << a[n - 2] << endl;
	For(i,0,n-1) cout << ans[i].ff << " " << ans[i].ss << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
