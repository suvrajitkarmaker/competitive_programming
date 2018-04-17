#include <bits/stdc++.h>
using namespace std;
vector<double>vc;
int main()
{
    int n,te;
    scanf("%d",&te);
    for(int tt=1; tt<=te; tt++)
    {
        scanf("%d",&n);
        vc.clear();
        double x1[n],x2[n],v[n],y,y2;
        for(int i=0; i<n; i++)
        {
            scanf("%lf %lf %lf %lf %lf",&x1[i],&y,&x2[i],&y,&v[i]);
            if(x1[i]>x2[i])
                swap(x1[i],x2[i]);
            vc.push_back(x1[i]);
            vc.push_back(x2[i]);
        }
        sort(vc.begin(),vc.end());
        cout<<vc.size()+1<<endl;
        for(int i=0; i<vc.size(); i++)
        {
            if(i==0)
                printf("-inf %0.3lf 1.000\n",vc[i]);
            else
            {

                double mu=1.0;
                for(int j=0; j<n; j++)
                {
                    if(vc[i-1]>=x1[j] && vc[i]<=x2[j])
                        mu*=v[j];
                }
                printf("%0.3lf %0.3lf %0.3lf\n",vc[i-1],vc[i],mu);

            }
        }
        printf("%0.3lf +inf 1.000\n",vc[vc.size()-1]);
        if(tt!=te)
        printf("\n");
    }
}
