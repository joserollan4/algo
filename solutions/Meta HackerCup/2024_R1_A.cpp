#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void sol() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}
	double l = 0.0, r = 1000000.0;
	double ans = -1;
	for (int i=0; i<100; i++) {
		double mid = (l + r)/2;
		bool ok = true;
		bool lapas = true;
		double time;
		for (int j=0; j<n; j++) {
			time = ((double)(j+1)) / mid;
			if (a[j] <= time && time <= b[j]) {
				continue;
			}
			else {
				ok = false;
				if (time <= a[j]) lapas = false;
				break;
			}
		}
		if (ok) {
			r = mid;
			ans = mid;
		}
		else {
			if (lapas) {
				// kulang speed
				l = mid;
			}
			else {
				r = mid;
			}
		}
	}
	if (ans < 0) {
		cout << -1;
	}
	else {
		cout << fixed << setprecision(10) << ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("subsonic_subway_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int i=1; i<=t; i++) {
		cout << "Case #" << i << ": ";
		sol();
		if (i!=t) {
			cout << '\n';
		}
	}
}
