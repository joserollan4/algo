struct Fenwick {
    int n; // size of Fenwick tree
    vector<ll> bit; // Fenwick tree array
    
    void init(int m) { // initialize array
        n = m;
        for (int i=0; i<=n; i++) {
            bit.push_back(0);
        }
    }   
    
    void add(int idx, ll val) { // does a[i] += x
        for (int i=idx+1; i<=n; i+=i&-i) {
            bit[i] += val;
        }   
    }      
    void range_add(int l, int r, ll val) { // does a[i] += x for l <= i <= r
        add(l,val);
        add(r+1,-val);
    }   
    ll get(int idx) { // returns value of a[i]
        ll res = 0;
        for (int i=idx+1; i>0; i-=i&-i) { 
            res += bit[i];
        }   
        return res;
    }   
};
