#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

typedef long long ll;
typedef long double ld;

void solve(ll n, ll k, vector<ll>& a) {
	// observation: elements can only act around their conjugacy class mod k

	// normalize k to be positive. It's like making all a negative and then shifting them back up above 0, because the operation is independent of the origin location
	if (k<0) {
		ll m=0;
		for (ll i=0; i<n; i++) {
			m=max(m, a[i]);
			a[i]*=-1;
		}
		for (ll i=0; i<n; i++) {
			a[i]+=m; // maps lowest a[i] -> 0
		}
		k*=-1;
		//debug(a, k);
	}
	// sort a so that for each collision, you can resolve it immediately. you can't do better than adding k once to the collision a[i] in the conjugacy class
	sort(a.begin(), a.end());
	// so that checking each class doesn't take O(kn);
	vector<vector<ll>> m(k, vector<ll>(0));
	for (ll i=0; i<n; i++) {
		m[a[i]%k].push_back(a[i]/k); // div by k to normalize
	}
	//debug(m);
	ll cnt=0;
	for (ll i=0; i<k; i++) {
		for (ll j=1; j<(ll)m[i].size(); j++) {
			if (m[i][j-1]>=m[i][j]) {
				cnt+=m[i][j-1]+1-m[i][j];
				m[i][j]=m[i][j-1]+1;
			}
		}
	}
	cout << cnt;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;
	while (t-->0) {
		ll n, k;
		cin >> n >> k;
		vector<ll> a(n);
		for (ll i=0;i<n;i++) cin >> a[i];
		solve(n,k,a);
		cout << '\n';
	}

	return 0;
}
