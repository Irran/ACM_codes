#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
#include <cstdio>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 200000 + 10;

/**
 * Basically, the idea is to traverse the whole tree structure,
 * after finding an even degree node, destroyed it.
 * However, the order of traversal is important.
 * To make sure we get the right answer,
 * we HAVA to destroy node in order from leaf up to root.(kinds of greedy algorhthm)
 * Obviously, dfs will fit this requirement.
 */

vector<int> graph[maxn];
vector<int> ans; // order of nodes destroyed
int n;
int degree[maxn];
bool is_destroyed[maxn];
int destroyed; // number of nodes that has been destroyed


// can only destroy descandent nodes
void des(int u,int fa){
    if(is_destroyed[u])
        return;
    if(degree[u] % 2 == 1)
        return;
    ans.push_back(u);
    destroyed++;
    degree[u] = 0;
    degree[fa]--;
    is_destroyed[u] = true;
    for(int v : graph[u]){
        if(v != fa){
            degree[v]--;
            des(v,u);
        }
    }
}

void dfs(int u,int fa){
    for(int v : graph[u]){
        if(v != fa){
            dfs(v,u);
        }
    }
    if(degree[u] % 2 == 0){
        des(u, fa); 
    }
}

int main(int argc, const char * argv[]) {
    
//    freopen("input.txt", "r", stdin);
    
    scanf("%d",&n);
    int v;
    for(int u=1;u<=n;u++){
        scanf("%d",&v);
        if(v){
            degree[u]++;
            degree[v]++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    dfs(1,0);
    if(n == destroyed){
        printf("YES\n");
        for(int u : ans)
            printf("%d\n",u);
    }else{
        printf("NO\n");
    }
    return 0;
}


