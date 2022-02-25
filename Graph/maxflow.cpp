#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 3;

template<class T, int N>
struct MaxFlow{
    const static T finf = (ll)(1e18) + 17;
    const static T feps = 0;

    struct edge {
        T flow, cap;
        int idx, rev, to;
        edge() {}
        edge(int to, int rev, T flow, T cap, int idx): to(to), rev(rev), flow(flow), cap(cap), idx(idx) {}
    };

    vector<edge> adj[N];
    int n, dist[N], po[N];
    int s = N - 2, t = N - 1;

    bool bfs() {
        dist[s] = -1, po[s] = 0;
        dist[t] = -1, po[t] = 0;
        for(int v = 0; v <= n; v++)
            dist[v] = -1, po[v] = 0;

        queue<int> q;
        q.push(s);
        dist[s] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(edge e: adj[u]){
                if(dist[e.to] == -1 && e.flow < e.cap) {
                    dist[e.to] = dist[u] + 1;
                    q.push(e.to);
                }
            }
        }

        return dist[t] != -1;
    }

    T dfs(int u, int t, T fl = finf) {
        if(u == t)
            return fl;

        for(; po[u] < adj[u].size(); po[u]++) {
            auto &e = adj[u][po[u]];
            if(dist[e.to] == dist[u] + 1 && e.flow < e.cap) {
                T f = dfs(e.to, t, min(fl, e.cap - e.flow));
                e.flow += f;
                adj[e.to][e.rev].flow -= f;
                if(f > 0)
                    return f;
            }
        }

        return 0;
    }

    void init(int n) { 
        this->n = n; 
        for(int i = 0; i <= n; i++)
            adj[i].clear();
    }

    void add_edge(int u, int v, T w, int idx = -1) {
        adj[u].push_back(edge(v, adj[v].size(), 0, w, idx));
        adj[v].push_back(edge(u, adj[u].size() - 1, 0, 0, -1));
    }

    T flow() {
        T ret = 0, to_add;
        while(bfs())
            while((to_add = dfs(s, t)))
                ret += to_add;

        return ret;
    }
};