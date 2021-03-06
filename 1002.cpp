#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[100002];
char temp[200];
int ysb[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i)
    {
        char temp2[30]={0};
        scanf("%s",&temp);
        int len=0;
        for(int j=0;temp[j]!=0;++j)
        {
            if(temp[j]=='-')
                continue;
            else if(temp[j]>='0' && temp[j]<='9')
                temp2[len++]=temp[j];
            else temp2[len++]=ysb[temp[j]-'A']+'0';
        }
        sscanf(temp2,"%d",&a[i]);
    }
    sort(a,a+N);
    bool isnull=true;
    long long start=a[0],k=0;
    for(int i=0;i<N;++i)
    {
        if(a[i]!=start)
        {
            if(k!=1)
            {
                printf("%03d-%04d %d\n",(int)(start/10000),(int)(start%10000),(int)k);
                isnull=false;
            }
            start=a[i];
            k=1;
        }
        else ++k;
    }
    if(k!=1)
    {
        printf("%03d-%04d %d\n",(int)(start/10000),(int)(start%10000),(int)k);
        isnull=false;
    }
    if(isnull)
        printf("No duplicates.\n");
    return 0;
}
