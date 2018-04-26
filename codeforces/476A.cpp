
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
const int maxn = 100000 + 10;

int k,n,s,p;


int main(int argc, const char * argv[]) {

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    scanf("%d %d %d %d",&k,&n,&s,&p);
    int sheets = n / s;
    if(n % s)
        sheets++;
    sheets *= k;
    int ans = sheets / p;
    if(sheets % p)
        ans++;
    printf("%d\n",ans);



    return 0;
}