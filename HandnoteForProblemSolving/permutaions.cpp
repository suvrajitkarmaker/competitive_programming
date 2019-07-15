#include <stdio.h>
#include <iostream>
using namespace std;

int used[40],number[40],n,r;
void permutation(int po)
{
    if(po==r+1)
    {
        for (int i = 1; i <= r; i++)
        {
            printf("%d ",number[i]);

        }
        printf("\n");
        return;
        
    }

    for (int i = 1; i<= n; i++)
    {
        if(used[i]==0)
        {
            used[i]=1;
            number[po]=i;
            permutation(po+1);
            used[i]=0;
        }
    }
    
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>r;//nPr
    permutation(1);


}
