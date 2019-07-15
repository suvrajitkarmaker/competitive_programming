class BinaryIndexTree
{
private:
    int n;
    int tree[100010];

public:
    void initial(int n)
    {
        this->n=n;
        for(int i=0; i<=n; i++)
            tree[i]=0;
    }

    int query(int idx)
    {
        int sum=0;
        while(idx>0)
        {
            sum+=tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    void update(int idx, int value)
    {
        while(idx<=n)
        {
            tree[idx]+=value;
            idx += idx & (-idx);
        }
    }
} bit;
