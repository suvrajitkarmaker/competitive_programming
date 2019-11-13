#include <bits/stdc++.h>
using namespace std;
struct node
{
    bool endmark;
    node* next[10 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 10; i++)
            next[i] = NULL;
    }
}*root;
void insert(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool search(string &str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    for (int i = 0; i < 10; i++)
    {
        if (curr->next[i] != NULL)
            return true;
    }
    return false;
}
void del(node* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete(cur);
}
vector<string>v;
int main()
{

    int te,n,f;
    scanf("%d",&te);
    char s[100];
    for(int i=0; i<te; i++)
    {
        scanf("%d",&n);
        v.clear();
        root = new node();
        for(int j=0; j<n; j++)
        {
            scanf("%s",s);
            v.push_back(s);
            insert(s,strlen(s));
        }
        f=0;
        for(int j=0; j<n; j++)
        {
            if(search(v[j],v[j].size()))
            {
                f=1;
                break;
            }
        }
        if(f==0)
            printf("YES\n");
        else
            printf("NO\n");
        del(root);
    }
}
