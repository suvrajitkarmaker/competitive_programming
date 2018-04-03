#include <bits/stdc++.h>
using namespace std;
int a[100000],b[100000],n;
void insertion()
{
    for(int i=1; i<n; i++)
    {
        int key=a[i],ke=b[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            b[j+1]=b[j];
            j--;
        }
        a[j+1]=key;
        b[j+1]=ke;
    }
}
vector<int>x,y,z,r1,r2;
int main()
{
    int ss,te,tp1,tp2;
    scanf("%d",&te);
    for(int q=1; q<=te; q++)
    {
        r1.clear();
        r2.clear();
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&ss);
        n=0;
        while(scanf("%d %d",&tp1,&tp2))
        {
            if(tp1==0 && tp2==0)
                break;

            if(tp2>0 && tp1<ss)
            {
                a[n]=tp1;
                b[n]=tp2;
                n++;
            }
        }
        insertion();
        int st=0,c5=0,rs1=0,rs2=0,ma=-999999999;
        for(int i=0; i<n; i++)
        {
            if(a[i]<=0 && b[i]>=ss && b[i]>ma)
            {
                c5=1;
                ma=b[i];
                rs1=a[i];
                rs2=b[i];
            }
        }
        if(c5==1)
        {
            r1.push_back(rs1);
            r2.push_back(rs2);
        }
        else
        {
            st=0;
            for(int i=0; i<n; i++)
            {
                if(st>=a[i] && st<=b[i])
                {
                    int mx1=-9999999,i1,j1;
                    for(int j=i; j<n; j++)
                    {
                        if(st>=a[j] && st<=b[j])
                        {
                            if(b[j]>mx1)
                            {
                                mx1=b[j];
                                i1=a[j];
                                j1=b[j];
                            }
                        }
                        if(a[j]>st)
                            break;
                    }
                    int c1=0;
                    for(int k=i+1; k<n; k++)
                    {
                        if(mx1>=a[k] && mx1<=b[k])
                        {
                            c1=1;
                            break;
                        }
                    }
                    if(c1==0)
                        break;
                    st=mx1;
                    r1.push_back(i1);
                    r2.push_back(j1);
                    if(r2[r2.size()-1]>=ss)
                        break;
                }
            }
        }
        printf("%d\n",r1.size());
        for(int i=0; i<r1.size(); i++)
        {
            printf("%d %d\n",r1[i],r2[i]);
        }
        if(q<te)
            printf("\n");
    }
}
