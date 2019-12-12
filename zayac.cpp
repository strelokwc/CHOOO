#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n,k,t,p=2;
    vector < vector <int> > a;
    cin>>k>>n;
    a.resize(n+1);
    for (int i=0; i<=n; i++)
        a[i].resize(92);
    a[0][0]=1;
    for (int i=1; i<n+1; i++){
        if (i%3==0)
            p++;
        for (int j=max(0,i-k); j<i; j++) 
            for ( int q=0; q<=min(p,91); q++) {
                t=a[i][q]+a[j][q];
                a[i][q]=t%10;
                if(q!=91)
                a[i][q+1]+=t/10;
            }
    }
    int g=1;
    for (int i=91; i>=0; i--) {
        if (a[n][i]!=0)
            g=0;
        if (g==0)
            cout<<a[n][i];
    }
}
