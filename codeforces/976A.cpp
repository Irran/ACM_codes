#include <iostream>

using namespace std;
const int maxn = 100 + 10;
char buf[maxn];

int main(){
//    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d %s",&n,buf);
    
    int cnt_0 = 0;
    int cnt_1 = 0;
    for(int i=0;i<n;i++){
        if(buf[i] == '1')
            cnt_1++;
        else
            cnt_0++;
    }
    
    if(cnt_1 == 0)
        printf("0\n");
    else{
        printf("1");
        for(int i=0;i<cnt_0;i++)
            printf("0");
        printf("\n");
    }
    
    
    return 0;
}
