#include <bits/stdc++.h>
using namespace std;
int mn[100]= {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int premn[100]= {0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int leap(long long int n)
{
    if(n<=1752)
    {
        if(n%4==0)
            return 1;
        else
            return 0;
    }
    if(n%4==0)
    {
        if(n%100==0)
        {
            if(n%400==0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}
int lepget1752(int y)
{
    int l1=0,l2=0;
    /*for(int i=1753; i<y; i++)
    {
        if(leap(i)==1)
            l1++;
    }*/
    l1+=1752/4;
    l1+=(y-1)/4-1753/4;
    l1-=(y-1)/100-1753/100;
    l1+=(y-1)/400-1753/400;
    return l1;
}
bool invalid(int m,int d,int y)
{
    int tm=mn[m];
    if(leap(y)==1 && m==2)
        tm=29;
    if(m>12)
        return 1;
    if(d>tm)
        return 1;
    if(d>=3 && d<=13 && m==9 && y==1752)
        return 1;
    return 0;
}
int main()
{
    char month[100][100]= {"dsaf","January","February","March","April","May","June","July","August","September","October","November","December"};
    char day[100][100]= {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    int m,d,y,dy,lep;
    int x;
    while(scanf("%d %d %d",&m,&d,&y))
    {
        if(m==0 && d==0 && y==0)
            break;

        if(invalid(m,d,y)==1)
            printf("%d/%d/%d is an invalid date.\n",m,d,y);
        else
        {
            int x=0;
            if(y>1752)
                x+=lepget1752(y);
            else
                x+=(y-1)/4;
            x+=premn[m-1];
            if((m-1)>=2 && leap(y)==1)
                x++;
            /*for(int i=1; i<=m-1; i++)
            {
                if(i==2 && leap(y)==1)
                {
                    x+=29;
                }
                else
                    x+=mn[i];
            }*/
            x+=((y-1)%7)+d-1;
            if(y>1752  || (y==1752 && m>9)||(y==1752 && m==9 && d>=14))
                x-=11;

            dy=x%7;
            printf("%s %d, %d is a %s\n",month[m],d,y,day[dy]);
        }
    }
}
