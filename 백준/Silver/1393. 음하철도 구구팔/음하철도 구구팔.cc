#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    int mod;
    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    while(b!=0){
        mod = a%b;
        a = b;
        b = mod;
    }
    return a;
}

int main()
{
    int xs,ys,xe,ye,dx,dy;
    cin>>xs>>ys>>xe>>ye>>dx>>dy;
    int g = gcd(dx,dy);
    dx/=g; dy/=g;
    int d = (xs-xe)*(xs-xe) + (ys-ye)*(ys-ye);
    while(true){
        xe+=dx;
        ye+=dy;
        int diff = (xs-xe)*(xs-xe) + (ys-ye)*(ys-ye);
        if(d>diff){
            d=diff;
        }
        else
            break;
    }
    printf("%d %d\n",xe-dx,ye-dy);
    return 0;
}