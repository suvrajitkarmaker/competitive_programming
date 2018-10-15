#include<bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c,d,s;
    int t,cn = 0;
    cin >> t;

    while(t--)
    {
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        s=a;
        s+=b;
        s+=c;
       // a+=b;
        //a+=c;
        if(((a<=56 &&b<=45 && c<=25)||s<=125) && d <= 7)
        {
            cout << 1 << endl;
            cn++;
        }
        else
            cout << 0 << endl;
    }

    cout << cn << endl;


}
