//#include <iostream>
//
///**
// * https://www.nowcoder.com/acm/contest/106/K
// */
//
//typedef long long ll;
//using namespace std;
//const int maxn = 100000 + 10;
//int n,k;
//int A[maxn];
//
//bool check(ll length){
//    int cnt = 0;
//    int cur = 0;
//    ll curSum;
//    while(cur < n-1){
//        curSum = 0;
//        while(cur+1 <= n-1 && curSum + A[cur+1] <= length)
//            curSum += A[++cur];
//        if(curSum == 0)
//            return false;
//        cnt++;
//    }
//    if(cnt > k)
//        return false;
//    return true;
//}
//
//ll solve(ll l,ll r){
//    if(l == r)
//        return l;
//    ll m = l + (r-l)/2;
//    if(check(m))
//        return solve(l, m);
//    else
//        return solve(m+1, r);
//}
//
//int main(){
//    //freopen("input.txt", "r", stdin);
//
//    scanf("%d %d",&n,&k);
//    ll sum = 0;
//    for(int i=1;i<=n-1;i++){
//        scanf("%d",A+i);
//        sum += A[i];
//    }
//
//    ll ans = solve(1, sum);
//    printf("%lld\n",ans);
//
//    return 0;
//}

