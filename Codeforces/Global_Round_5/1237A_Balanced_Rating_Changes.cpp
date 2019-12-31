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
	int a[n];
	For(i,0,n) cin >> a[i];
	int b[n];
	For(i,0,n) b[i] = abs(a[i] / 2) * (a[i] < 0 ? -1 : 1);
	int mod[n];
	For(i,0,n) {
		if (abs(a[i]) % 2 == 0) {
			mod[i] = 0;
			continue;
		}
		if (a[i] < 0) mod[i] = 1;
		else mod[i] = 2;
	}
	int sum = 0;
	For(i,0,n) sum += b[i];
	For(i,0,n) {
		if (sum == 0) break;
		if (sum > 0) {
			if (mod[i] == 1) {
				b[i]--;
				sum--;
			}
		} else {
			if (mod[i] == 2) {
				b[i]++;
				sum++;
			}
		}
	}
	For(i,0,n) cout << b[i] << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}