#include <bits/stdc++.h>
using namespace std;
string hudai="--:--:--";
struct qr
{
    int te;
    char pr;
    char tm[100];
    int stm;
    char res[100];
};
bool cmp(qr a,qr b)
{
    return a.stm<=b.stm;
}
int check(int a[],int tm,int b[],int pr)
{
    for(int i=1; i<=tm; i++)
    {
        if(a[i]==0)
            return 1;
        if(a[i]==pr)
            return 1;
    }
    for(int i=1; i<=pr; i++)
    {
        if(b[i]==0)
            return 1;
        if(b[i]==tm)
            return 1;
    }
    return 0;
}
int main()
{
    int team,prob,submi,x,y,z;
    while(scanf("%d %d %d",&team,&prob,&submi))
    {
        if(!team && !prob && !submi)
            break;
        struct qr a[submi];
        string ss;
        for(int i=0; i<submi; i++)
        {
            scanf("%d %c %s %s",&a[i].te,&a[i].pr,a[i].tm,a[i].res);
            sscanf(a[i].tm, "%d:%d:%d", &x,&y,&z);
            a[i].stm=(x*3600)+(y*60)+z;
            if(strcmp(a[i].res,"No")==0)
                getline(cin,ss);
        }
        sort(a,a+submi,cmp);
        int ctem[team+1],cprb[prob+1],inf[team+1][prob+1];
        memset(ctem,0,sizeof(ctem));
        memset(cprb,0,sizeof(cprb));
        memset(inf,0,sizeof(inf));

        int f1=0,f2=0;
        string rs1="--:--:--",rs2="--:--:--";
        for(int i=0; i<submi; i++)
        {
            //printf("%d %c %s %s %d\n",a[i].te,a[i].pr,a[i].tm,a[i].res,a[i].stm);
            if(strcmp(a[i].res,"Yes")==0 && inf[a[i].te][a[i].pr-64]==0)
            {
                inf[a[i].te][a[i].pr-64]=1;
                ctem[a[i].te]++;
                //cout<<"dsaf";
                cprb[a[i].pr-64]++;
            }
            else
                continue;
            if(check(ctem,team,cprb,prob)==0 && f1==0)
            {
                f1=1;
                rs1=a[i].tm;

            }
            if(check(ctem,team,cprb,prob)==1 && f1==1 && f2==0)
            {
                f2=1;
                rs2=a[i].tm;
                break;

            }

        }
        cout<<rs1<<" "<<rs2<<endl;

    }
}
