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
//
//int T,n,m;
//
///**
// * HDU4825
// */
//
//// 01Trie
//int ch[32*maxn][2];
//int val[32*maxn];
//int sz = 1;
//
//void init(){
//    memset(ch[0], 0, sizeof(ch[0]));
//    sz = 1;
//}
//
//void insert(int x){
//    int u = 0;
//    for(int i=31;i>=0;i--){
//        int c = (x>>i) & 1;
//        if(!ch[u][c]){
//            memset(ch[sz], 0, sizeof(ch[sz]));
//            val[sz] = 0;
//            ch[u][c] = sz++;
//        }
//        u = ch[u][c];
//    }
//    val[u] = x;
//}
//
//int query(int x){
//    int u = 0;
//    for(int i=31;i>=0;i--){
//        int c = (x>>i) & 1;
//        if(ch[u][c^1])
//            u = ch[u][c^1];
//        else
//            u = ch[u][c];
//    }
//    return val[u];
//}
//
//int main(int argc, const char * argv[]) {
//    
//    //    freopen("input.txt", "r", stdin);
//    int kase = 0;
//    scanf("%d",&T);
//    while(T--){
//        init();
//        scanf("%d%d",&n,&m);
//        for(int i=0;i<n;i++){
//            int temp;
//            scanf("%d",&temp);
//            insert(temp);
//        }
//        printf("Case #%d:\n",++kase);
//        for(int i=0;i<m;i++){
//            int temp;
//            scanf("%d",&temp);
//            int ans = query(temp);
//            printf("%d\n",ans);
//        }
//    }
//    
//    
//    return 0;
//}
//
//
//
