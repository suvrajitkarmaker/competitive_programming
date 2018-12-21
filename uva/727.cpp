#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define gcd3(x,y,z)                __gcd(__gcd(x,y),z)
#define INF                     LLONG_MAX
#define inf                     LONG_MAX
#define PI                      (2.0*acos(0.0))
#define Log(b,x)                (log(x)/log(b))
#define all(x)                  (x).begin(), (x).end()
#define Unique(x)               sort(all(x)); x.erase(unique(all(x)), x.end());
#define inttostring(x)          to_string(x)
#define stringtoint(x)          stoll(x)
#define valid(nx,ny,row,col)    nx>0 && nx<=row && ny>0 && ny<=col
#define CLR(x,y)                memset(x,y,sizeof(x));
#define max3(x,y,z)             max(z,max(x,y));
#define min3(x,y,z)             min(z,min(x,y));
#define MP(x, y) make_pair(x, y)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define pii pair< int, int >
#define psi pair< string, int >
#define MAX 100100000
#define eps 1e-15
int ct=0;
int fun(char cr)
{
    if(cr=='*'||cr=='/')
        return 2;
    else if(cr=='+'||cr=='-')
        return 1;
    return -1;
}
void infixtoOpostfix(string s)
{
    stack<char>st;
    st.push('S');
    string res;
    char tc;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            res+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push('(');
        }
        else if(s[i]==')')
        {
            while(st.top()!='S' && st.top()!='(')
            {
                tc=st.top();
                res+=tc;
                st.pop();
            }
            if(st.top()=='(')
            {
                st.pop();
            }
        }
        else
        {
            while(st.top()!='S' && fun(s[i])<=fun(st.top()))
            {
                tc=st.top();
                res+=tc;
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(st.top()!='S')
    {
        tc=st.top();
        res+=tc;
        st.pop();
    }
    if(ct>0)
        printf("\n");
    ct++;
    cout<<res<<endl;
}

int main()
{
//    READ("input.txt");
//     WRITE("output.txt");
    string s;
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    char cr;

    while(t--)
    {

        s.clear();
        while(scanf("%c",&cr)!=EOF)
        {
            if(cr=='\n'||cr==EOF)
                break;
            getchar();
            if(cr=='\n')
                break;
            s+=cr;
        }
        //cout<<s<<endl;
        infixtoOpostfix(s);

    }
}
