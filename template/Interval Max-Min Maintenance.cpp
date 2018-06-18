//#include <iostream>
//
//using namespace std;
//typedef long long ll;
//const int maxn = 1000000 + 10;
//int n;
//int A[maxn];
//int Lmax[maxn];
//int Rmax[maxn];
//int Lmin[maxn];
//int Rmin[maxn];
//
///**
// * https://www.nowcoder.com/acm/contest/106/I
// */
//
//int main(){
//
//    //    freopen("input.txt", "r", stdin);
//
//    while(scanf("%d",&n) == 1){
//        for(int i=1;i<=n;i++){
//            scanf("%d",A+i);
//            Lmin[i] = Rmin[i] = Lmax[i] = Rmax[i] = i;
//        }
//        for(int i=2;i<=n;i++){
//            int cur=i;
//            while(cur>1 && A[i]>=A[cur-1])
//                cur=Lmax[cur-1];
//            Lmax[i]=cur;
//
//            cur=i;
//            while(cur>1 && A[i]<=A[cur-1])
//                cur=Lmin[cur-1];
//            Lmin[i]=cur;
//        }
//        for(int i=n-1;i>=1;i--){
//            int cur=i;
//            while(cur<n && A[i]>A[cur+1])
//                cur=Rmax[cur+1];
//            Rmax[i]=cur;
//
//            cur=i;
//            while(cur<n && A[i]<A[cur+1])
//                cur=Rmin[cur+1];
//            Rmin[i]=cur;
//        }
//
//
//        ll ans = 0;
//        for(int i=1;i<=n;i++){
//            ans += (ll)(Rmax[i] - i + 1) * (i - Lmax[i] + 1) * A[i];
//            ans -= (ll)(Rmin[i] - i + 1) * (i - Lmin[i] + 1) * A[i];
//        }
//        printf("%lld\n",ans);
//
//    }
//
//    return 0;
//}
//
//
//
//
