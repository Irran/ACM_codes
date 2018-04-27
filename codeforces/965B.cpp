#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 100 + 10;

char mp[maxn][maxn];
int cnt[maxn][maxn];
int n,k;

bool is_possible_h(int x,int y){
    for(int i=y;i<y+k;i++){
        if(mp[x][i] == '#')
            return false;
    }
    return true;
}

bool is_possible_v(int x,int y){
    for(int i=x;i<x+k;i++){
        if(mp[i][y] == '#')
            return false;
    }
    return true;
}

void addcnt_h(int x,int y){
    for(int i=y;i<y+k;i++){
        cnt[x][i]++;
    }
}

void addcnt_v(int x,int y){
    for(int i=x;i<x+k;i++){
        cnt[i][y]++;
    }
}

int main(int argc, const char * argv[]) {
    
//        freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    
    while(scanf("%d %d",&n,&k) == 2){
        memset(cnt, 0, sizeof(cnt));
        for(int i=1;i<=n;i++){
            scanf("%s",&mp[i][1]);
        }
        for(int i=1;i+k<=n+1;i++){
            for(int j=1;j<=n;j++){
                if(is_possible_v(i,j)){
                    addcnt_v(i, j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j+k<=n+1;j++){
                if(is_possible_h(i,j)){
                    addcnt_h(i, j);
                }
            }
        }
        //        for(int i=1;i<=n;i++){
        //            for(int j=1;j<=n;j++){
        //                cout<<cnt[i][j]<<" ";
        //            }
        //            cout<<endl;
        //        }
        
        int ans = 0;
        int x = 1;
        int y = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cnt[i][j] > ans){
                    ans = cnt[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d\n",x,y);
    }
    
    
    return 0;
}