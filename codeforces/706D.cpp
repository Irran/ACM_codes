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

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 200000 + 10;

int q;

//01Trie
int ch[maxn*32][2];
int val[maxn*32];
int num[maxn*32];
int sz;

void init(){
    memset(ch[0], 0, sizeof(ch[0]));
    sz = 1;
}

void insert(int x){
    int u = 0;
    for(int i=31;i>=0;i--){
        int c = (x>>i) & 1;
        if(!ch[u][c]){
            memset(ch[sz], 0, sizeof(ch[sz]));
            val[sz] = 0;
            num[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
        num[u]++;
    }
    val[u] = x;
}

void rm(int x){
    int u = 0;
    for(int i=31;i>=0;i--){
        int c = (x>>i) & 1;
        u = ch[u][c];
        num[u]--;
    }
}

int query(int x){
    int u = 0;
    for(int i=31;i>=0;i--){
        int c = (x>>i) & 1;
        if(ch[u][c^1] && num[ch[u][c^1]] > 0)
            u = ch[u][c^1];
        else
            u = ch[u][c];
    }
    return val[u];
}


int main(int argc, const char * argv[]) {

//    freopen("input.txt", "r", stdin);
    
    scanf("%d",&q);
    init();
    insert(0);
    for(int i=0;i<q;i++){
        char op;
        int x;
        getchar(); // discard '\n'
        scanf("%c %d",&op,&x);
        if(op == '+')
            insert(x);
        else if(op == '-')
            rm(x);
        else{
            int y = query(x);
            printf("%d\n",x^y);
        }
            
    }
    return 0;
}
