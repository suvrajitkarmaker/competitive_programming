#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n,m;
    while(getline(cin,m))
    {
        getline(cin,n);
        int l1=m.size();
        int l2=n.size();
        if(l1==0||l2==0)
        {
            printf("\n");
            continue;
        }
        string s;
        for(int i=0; i<l1; i++)
        {
            for(int j=0; j<l2; j++)
            {
                if(m[i]==n[j])
                {
                    s+=m[i];
                    n[j]='9';
                    break;
                }
            }
        }
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
}
