#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<int> parent(100007,-1);
vector<ll> sum_parent(100007,0);
vector<bool> ok(100007,false);

void make_set(int v) {
    parent[v] = v;
}   

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }   
    return parent[v] = find_set(parent[v]);
}   

void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
    }   
}   

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n+1);
    vector<int> p(n);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (auto &e:p) cin >> e;
    
    reverse(p.begin(),p.end());
    ll cur = 0;
    vector<ll> ans;
    ans.push_back(cur);
    for (int i=0; i<n-1; i++) {
        int v = p[i];
        make_set(v);
        ll p_left = 0, p_right = 0;
        if (ok[v - 1]) {
            int pr = find_set(v-1);
            unite(v,v-1);
            p_left = sum_parent[pr];
        }   
        if (ok[v + 1]) {
            int pr = find_set(v+1);
            unite(v,v+1);
            p_right = sum_parent[pr];
        }   
        ll sum = a[v] + p_left + p_right;
        int prt = find_set(v);
        sum_parent[prt] = max(sum_parent[prt],sum);
        cur = max(sum_parent[prt],cur);
        ans.push_back(cur);
        ok[v] = true;
    }   
    reverse(ans.begin(),ans.end());
    for (auto &e:ans) cout << e << '\n';
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
    int t = 1;
    //cin >> t;
    while (t--) {
        sol();
        if (t != 0) cout << '\n';
    }   
}   
