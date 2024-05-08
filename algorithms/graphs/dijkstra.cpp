const int N = 3e7;
const ll inf = 9e18;

vector<vector<pair<ll,ll>>> adj(N);
vector<ll> dis(N,inf);
vector<bool> vis(N,false);

void dijkstra(int source) {
    priority_queue<pair<ll,ll>> p;
    dis[source] = 0;
    p.push({0,source});
    
    while (!p.empty()) {
        ll a = p.top().second;
        p.pop();
        if (vis[a]) {
            continue;
        }
        used[a] = true;
        
        for (auto &u:adj[a]) {
            ll b = u.first, w = u.second;
            ll d = dis[a] + w;
            if (d < dis[b]) {
                dis[b] = d;
                ll nd = -dis[b];
                p.push({nd,b});
            }   
        }   
    }   
}   
