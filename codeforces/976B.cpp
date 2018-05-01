#include <iostream>

using namespace std;
typedef long long ll;


int main(){
//    freopen("input.txt", "r", stdin);

    ll n,m,k;
    cin>>n>>m>>k;
    ll ans_x,ans_y;
    if(k < n){
        ans_y = 1;
        ans_x = 1 + k;
    }else{
        k -= n-1;
        ll turns = k / (m-1);
        ll reminder = k % (m-1);
        if(reminder == 0){
            ans_x = n - turns + 1;
            if(turns % 2 == 1)
                ans_y = m;
            else
                ans_y = 2;
        }
        else{
            ans_x = n - turns;
            if(turns % 2 == 0)
                ans_y = 1 + reminder;
            else
                ans_y = m+1 - reminder;
        }
    }
    
    cout<<ans_x<<" "<<ans_y<<endl;
    
    return 0;
}
