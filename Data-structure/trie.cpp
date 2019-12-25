#include <stdio.h>
#include<string.h>
struct node
{
    bool endmark;
    node* next[26+1];
    node()
    {
        for(int i=0; i<26; i++)
        {
            next[i]=NULL;
        }
    }
}*root;
void insert(char* str,int len)
{
    node* curr = root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id]=new node();
        curr=curr->next[id];
    }
    curr->endmark=1;
}
bool search(char* str,int len)
{
    node*curr=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            return false;
        curr=curr->next[id];
    }
    return curr->endmark;
}

bool isEmpty(node* root)
{
    for (int i = 0; i < 26; i++)
        if (root->next[i])
            return false;
    return true;
}
node* remove(node* curr, char* str, int len,int depth)
{
    if (curr==NULL)
    {
        return NULL;
    }
    if (depth == len)
    {
        if (curr->endmark)
            curr->endmark = false;

        if (isEmpty(curr))
        {
            delete (curr);
            curr = NULL;
        }
        return curr;
    }

    int index = str[depth] - 'a';
    curr->next[index] =remove(curr->next[index], str,len, depth + 1);

    if (isEmpty(curr) && curr->endmark == false)
    {
        delete (curr);
        curr = NULL;
    }
    return curr;
}

void del(node* cur)
{
    for(int i=0; i<26; i++)
    {
        if(cur->next[i])
            del(cur->next[i]);

    }
    delete(cur);
}
int main()
{
    puts("ENTER NUMBER OF WORDS");
    root = new node();
    int num_word;
    scanf("%d",&num_word);
    printf("Enter %d names\n",num_word);
    for (int i = 1; i <= num_word; i++)
    {
        char str[50];
        scanf("%s", str);
        insert(str, strlen(str));
    }
    puts("ENTER NUMBER OF QUERY");
    int query;
    scanf("%d",&query);
    for (int i = 1; i <= query; i++)
    {
        char str[50];
        printf("Enter query type Delete or search\n");
        scanf("%s", str);
        printf("Enter query string\n");
        if(str[0]=='D'||str[0]=='d')
        {
            scanf("%s", str);
            remove(root,str,strlen(str),0);
        }
        else
        {
            scanf("%s", str);
            if (search(str, strlen(str)))
                puts("FOUND");
            else
                puts("NOT FOUND");
        }

    }
    del(root);
    return 0;
}

