#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long int ll;
const D EPS=1e-8;
const D PI=acos(-1.0);
const D INF = 1e20;
const int N=1e4+14;
int compare(D x)
{
    if(fabs(x)<EPS)
        return 0;
    return x>EPS?1:-1;
}
D square(D x)
{
    return x*x;
}
struct point
{
    D x,y;
    point()
    {
        x=0;
        y=0;
    }
    point(D p,D q)
    {
        x=p;
        y=q;
    }
    void scan() {cin>>x>>y;}
    void print() {cout<<x<<" "<<y<<"\n";}
    bool operator <(point a) const {return compare(a.x-x)==0?compare(y-a.y)<0:x<a.x;}

    point operator + (point p) {return point(p.x+x,p.y+y);}
    point operator - (point p) {return point(x-p.x,y-p.y);}
    point operator * (D v) {return point(x*v,y*v);}
    point operator / (D v) {return point(x/v,y/v);}
    bool operator == (point p) {return (compare(x-p.x)==0 && compare(y-p.y)==0);}
    D dot(point p) {return x*p.x+y*p.y;}
    D cross(point p) {return x*p.y-y*p.x;}
    D distance(point p) {return hypot(x-p.x,y-p.y);}
    point rotateLeft() {return point(-y,x);}
    point rotateRight() {return point(y,-x);}
    D orient(point a, point b, point c) {return (b-a).cross(c-a);}
    D sq(point p) {return p.x*p.x + p.y*p.y;}
    D abs(point p) {return sqrt(sq(p));}
    D angle(point v, point w) {
        double cosTheta = v.dot(w) / abs(v) / abs(w);
        return acos(max(-1.0, min(1.0, cosTheta)));
    }
    D orientedAngle(point a, point b, point c)
    {
        if (orient(a,b,c) >= 0)
            return angle(b-a, c-a);
        else
            return 2*PI - angle(b-a, c-a);
    }
    int orientation(point p, point q, point r)
    {
        int val = (q.y - p.y) * (r.x - q.x) -
                  (q.x - p.x) * (r.y - q.y);

        if (val == 0)
            return 0;
        return (val > 0)? 1: 2;
    }

}pt;


vector<point> hull;
//////////////////////convexhulllognstart/////////////////////
double abs(point p)
{
    return sqrt(pt.sq(p));
}
bool isPivot(point &A,point &B)
{
    if(abs(A.x-B.x)>EPS)
        return A.x<B.x;
    return A.y<B.y;
}
point piv;
bool polarSort(point &A,point &B)
{
    D area=pt.orient(piv, A, B);
    if(abs(area)<EPS)
        return pt.sq(A-piv)<pt.sq(B-piv);
    return area>0;
}
void convexHull_logn(vector<point>& v)
{
    hull.clear();
    int n=v.size();
    if(!n)
        return;
    int pivot=0;
    for(int i=1; i<n; i++)
    {
        if(isPivot(v[i],v[pivot]))
            pivot=i;
    }
    swap(v[0],v[pivot]);
    piv=v[0];
    pivot=0;
    sort(v.begin()+1,v.end(),polarSort);
    if(n<3)
    {
        hull=v;
        return;
    }
    hull.push_back(v[0]);
    hull.push_back(v[1]);
    for(int i=2; i<n; i++)
    {
        while(hull.size()>=2 && pt.orient(hull[hull.size()-2],hull.back(),v[i])<=0)
            hull.pop_back();
        hull.push_back(v[i]);
    }
}
/////////////////////convexhulllognend////////////////////
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int main()
{
 //   READ("input.txt");
//    WRITE("output.txt");
    int te,n,x;
    scanf("%d",&te);
    printf("%d\n",te);
    for(int i=0;i<te;i++)
    {
        scanf("%d",&n);
        vector<point>v;

        point p;
        for(int j=0;j<n;j++)
        {
            p.scan();
            v.push_back(p);
        }
        convexHull_logn(v);
        if(i<te-1)
        scanf("%d",&x);
        printf("%d\n",hull.size()+1);
        double mi=99999999999.0;
        int po;
        for(int j=0;j<hull.size();j++)
        {
            if(hull[j].y<mi)
            {
                po=j;
                mi=hull[j].y;
            }
        }
        for(int j=po;j<hull.size();j++)
        {
            hull[j].print();
        }
         for(int j=0;j<=po;j++)
        {
            hull[j].print();
        }
        //hull[0].print();
        if(i<te-1)
            printf("-1\n");
    }
    return 0;
}
