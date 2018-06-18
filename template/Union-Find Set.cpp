//#include <iostream>
//
///*
// * https://www.nowcoder.com/acm/contest/106/C
// */
//
//using namespace std;
//
//const int maxn = 200000 + 10;
//
//int id[maxn];
//int p[maxn];
//int num[maxn];
//int T,n,q;
//int cur;
//
//int fd(int x){
//    return x == p[x] ? x : p[x] = fd(p[x]);
//}
//
//void init(){
//    for(int i=1;i<=n+q;i++){
//        p[i] = i;
//        id[i] = i;
//        num[i] = 1;
//    }
//    cur = n+1;
//}
//
//void unite(int u,int v){
//    int x = fd(u);
//    int y = fd(v);
//    if(x != y){
//        p[y] = x;
//        num[x] += num[y];
//    }
//}
//
//void del(int u){
//    int x = fd(id[u]);
//    num[x]--;
//    id[u] = cur++;
//}
//
//int main(){
//    
//    //    freopen("input.txt", "r", stdin);
//    
//    scanf("%d",&T);
//    int kase = 0;
//    while(T--){
//        scanf("%d %d",&n,&q);
//        init();
//        printf("Case #%d:\n",++kase);
//        for(int i=0;i<q;i++){
//            int cmd,u,v;
//            scanf("%d",&cmd);
//            if(cmd == 1){
//                scanf("%d %d",&u,&v);
//                unite(id[u], id[v]);
//            }else if(cmd == 2){
//                scanf("%d",&u);
//                del(u);
//            }else if(cmd == 3){
//                scanf("%d",&u);
//                int x = fd(id[u]);
//                printf("%d\n",num[x]);
//            }else{
//                scanf("%d %d",&u,&v);
//                int x = fd(id[u]);
//                int y = fd(id[v]);
//                if(x == y)
//                    printf("YES\n");
//                else
//                    printf("NO\n");
//            }
//        }
//    }
//    
//    return 0;
//}
//
//
