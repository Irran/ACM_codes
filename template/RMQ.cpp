//#include <algorithm>
//using namespace std;
//int d[100][100];
//int A[100];
//int n;
//
//void RMQ_init(){
//    for(int i=1;i<=n;i++)
//        d[i][0] = A[i];
//    for(int j=1;(1<<j)<=n;j++){
//        for(int i=1;i+(1<<j)-1<=n;i++){
//            d[i][j] = max( d[i][j-1] , d[i+(1<<(j-1))][j-1] );
//        }
//    }
//}
//
//int RMQ_query(int l, int r){
//    if(l > r)
//        return -1; // return impossible value
//    int k = 0;
//    while((1 << (k+1)) <= r-l+1)
//        k++;
//    return max(d[l][k], d[r-(1<<k)+1][k]);
//}
//
//
