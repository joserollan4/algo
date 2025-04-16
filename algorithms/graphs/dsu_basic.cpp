// basic disjoint sets union a.k.a. union find
// find_set returns parent node of node v in O(lg n)
// unite "unites" (adds an edge from) a to b in O(lg n)
vector<int> parent;
vector<int> sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
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
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}   
