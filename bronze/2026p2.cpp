#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

typedef long long ll;

void solve(string s) {
	ll n=s.size();
	ll mod=1e9+7;
	ll sum=0;
	ll s2=0;
	ll t=1;
	ll tm1=0;
	bool init=0; // starting string is binary or not
	for (ll i=n-1; i>=0; i--) {
		// works since 0 -> 48 ASCII
		if (s[i]>49) init=1;
		if (s[i]%2==1) {
			sum+=t;
			sum%=mod;
			s2+=tm1;
			s2%=mod;
		}
		if (tm1==0) tm1++;
		else tm1*=2;
		tm1%=mod;
		t*=2;
		t%=mod;
	}
	cout << (init+sum+s2)%mod;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;
	for (ll i=0; i<t; i++) {
		string s;
		cin >> s;
		solve(s);
		cout << '\n';
	}
	return 0;
}
