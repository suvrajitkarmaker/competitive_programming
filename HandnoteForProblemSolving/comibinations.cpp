#include <stdio.h>
#include <iostream>
using namespace std;

int number[40],n,r;
void combination(int po,int last)
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

    for (int i = last+1; i<=n-r+po; i++)
    {
        number[po]=i;
        combination(po+1,i);    
    }
    
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>r;//nCr
    combination(1,0);


}
