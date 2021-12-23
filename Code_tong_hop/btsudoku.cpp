#include <iostream>
#include <algorithm>
#include <time.h>
#include <fstream>

#define fo(x,a,b) for(int x=a;x<=b;x++)
#define fo1(x,a,b) for(int x=a;x>=b;x--)
#define fi first
#define se second
#define ll long long
#define name "btsudoku"

using namespace std;

const int mn=1e5+7;
const int oo= 1e9+7;
typedef pair <int,int> ii;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

int n;
int a[10][10];
int f[10][10];
bool hang[10][10],cot[10][10],o[10][10];

void capnhat()
{
    fo(i,1,9)
    {
        fo(j,1,9)cout<<f[i][j];
    }
    exit(0);
}

void Try(int x,int y)
{
    if(a[x][y]==0)
    {
        fo(i,1,9)
        {
            int hh=x/3+(x%3!=0);
            int cc=y/3+(y%3!=0);
            int t=3*(hh-1)+cc;
            if(hang[x][i]||cot[y][i]||o[t][i])
                continue;
            f[x][y]=i;
            hang[x][i]=1;
            cot[y][i]=1;
            o[t][i]=1;
            if(x==9&&y==9)
                capnhat();
            if(y==9)
                Try(x+1,1);
            else
                Try(x,y+1);
            hang[x][i]=0;
            cot[y][i]=0;
            o[t][i]=0;
        }
    }
    else
    {
        f[x][y]=a[x][y];
        if(x==9&&y==9)
            capnhat();
        if(y==9)
            Try(x+1,1);
        else
            Try(x,y+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    char c;
    n=1;
    int tmp=0;
    while(n<=9)
    {
        cin>>c;
        if(isdigit(c))
        {
            a[n][++tmp]=c-48;
            int x1=tmp/3+(tmp%3!=0);
            int x2=n/3+(n%3!=0);
            hang[n][a[n][tmp]]=1;
            cot[tmp][a[n][tmp]]=1;
            o[3*(x2-1)+x1][a[n][tmp]]=1;
        }
        else
            a[n][++tmp]=0;
        if(tmp==9)
        {
            tmp=0;
            n++;
        }
    }
    Try(1,1);
    return 0;
}
