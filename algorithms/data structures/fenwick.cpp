struct Fenwick {
    int n;
    vector<ll> bit;
    
    void init(int m) {
        n = m;
        for (int i=0; i<=n; i++) bit.push_back(0);
    }   
    void add(int idx, ll val) {
        for (idx++; idx<=n; idx+=idx&-idx) {
            bit[idx] += val;
        }   
    }   
    void range_add(int l, int r, ll val) {
        add(l,val);
        add(r+1,-val);
    }   
    ll get(int idx) {
        ll res = 0;
        for (idx++; idx>0; idx-=idx&-idx) {
            res += bit[idx];
        }   
        return res;
    }   
};
