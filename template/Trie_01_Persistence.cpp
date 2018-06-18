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
//int n,m;
//
//
////01Trie
//int ch[maxn*64][2];
//int val[maxn*64];
//int sz = 1;
////Persistence
//int rt[maxn];
//int createdtime[maxn*64];
//
//void init(){
//    memset(ch[0], 0, sizeof(ch[0]));
//    sz = 1;
//}
//
//void insert(int x,int pos){
//    memset(ch[sz], 0, sizeof(ch[sz]));
//    val[sz] = 0;
//    ch[sz][0] = ch[rt[pos-1]][0];
//    ch[sz][1] = ch[rt[pos-1]][1];
//    rt[pos] = sz++;
//
//    int u = rt[pos];
//    for(int i=31;i>=0;i--){
//        int c = (x>>i) & 1;
//        if(!ch[u][c]){
//            memset(ch[sz], 0, sizeof(ch[sz]));
//            val[sz] = 0;
//            ch[u][c] = sz++;
//        }else{
//            memset(ch[sz], 0, sizeof(ch[sz]));
//            val[sz] = 0;
//            ch[sz][0] = ch[ch[u][c]][0];
//            ch[sz][1] = ch[ch[u][c]][1];
//            ch[u][c] = sz++;
//        }
//        u = ch[u][c];
//        createdtime[u] = pos;
//    }
//    val[u] = x;
//}
//
//int query(int l, int r,int x){
//    int u = rt[r];
//    for(int i=31;i>=0;i--){
//        int c = (x>>i) & 1;
//        if(ch[u][c^1] && createdtime[ch[u][c^1]] >= l)
//            u = ch[u][c^1];
//        else
//            u = ch[u][c];
//    }
//    return val[u];
//}
//
//
//
//
