//#include <iostream>
//#include <iomanip>
//#include <algorithm>
//#include <string>
//#include <cstring>
//#include <map>
//#include <set>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <cmath>
//#include <climits>
//#include <ctime>
//#include <cctype>
//
//using namespace std;
//typedef long long ll;
//const int INF = 0x3f3f3f3f;
//const double PI = acos(-1.0);
//const int maxn = 100000 + 10;
///**
// * 刘汝佳 训练指南P323
// */
//
//int T,n,m,ans;
//int cnt,ck;
//int low[maxn];
//int dfn[maxn];
//int id[maxn];
//int num[maxn];
//int dp[maxn];
//int deg[maxn];
//bool in_stack[maxn];
//vector<int> graph[maxn],newgraph[maxn];
//stack<int> sk;
//
//void init(){
//    scanf("%d %d",&n,&m);
//    ans = cnt = ck = 0;
//    memset(low, 0, sizeof(low));
//    memset(dfn, 0, sizeof(dfn));
//    memset(id, 0, sizeof(id));
//    memset(num, 0, sizeof(num));
//    memset(dp, 0, sizeof(dp));
//    memset(deg, 0, sizeof(deg));
//    memset(in_stack, 0, sizeof(in_stack));
//    for(int i=0;i<=n;i++){
//        graph[i].clear();
//        newgraph[i].clear();
//    }
//    for(int i=0;i<m;i++){
//        int u,v;
//        scanf("%d %d",&u,&v);
//        graph[u].push_back(v);
//    }
//}
//
//void tarjan(int u){
//    dfn[u] = low[u] = ++ck;
//    in_stack[u] = true;
//    sk.push(u);
//    for(int v : graph[u]){
//        if(!dfn[v]){
//            tarjan(v);
//            low[u] = min(low[u],low[v]);
//        }else if(in_stack[v]){
//            low[u] = min(low[u],dfn[v]);
//        }
//    }
//    if(low[u] == dfn[u]){
//        cnt++;
//        int j;
//        do{
//            j = sk.top();
//            sk.pop();
//            num[cnt]++;
//            id[j] = cnt;
//            in_stack[j] = false;
//        }while(j != u);
//    }
//}
//
//void rebuild(){
//    for(int i=1;i<=n;i++){
//        if(!dfn[i])
//            tarjan(i);
//    }
//    for(int u=1;u<=n;u++){
//        for(int v : graph[u]){
//            if(id[u] != id[v])
//                newgraph[id[u]].push_back(id[v]);
//        }
//    }
//}
//
//void solve(){
//    queue<int> q;
//    for(int u=1;u<=cnt;u++){
//        for(int v : newgraph[u]){
//            deg[v]++;
//        }
//    }
//    for(int i=1;i<=cnt;i++){
//        if(deg[i] == 0){
//            dp[i] = num[i];
//            q.push(i);
//        }
//    }
//    while(!q.empty()){
//        int u = q.front();
//        q.pop();
//        for(int v : newgraph[u]){
//            dp[v] = max(dp[v],num[v] + dp[u]);
//            deg[v]--;
//            if(deg[v] == 0)
//                q.push(v);
//        }
//    }
//    for(int i=1;i<=cnt;i++){
//        ans = max(ans,dp[i]);
//    }
//    printf("%d\n",ans);
//}
//
//
//int main(int argc, const char * argv[]) {
//
////    freopen("input.txt", "r", stdin);
//    scanf("%d",&T);
//    while(T--){
//        init();
//        rebuild();
//        solve();
//    }
//
//    return 0;
//}
//
//
//
//

