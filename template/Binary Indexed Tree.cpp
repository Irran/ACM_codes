//int C[100];
//int n;
//
//int lowbit(int x){
//    return x&-x;
//}
//
//int getSum(int x){
//    int ret = 0;
//    while(x > 0){
//        ret += C[x];
//        x -= lowbit(x);
//    }
//    return ret;
//}
//
//void add(int x,int d){
//    while(x <= n){
//        C[x] += d;
//        x += lowbit(x);
//    }
//}
//
//void change(int x,int from,int to){
//    while(x <= n){
//        C[x] -= from;
//        C[x] += to;
//        x += lowbit(x);
//    }
//}
//

