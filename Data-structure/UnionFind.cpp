class UnionFind
{
private:
    int n;
    int group;
    int sz[500010];
    int parent[500010];
public:
    void Initial(int n)
    {
        this->n=n;
        this->group=n;
        for(int i = 0; i < n; i++)
            parent[i] = i, sz[i] = 1;
    }
    int connectedGraph()
    {
        return this->group;
    }
    int find(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    bool IsConnected(int x,int y)
    {
        if(x==y||find(x)==find(y))
            return true;
        return false;
    }
    int size(int p)
    {
        return sz[ find(p) ];
    }
    void union_sets(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            group--;
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
} uf;
