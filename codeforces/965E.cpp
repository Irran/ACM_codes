#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <ctime>
#include <numeric>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 100000 + 10;

// Trie
const int sigma_size = 26;
int ch[maxn][sigma_size];
int sz;
bool is_word[maxn];

void init(){
    memset(ch[0], 0, sizeof(ch[0]));
    sz = 1;
}

int id(char c){
    return c - 'a';
}

void insert(char * wd){
    int len = (int)strlen(wd);
    int u = 0;
    for(int i=0;i<len;i++){
        int c = id(wd[i]);
        if(!ch[u][c]){
            memset(ch[sz], 0, sizeof(ch[sz]));
            is_word[sz] = false;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    is_word[u] = true;
}

void merge_set(multiset<int>& lhs,multiset<int>& rhs){
    for(int d : rhs)
        lhs.insert(d);
}


multiset<int> solve(int u,int depth){
    multiset<int> ret;
    for(int c=0;c<sigma_size;c++){
        if(ch[u][c]){
            multiset<int> temp = solve(ch[u][c], depth+1);
            merge_set(ret, temp);
        }
    }
    if(is_word[u]){
        ret.insert(depth);
    }else if(depth){
        ret.erase(--ret.end());
        ret.insert(depth);
    }
    return ret;
}




int main(int argc, const char * argv[]) {

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    int n;
    char buf[100000];
    init();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",buf);
        insert(buf);
    }
    multiset<int> ret = solve(0,0);
    int ans = accumulate(ret.begin(), ret.end(), 0);
    printf("%d\n",ans);
    


    return 0;
}




