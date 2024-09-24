#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void sol() {
	long double n, p;
	cin >> n >> p;
	p /= 100.0;
	long double div = 1.0/n;
	long double ans = p/(pow(p,div)) - p;
	ans *= 100;
	cout << fixed << setprecision(15) << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("line_by_line_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;
    for (int i=1; i<=t; i++) {
    	cout << "Case #" << i << ": ";
    	sol();
    	if (i != t) cout << '\n';
    }
}  
