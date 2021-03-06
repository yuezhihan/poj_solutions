#include <cstdio>
#include <set>
using namespace std;

#define K1 9973
#define K2 15329

char str[1008][1008];
unsigned long long T[108];
unsigned long long strhash1[1008][1008],strhash[1008][1008];

multiset<unsigned long long> myset;

char tempstr[1008][1008];
int main()
{
    int casei=0;
    while(true)
    {
        ++casei;
        int N,M,cntT,P,Q;
        scanf("%d%d%d%d%d",&N,&M,&cntT,&P,&Q);
        if(N==0 && M==0)
            break;
        unsigned long long t1=1,t2=1;
        for(int i=1;i<=Q;++i)
            t1*=K1;
        for(int i=1;i<=P;++i)
            t2*=K2;
        
        for(int i=1;i<=N;++i)
//          for(int j=1;j<=M;++j)
                scanf("%s",&str[i][1]);
        //      cin >> str[i][j];
        for(int k=1;k<=cntT;++k)
        {
            for(int i=1;i<=P;++i)
//              for(int j=1;j<=Q;++j)
                    scanf("%s",&tempstr[i][1]);
//                  cin >> tempstr[i][j];
            T[k]=0;
            for(int i=P;i>=1;--i)
            {
                unsigned long long hash=0;
                for(int j=Q;j>=1;--j)
                    hash=hash*K1+tempstr[i][j];
                T[k]=T[k]*K2+hash;
            }
        }
        
        for(int i=N;i>=1;--i)
        {
            strhash1[i][M+1]=0;
            for(int j=M;j>=M-Q+1;--j)
                strhash1[i][j]=strhash1[i][j+1]*K1+str[i][j];
            for(int j=M-Q;j>=1;--j)
                strhash1[i][j]=strhash1[i][j+1]*K1-str[i][j+Q]*t1+str[i][j];
        }
        
        for(int j=M-Q+1;j>=1;--j)
        {
            strhash[N+1][j]=0;
            for(int i=N;i>=N-P+1;--i)
                strhash[i][j]=strhash[i+1][j]*K2+strhash1[i][j];
            for(int i=N-P;i>=1;--i)
                strhash[i][j]=strhash[i+1][j]*K2-strhash1[i+P][j]*t2+strhash1[i][j];
        }
        myset.clear();
        for(int i=1;i<=cntT;++i)
        {
            myset.insert(T[i]);
//          cout << T[i] << ' ';
        }
//      cout << endl;
        for(int i=1;i<=N-P+1;++i)
            for(int j=1;j<=M-Q+1;++j)
            {
                myset.erase(strhash[i][j]);
//              cout << i << ' ' << j << ' ' << strhash[i][j] << endl;
            }
        printf("Case %d: %d\n",casei,cntT-myset.size());
//      cout << "Case " << casei << ": " << cntT-myset.size() << endl;
    }
    return 0;
}
