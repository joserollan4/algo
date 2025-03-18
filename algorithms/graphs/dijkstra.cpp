const int N = 3e5;
const ll inf = 9e18;

vector<vector<pair<ll,ll>>> adj(N);
vector<ll> dis(N,inf);
vector<int> path(N,-1);
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
        vis[a] = true;
        
        for (auto &u:adj[a]) {
            ll b = u.first, w = u.second;
            ll d = dis[a] + w;
            if (d < dis[b]) {
                dis[b] = d;
                path[b] = a;
                ll nd = -dis[b];
                p.push({nd,b});
            }   
        }   
    }   
}   

/*
vector<int> restore(int source, int end) {
    vector<int> ans;
    for (int node=end; node!=s; node=path[node]) {
        ans.push_back(node);
    }
    ans.push_back(source);
    reverse(ans.begin(),ans.end());
    return ans;
}
*/
