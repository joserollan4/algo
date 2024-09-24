#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void sol() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (auto &e:v) cin >> e;
	sort(v.begin(),v.end());
	ll tot = v[0];
	for (int i=2; i<n; i++) {
		tot += v[0];
		tot += v[0];
	}
	if (tot <= k) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("walk_the_line_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++) {
    	cout << "Case #" << i << ": ";
    	sol();
    	if (i != t) cout << '\n';
    }
}  
