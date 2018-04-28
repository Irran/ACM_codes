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
#include <numeric>

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 5000000 + 10;

/**
 * 刘汝佳 训练指南P210
 */

/**
 * First, we store all words in a Trie tree.
 * Since that there're too many words, left-son right-sibling notation is used to save memory space.
 * Then, we calculate the answer recursively.
 * Consider these two words. "than" "then"
 * Each common node we go through will result 2 comparison.         -- part1
 * Then 1 comparison is need to distinguish them.                   -- part2
 * Hence, ecah time we go through a node 'u', we add 'ans' by num[u]*(num[u]-1).                                -- part1
 * Also, we should iterate through all child nodes, and add 'ans' by the product of each combination of them.   -- part2
 * What's more, if node 'u' represents a word, we also have to distinguish it from all child nodes.     -- part3
 * 'ans' should add by '(num[u]-num_word[u])*num_word[u]'                                               -- part3
 * Pay Attention! if there are two words that are completly identical, they have to compare their '\0'! -- part4
 * That's why we calculate 'num_word[u]*(num_word[u]-1);'                                               -- part4
 */


int ch[maxn][2];        // left-son right-sibling notation
bool is_word[maxn];     // whether this node represent a word
char c[maxn];           // char represented by this node
int num[maxn];          // number of word nodes that are descendant of this nodes(including this node itself)
int num_word[maxn];     // number of words this node represents(number of duplicate words)
int sz = 1;
ll ans = 0;

void init(){
    memset(is_word, 0, sizeof(is_word));
    memset(c, 0, sizeof(c));
    memset(num, 0, sizeof(num));
    memset(num_word, 0, sizeof(num_word));
    memset(ch[0], 0, sizeof(ch[0]));
    sz = 1;
    ans = 0;
}

void insert(char* word){
    int u = 0;
    for(int i=0;word[i]!='\0';i++){
        if(!ch[u][0]){
            memset(ch[sz], 0, sizeof(ch[sz]));
            c[sz] = word[i];
            ch[u][0] = sz++;
        }
        int child = ch[u][0];
        bool is_find = true;
        while(c[child] != word[i]){
            if(ch[child][1] != 0){
                child = ch[child][1];
            }else{
                is_find = false;
                break;
            }
        }
        if(!is_find){
            memset(ch[sz], 0, sizeof(ch[sz]));
            c[sz] = word[i];
            ch[child][1] = sz++;
            child = ch[child][1];
        }
        u = child;
        num[u]++;
    }
    is_word[u] = true;
    num_word[u]++;
}

void solve(int u){
    ans += num[u] * (num[u] - 1);                       // part1
    if(is_word[u]){
        ans += (num[u] - num_word[u]) * num_word[u];    // part3
        ans += num_word[u] * (num_word[u]-1);           // part4
    }
    if(ch[u][0]){
        int child = ch[u][0];
        vector<int> nums;
        nums.push_back(num[child]);
        solve(child);
        while(ch[child][1] != 0){
            child = ch[child][1];
            nums.push_back(num[child]);
            solve(child);
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                ans += nums[i] * nums[j];               // part2
            }
        }
        
    }
}


int main(int argc, const char * argv[]) {
    
//    freopen("input.txt", "r", stdin);

    int n;
    char buf[1010];
    int kase = 0;
    while(scanf("%d",&n) == 1 && n){
        init();
        for(int i=0;i<n;i++){
            scanf("%s",buf);
            insert(buf);
        }
        solve(0);
        printf("Case %d: %lld\n",++kase,ans);
    }
    
    
    return 0;
}


