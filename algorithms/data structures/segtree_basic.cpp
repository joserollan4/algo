const int MAXN = 2000000;
const int INF = 2e9;

struct Segtree {
    int N;
    vector<int> ar;

    void init(int n) { // initialize segtree with all 0s
        N = 1;
        while (N < n) {
            N *= 2;
        }
        ar.assign(2*N,INF);
    }

    void update(int idx, int val, int tx, int tl, int tr) { 
        if (tr - tl == 1) {
            ar[tx] = val;
            return;
        }
        int mid = (tl + tr) / 2;
        if (idx < mid) {
            update(idx, val, 2*tx + 1, tl, mid);
        }
        else {
            update(idx, val, 2*tx + 2, mid, tr);
        }
        ar[tx] = min(ar[2*tx + 1],ar[2*tx + 2]);
    }

    void update(int idx, int val) { // update v[idx] = val
        update(idx, val, 0, 0, N);
    }

    int minimum(int l, int r, int tx, int tl, int tr) { 
        if (tl >= r || l >= tr) return INF;
        if (tl >= l && tr <= r) return ar[tx];
        int mid = (tl + tr) / 2;
        int mid_left = minimum(l, r, 2*tx + 1, tl, mid);
        int mid_right = minimum(l, r, 2*tx + 2, mid, tr);
        return min(mid_left, mid_right);
    }

    int minimum(int l, int r) { // min(v[i]) for i in [l,r) 
        return minimum(l, r, 0, 0, N);
    }
};
