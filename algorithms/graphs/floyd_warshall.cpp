// solves all pairs shortest paths (AP-SP) in O(n^3)
ll dist[500][500];
const ll inf = 1e18;

void init(int n) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = inf;
			}
		}
	}
}

void floyd(int n) {
	for (int k=0; k<n; k++) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				ll x = dist[i][k] + dist[k][j];
				if (x < dist[i][j]) {
					dist[i][j] = x;
				}
			}
		}
	}
}
