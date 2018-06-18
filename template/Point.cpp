//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//const int MOD = 1e9 + 7;
//
///**
// * https://www.nowcoder.com/acm/contest/106/G
// */
//
//struct Point{
//    ll x,y;
//    bool operator==(const Point& rhs)const{
//        return x == rhs.x && y == rhs.y;
//    }
//    Point operator+(const Point& rhs)const{
//        return (Point){x+rhs.x,y+rhs.y};
//    }
//    Point operator-(const Point& rhs)const{
//        return (Point){x-rhs.x,y-rhs.y};
//    }
//    // inner product
//    Point operator*(ll a)const{
//        return (Point){x*a,y*a};
//    }
//    ll operator*(const Point& rhs)const{
//        return x*rhs.x + y*rhs.y;
//    }
//};
//
//// 垂心/垂线交点
//bool isOrthocenter(Point a,Point b,Point c,Point o){
//    if((a-b)*(c-o))
//        return false;
//    if((a-c)*(b-o))
//        return false;
//    if((b-c)*(a-o))
//        return false;
//    return true;
//}
//
//// 重心/中线交点
//bool isCentroid(Point a,Point b,Point c,Point o){
//    return (a+b+c) == o*3;
//}
//
//// 外心/垂直平分线交点/外接圆圆心
//bool isCircumcenter(Point a,Point b,Point c,Point o){
//    ll la = (a-o)*(a-o);
//    ll lb = (b-o)*(b-o);
//    ll lc = (c-o)*(c-o);
//    return la == lb && lb == lc;
//}
//
//// a * b = |a| * |b| * sinθ
//// if a*b < 0 a is on the right side of a
//// this property can be used to check if point O is in triangle ABC.
//ll crossProduct(const Point& a,const Point& b){
//    return a.x * b.y - b.x * a.y;
//}
//
//ll quick_pow(ll a,ll b){
//    ll ret = 1;
//    while(b){
//        if(b&1)
//            ret = ret * a % MOD;
//        a = a * a % MOD;
//        b >>= 1;
//    }
//    return ret;
//}
//
//ll inv(ll x){
//    return quick_pow(x, MOD-2);
//}
//
//// 内心/内角平分线交点/内接圆圆心
//bool isIncenter(Point a,Point b,Point c,Point o){
//    ll ta = crossProduct(b-a, o-a) % MOD;
//    ll tb = crossProduct(c-b, o-b) % MOD;
//    ll tc = crossProduct(a-c, o-c) % MOD;
//    if(ta < 0 || tb < 0 || tc < 0)
//        return false; // O isn't in triangle ABC
//    ll la = (ta*ta%MOD * inv((a-b)*(a-b)%MOD) % MOD)%MOD;
//    ll lb = (tb*tb%MOD * inv((c-b)*(c-b)%MOD) % MOD)%MOD;
//    ll lc = (tc*tc%MOD * inv((a-c)*(a-c)%MOD) % MOD)%MOD;
//    return la == lb && lb == lc;
//    
//}
//
//int main(){
//    Point a,b,c,o;
//    scanf("%lld %lld",&a.x,&a.y);
//    scanf("%lld %lld",&b.x,&b.y);
//    scanf("%lld %lld",&c.x,&c.y);
//    scanf("%lld %lld",&o.x,&o.y);
//    if(crossProduct(b-a, c-a) < 0)
//        swap(b, c); // make sure A/B/C goes anticlockwise.
//    bool flag = false;
//    flag |= isOrthocenter(a, b, c, o);
//    flag |= isCentroid(a, b, c, o);
//    flag |= isCircumcenter(a, b, c, o);
//    flag |= isIncenter(a, b, c, o);
//    if(flag)
//        printf("Yes\n");
//    else
//        printf("No\n");
//    
//    
//    return 0;
//}
//
