// basic impl
struct sqrt_decomp {
	int len;
	vector<ll> bin;
	vector<ll> A;
	void init(int n, vector<ll> &a) {
		A = a;
		len = (int)sqrt(n + .0) + 1;
		bin.resize(len);
		for (int i=0; i<n; i++) {
			bin[i/len] += a[i];
		}
	}

	ll query(int l, int r) { // sum from l to r
		ll ans = 0;
		for (int i=l; i<=r; ) {
			if (i % len == 0 && i + len - 1 <= r) {
				ans += bin[i/len];
				i += len;
			}
			else {
				ans += A[i];
				i++;
			}
		}
		return ans;
	}
};
