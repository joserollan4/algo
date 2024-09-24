#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void sol() {
	int n, g;
	cin >> n >> g;
	vector<int> v(n);
	for (auto &e:v) cin >> e;
	int low, high, mn = 1e9;
	for (int i=0; i<n; i++) {
		mn = min(mn,abs(v[i]-g));
	}
	low = g - mn;
	high = g + mn;

	int ans1 = 1e9, ans2 = 1e9;
	// case 1: focus sa low
	queue<int> q;
	int mx_sofar = 0;
	for (int i=0; i<n; i++) {
		if (v[i] <= low) {
			q.push(i+1);
			mx_sofar = max(mx_sofar,v[i]);
		}
		else {
			if (!q.empty()) {
				q.push(i+1);
				q.pop();
			}
		}
	}
	if (!q.empty()) ans1 = q.front();

	queue<int> Q;
	mx_sofar = 0;
	for (int i=0; i<n; i++) {
		if (v[i] <= high) {
			Q.push(i+1);
			mx_sofar = max(mx_sofar,v[i]);
		}
		else {
			if (!Q.empty()) {
				Q.push(i+1);
				Q.pop();
			}
		}
	}
	if (!Q.empty()) ans2 = Q.front();

	cout << min(ans1,ans2) << ' ' << mn;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("line_of_delivery_part_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++) {
    	cout << "Case #" << i << ": ";
    	sol();
    	if (i != t) cout << '\n';
    }
}  
