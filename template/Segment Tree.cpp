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
//const int maxn = 1000000 + 10;
//
///**
// * 刘汝佳 训练指南P201
// */
//
//int r,c,m;
//int A[maxn];
//// result
//int sumv[maxn<<2];
//int minv[maxn<<2];
//int maxv[maxn<<2];
//// mark
//int addv[maxn<<2];
//int setv[maxn<<2];
//// ans
//int _sum,_max,_min;
//
//void init(){
//    memset(setv, -1, sizeof(setv));
//    memset(addv, 0, sizeof(addv));
//}
//
//void pushUp(int rt){
//    sumv[rt] = sumv[rt*2] + sumv[rt*2+1];
//    minv[rt] = min(minv[rt*2],minv[rt*2+1]);
//    maxv[rt] = max(maxv[rt*2],maxv[rt*2+1]);
//}
//
//void build(int rt,int l,int r){
//    if(l == r){
//        sumv[rt] = A[l];
//        maxv[rt] = A[l];
//        minv[rt] = A[l];
//    }
//    else{
//        int m = l + (r-l)/2;
//        build(rt*2, l, m);
//        build(rt*2+1, m+1, r);
//        pushUp(rt);
//    }
//}
//
//
//void pushDown(int rt,int lno,int rno){
//    if(setv[rt] != -1){
//        setv[rt*2] = setv[rt*2+1] = setv[rt];
//        maxv[rt*2] = maxv[rt*2+1] = setv[rt];
//        minv[rt*2] = minv[rt*2+1] = setv[rt];
//        sumv[rt*2] = setv[rt] * lno;
//        sumv[rt*2+1] = setv[rt] * rno;
//        addv[rt*2] = addv[rt*2+1] = 0;
//        setv[rt] = -1;
//    }
//    if(addv[rt]){
//        addv[rt*2] += addv[rt];
//        addv[rt*2+1] += addv[rt];
//        maxv[rt*2] += addv[rt];
//        maxv[rt*2+1] += addv[rt];
//        minv[rt*2] += addv[rt];
//        minv[rt*2+1] += addv[rt];
//        sumv[rt*2] += lno * addv[rt];
//        sumv[rt*2+1] += rno * addv[rt];
//        addv[rt] = 0;
//    }
//}
//
//// segmentation modification for add operation
//void update_add(int rt,int v,int l,int r,int ql,int qr){
//    if(ql <= l && r <= qr){
//        sumv[rt] += (r-l+1) * v;
//        maxv[rt] += v;
//        minv[rt] += v;
//        addv[rt] += v;
//    }else{
//        int m = l + (r-l)/2;
//        pushDown(rt, m-l+1, r-m);
//        if(ql <= m)
//            update_add(rt*2, v, l, m, ql, qr);
//        if(qr > m)
//            update_add(rt*2+1, v, m+1, r, ql, qr);
//        pushUp(rt);
//    }
//}
//
//// segmentation modification for set operation
//void update_set(int rt,int v,int l,int r,int ql,int qr){
//    if(ql <= l && r <= qr){
//        sumv[rt] = v * (r-l+1);
//        maxv[rt] = v;
//        minv[rt] = v;
//        setv[rt] = v;
//        addv[rt] = 0;
//    }else{
//        int m = l + (r-l)/2;
//        pushDown(rt, m-l+1, r-m);
//        if(ql <= m)
//            update_set(rt*2, v, l, m, ql, qr);
//        if(qr > m)
//            update_set(rt*2+1, v, m+1, r, ql, qr);
//        pushUp(rt);
//    }
//}
//
//void query(int rt,int l,int r,int ql,int qr){
//    if(ql <= l && r <= qr){{
//        _sum += sumv[rt];
//        _min = min(_min,minv[rt]);
//        _max = max(_max,maxv[rt]);
//    }
//    }else{
//        int m = l + (r-l)/2;
//        pushDown(rt, m-l+1, r-m);
//        if(ql <= m)
//            query(rt*2, l, m, ql, qr);
//        if(qr > m)
//            query(rt*2+1, m+1, r, ql, qr);
//    }
//}
//
//
//
//

