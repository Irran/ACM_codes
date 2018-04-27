#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
#include <cstdio>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 1000 + 10;

int arrive[maxn];


int main(int argc, const char * argv[]) {
    
//    freopen("input.txt", "r", stdin);
    
    int n,A,B,C,T;
    while(scanf("%d %d %d %d %d",&n,&A,&B,&C,&T) == 5){
        memset(arrive, 0, sizeof(arrive));
        arrive[0] = 0;
        arrive[n+1] = T;
        for(int i=1;i<=n;i++)
            scanf("%d",arrive+i);
        int ans = 0;
        if(C <= B){
            ans = A * n;
        }else{
            int k = 0;
            for(int i=1;i<=n+1;i++){
                ans += C * k * (arrive[i] - arrive[i-1]);
                k++;
            }
            for(int i=1;i<=n;i++){
                ans += A - (T - arrive[i]) * B;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}


