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
typedef unsigned long long ll;
const ll INF = 1e18;
const double PI = acos(-1.0);
const int maxn = 200 + 10;

ll ans = 0;
ll n,k,M,D;


int main(int argc, const char * argv[]) {
    
//    freopen("input.txt", "r", stdin);

    cin>>n>>k>>M>>D;
    
    for(int d=1;d<=D;d++){
        ll x_max = min(M,n/(k*(d-1)+1));
        if((k*(d-1)+1) > INF)
            break;
        ans = max(ans,x_max*d);
    }
    cout<<ans<<endl;
    
    
    return 0;
}


