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
    void print() {cout<<setprecision(3)<<fixed<<x<<" "<<y<<"\n";}
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

struct line
{

    point a,b;
    line(){
        a=point(0,0);
        b=point(0,0);
    }
    line(point p,point q) {
        a=p;
        b=q;
    }
    void scan(){
        a.scan();
        b.scan();
    }
    void printf(){
        a.print();
        b.print();
    }
    bool isParallel(line v){return compare((b-a).cross(v.b-v.a))==0;}
    bool isColinear(line v) {return compare((b-a).cross(v.b-a))==0 && compare((b-a).cross(v.a-a))==0;}
    line perpendicLine(point p) {return line(p,p+(b-a).rotateLeft());}
    point intersectionPoint(line v){
        D a1=(v.b-v.a).cross(a-v.a);
        D a2=(v.b-v.a).cross(b-v.b);
        if(compare(a1)==compare(0) && compare(a2)==compare(0))//if a1=0 & a2=0 then they are same line
            return point(3000,3000); //it depends of problem constant
        if(compare(a1)==compare(a2)) //if a1==a2 same then they are not intersect
            return point(2000,2000); //it depends of problem constant
        return point((a.x*a2 - b.x*a1)/(a2-a1), (a.y*a2 - b.y*a1)/(a2-a1));
    }
    int isPointOnSeg(point p) {return (compare((p-a).cross(b-a))==0 && compare((p-a).dot(p-b))<=0);}

    int doSegIntersectSeg(line v)
    {

        int d1=compare((b-a).cross(v.a-a));
        int d2=compare((b-a).cross(v.b-a));
        int d3=compare((v.b-v.a).cross(a-v.a));
        int d4=compare((v.b-v.a).cross(b-v.a));
        if((d1^d2)==-2 && (d3^d4)==-2)
            return 2;//intersects;
        if(!d1&&compare((v.a - a).dot(v.a - b))<=0) return 1; //intersect strictly inside
        if(!d2&&compare((v.b - a).dot(v.b - b))<=0) return 1;
        if(!d3&&compare((a - v.a).dot(a - v.b))<=0) return 1;
        if(!d4&&compare((b - v.a).dot(b - v.b))<=0) return 1;

        return 0;//no intersection
    }

};
struct circle
{
    point p;
    D r;
    circle()
    {
        p=point(0,0);
        r=0;
    }
    circle(point a, D x)
    {
        p=a;
        r=x;
    }
    circle(point a,point b,point c)
    {
        line x=line(a,b).perpendicLine((a+b)/2.0);
        line y=line(b,c).perpendicLine((b+c)/2.0);
        p=x.intersectionPoint(y);
        r=p.distance(a);
    }
    void scan()
    {
        p.scan();
        cin>>r;
    }
    void print()
    {
        p.print();
        cout<<r<<"\n";
    }
    D circumference()
    {
        return 2.0*PI*r;

    }
};
struct polygon
{
    int n;
    point p[N];
    line l[N];
    void scan(int x)
    {
        n=x;
        for(int i=0; i<n; i++)
        {
            p[i].scan();
        }
    }
    void getline()
    {
        for(int i=0; i<n; i++)
        {
            l[i]=line(p[i],p[(i+1)%n]);
        }
    }
    int pointInPolygon(point q)
    {
        for(int i=0; i<n; i++)
        {
            if(p[i]==q)
                return 3;//q is a vertex
        }
        //getline
        for(int i=0; i<n; i++)
        {
            if(l[i].isPointOnSeg(q))
            {
                return 2;//q is on the side
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            int j=(i+1)%n;
            int k=compare((q-p[j]).cross(p[i]-p[j]));
            int u=compare(p[i].y-q.y);
            int v=compare(p[j].y-q.y);
            if(k>0 && u<0 && v>=0) cnt+=1;
            if(k<0 && v<0 && u>=0) cnt-=1;
        }

        return cnt!=0;//1 if inside, 0 if outside
    }

    int doesLineIntersectPolygon(line u)
    {
        getline();
        int k=0;
        for(int i=0; i<n; i++)
        {
            if(l[i].doSegIntersectSeg(u)==2) return 1;//some intersection
            if(l[i].doSegIntersectSeg(u)==1) k=1;
        }
        if(pointInPolygon(u.a)||pointInPolygon(u.b)) return 1;
        if(!k) return 0;//no intersection

        vector<point>vec;
        for(int i=0; i<n; i++)
        {
            if(l[i].doSegIntersectSeg(u))
            {
                if(l[i].isParallel(u))
                {
                    vec.push_back(u.a);
                    vec.push_back(u.b);
                    vec.push_back(l[i].a);
                    vec.push_back(l[i].b);
                    continue;
                }
                vec.push_back(l[i].intersectionPoint(u));
            }
        }
        sort(vec.begin(),vec.end());
        int sz=vec.size();
        for(int i=0; i<sz-1; i++)
        {
            point mid=(vec[i]+vec[i+1])/2;
            if(pointInPolygon(mid)==1) return 1;
        }
        return 2;//intersection on the side

    }
    double areaPolygon(vector<point>p)
    {
        double area=0.0;
        for(int i=0,n=p.size(); i<n; i++)
        {
            area+=p[i].cross(p[(i+1)%n]);
        }
        return abs(area)/2.0;
    }
}poly;
vector<point> hull;
void convexHull_nq(point points[], int n)
{
    hull.clear();
    if (n < 3)
        return;


    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q;
    while(1)
    {
        hull.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
            if (pt.orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;
        if(p==l)
            break;

    }

}
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
int main()
{

    return 0;
}
