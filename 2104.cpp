#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#define B 1000
#define num(x) (((x)-1)/B)
using namespace std;
int A[100008],sorted_A[100008];
int bucket[100008/B][B+8],bucket_len[100008/B];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("WA.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        sorted_A[i]=A[i];
    }
    sort(sorted_A+1,sorted_A+n+1);
    for(int i=1;i<=n;++i)
        bucket[num(i)][bucket_len[num(i)]++]=A[i];
    for(int i=0,size=num(n);i<=size;++i)
        sort(bucket[i],bucket[i]+bucket_len[i]);
    for(int i=1;i<=m;++i)
    {
        int L,R,k;
        scanf("%d%d%d",&L,&R,&k);
        int x_L=1,x_R=n+1;
        while(x_L<x_R)
        {
            int x_M=x_L+(x_R-x_L)/2;
            int ans=0,x=sorted_A[x_M],tL=L,tR=R;
            for(;tL<=tR && (tL-1)%B!=0;++tL)
                if(A[tL]<x)
                    ++ans;
            for(;tL<=tR && tR%B!=0;--tR)
                if(A[tR]<x)
                    ++ans;
            for(;tL<=tR;tL+=B)
            {
                int b=num(tL);
                ans+=lower_bound(bucket[b],bucket[b]+bucket_len[b],x)-bucket[b];
            }
            if(ans<k)
                x_L=x_M+1;
            else x_R=x_M;
        }
        printf("%d\n",sorted_A[x_L-1]);
    }
    return 0;
}
