#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const int N = 10000000;
vector<bool> sieve(N+10,true);
vector<int> pre(N+1,0);

void sol() {
	int n;
	cin >> n;
	if (n <= 4) {
		cout << 0;
	}
	else {
		int ans = pre[n];
		//cout << ans << ' ';
		if (sieve[n] && sieve[n+2]) {
			ans--;
		}
		if (sieve[n-1] && sieve[n+1]) {
			ans--;
		}
		cout << ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("prime_subtractorization_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	sieve[0] = false;
	sieve[1] = false;
	for (int i=2; i<=N; i++) {
		if (sieve[i] && (ll)i*i<=N) {
			for (int j=i*i; j<=N; j+=i) {
				sieve[j] = false;
			}
		}
	}
	for (int i=N; i<N+10; i++) {
		sieve[i] = false;
	}
	for (int i=2; i<=N; i++) {
		pre[i] = pre[i - 1];
		if (i == 2) {
			pre[i]++;
		}
		else {
			if (sieve[i]) {
				if (sieve[i+2]) {
					pre[i]++;
				}

			}
		}
	}

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
