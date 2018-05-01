#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 300000 + 10;
struct Itval{
    int id,s,e;
    bool operator< (const Itval& rhs)const{
        if(e == rhs.e)
            return s > rhs.s;
        return e < rhs.e;
    }
};

Itval itval[maxn];


int main(){
//    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        itval[i].id = i;
        scanf("%d %d",&itval[i].s,&itval[i].e);
    }
    sort(itval+1,itval+1+n);
    int x = -1;
    int right_most = -1;
    int y = -1;
    for(int i=1;i<=n;i++){
        if(itval[i].s > right_most){
            right_most = itval[i].s;
            x = itval[i].id;
        }
        if(itval[i].s <= right_most && x != itval[i].id){
            y = itval[i].id;
            break;
        }
    }
    if(y == -1)
        x = -1;
    printf("%d %d\n",x,y);
    

    
    return 0;
}
