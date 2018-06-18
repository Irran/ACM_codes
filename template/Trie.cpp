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
//const int maxn = 300000 + 10;
//
//
//// Trie
//const int sigma_size = 26;
//int ch[maxn][sigma_size];
//int sz = 1;
//int val[maxn];
//
//void init(){
//    memset(ch[0], 0, sizeof(ch[0]));
//    sz = 1;
//}
//
//int id(char c){
//    return c - 'a';
//}
//
//void insert(char * wd,int v){
//    int len = (int)strlen(wd);
//    int u = 0;
//    for(int i=0;i<len;i++){
//        int c = id(wd[i]);
//        if(!ch[u][c]){
//            memset(ch[sz], 0, sizeof(ch[sz]));
//            val[sz] = 0;
//            ch[u][c] = sz++;
//        }
//        u = ch[u][c];
//    }
//    val[u] = v;
//}
//
//int query(char* wd){
//    int len = (int)strlen(wd);
//    int u = 0;
//    for(int i=0;i<len;i++){
//        int c = id(wd[i]);
//        if(!ch[u][c])
//            return -1; // doesn't exist
//        u = ch[u][c];
//    }
//    return val[u];
//}
//
//
//
//
//
