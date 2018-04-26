#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 100000 + 10;

int A[maxn];
int ans = INF;
int w,l;

int main(int argc, const char * argv[]) {
    
//    freopen("input.txt", "r", stdin);

    scanf("%d %d",&w,&l);
    for(int i=1;i<=w-1;i++){
        scanf("%d",A+i);
    }
    int cur = 0;
    for(int i=1;i<=l;i++)
        cur += A[i];
    ans = min(ans,cur);
    for(int i=l+1;i<=w-1;i++){
        cur += A[i];
        cur -= A[i-l];
        ans = min(ans,cur);
    }
    printf("%d\n",ans);
    
    
    return 0;
}


