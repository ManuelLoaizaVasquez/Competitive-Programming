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

int main() {
	fastio;
	int n;
	cin >> n;
	string s;
	cin >> s;
	int f[2];
	int a[n];
	For(i,0,n) a[i] = (s[i] == 'B' ? 0 : 1);
	For(i,0,2) f[i] = 0;
	For(i,0,n) f[a[i]]++;
	if (f[0] % 2 == 0 or f[1] % 2 == 0) {
		vi ans;
		int c = (f[0] % 2 == 0 ? 0 : 1);
		For(i,0,n-1) {
			if (a[i] == c) continue;
			ans.pb(i + 1);
			For(j,0,2) a[i + j] ^= 1;
		}
		For(i,0,n-1) {
			if (a[i] == c) {
				ans.pb(i + 1);
				For(j,0,2) a[i + j] ^= 1;
			}
		}
		int k = ans.size();
		cout << k << endl;
		For(i,0,k) cout << ans[i] << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
