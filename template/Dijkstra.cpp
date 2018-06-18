#include <vector>
#include <queue>

using namespace std;
const int maxn = 200 + 10;


struct Edge{
    int from,to,cost;
};

struct Node{
    int d,u;
    bool operator<(const Node& rhs)const{
        return d > rhs.d;
    }
};

struct Dijkstra{
    int n,m;
    vector<Edge> edges;
    vector<int> graph[maxn];
    bool is_visited[maxn];
    int d[maxn];
    int p[maxn];
    
    void init(int n){
        this->n = n;
        edges.clear();
        for(int i=0;i<=n;i++)
            graph[i].clear();
        memset(is_visited, 0, sizeof(is_visited));
        memset(d, 0x3f, sizeof(d));
        memset(p, -1, sizeof(p));
    }
    
    void addEdge(int from,int to,int cost){
        edges.push_back((Edge){from,to,cost});
        m = (int)edges.size();
        graph[from].push_back(m-1);
    }
    
    void dijkstra(int s){
        priority_queue<Node> q;
        q.push((Node){0,s});
        d[s] = 0;
        while(!q.empty()){
            Node node = q.top();
            q.pop();
            int u = node.u;
            if(is_visited[u])
                continue;
            is_visited[u] = true;
            for(int i=0;i<graph[u].size();i++){
                Edge& e = edges[graph[u][i]];
                if(d[e.to] > d[e.from] + e.cost){
                    d[e.to] = d[e.from] + e.cost;
                    p[e.to] = e.from;
                    q.push((Node){d[e.to],e.to});
                }
            }
        }
    }
    
}dij;


