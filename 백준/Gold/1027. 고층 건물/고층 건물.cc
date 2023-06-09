#include <iostream>
#include <vector>

using namespace std;

inline double calc(int x1, int y1, int x2, int y2){
    return (double)(y2-y1)/(x2-x1);
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        double max = -2100000000;
        double min = 2100000000;
        int cnt = 0;
        for(int j=i-1;j>=0;j--){
            double h = calc(i,v[i],j,v[j]);
            if(min>h){
                min=h;cnt++;
            }
        }
        for(int j=i+1;j<n;j++){
            double h = calc(i,v[i],j,v[j]);
            if(max<h){
                max=h;cnt++;
            }
        }
        if(ans<cnt) ans = cnt;
    }
    printf("%d\n",ans);
    return 0;
}