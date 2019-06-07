#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define p_b push_back
#define debug cout<<"Reached Here"<<endl;
#define pdd pair<double, double>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()
#define pq_min priority_queue< int, vector<int>, greater<int> >
#define dbg(args...)    do { cerr << #args << ' ' ; print(args); } while(0); cerr << endl;
#define rep(i,n)  for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

typedef long long ll;
typedef unsigned long long ull;

int dx[]= {0,0,1,-1,-1,1,-1,1};
int dy[]= {-1,1,0,0,1,1,-1,-1};
int dz[]= {0,0,1,-1,-1,1,-1,1};
int kx[]= {2,2,-2,-2,1,-1,1,-1};
int ky[]= {1,-1,1,-1,2,2,-2,-2};

/// Template Starts here

template <typename T>
void print(const T& x)
{
    cerr<<x<<' ';
}

template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest)
{
    print(first);
    print(rest ...) ;
}
/// Template Ends here

/// Functions Starts here

bool isPal(string s)
{
    int half = s.size()/2;
    for(int i=0,j=s.size()-1;i<half;i++,j--)
        if(s[i]!=s[j])  return false;
    return true;
}

double _distance(double x1,double y1,double x2,double y2)
{
    double x1x2 = x1 - x2;
    double y1y2 = y1 - y2;
    return sqrt((x1x2*x1x2)+(y1y2*y1y2));
}

bool inBound(int x,int y,int r,int c)
{
    return (x>=0&&x<r&&y>=0&&y<c);
}

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b > 0)
    {
        if (b&1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

/*
int lp[32001];
vector<int>prime;
void sieve(int limit = 32001)
{
    for(int i=2;i<limit;i++)
    {
        if(!lp[i])
        {
            lp[i] = i;
            prime.push_back(i);
        }
        for(int j=0;j<prime.size()&&prime[j]<=i&&i*prime[j]<limit;j++)
            lp[i*prime[j]]=i;
    }
}
*/

/// Functions Ends here

string grid[15];
int alpha[26][2];
bool visit[15][15];
int level[15][15];

int bfs(int sx,int sy,int tx,int ty,int n)
{
    queue<pii>q;
    mem(visit,false);
    q.push({sx,sy});
    level[sx][sy] = 0;
    visit[sx][sy] = true;
    grid[sx][sy] = '.';
    while(q.size())
    {
        int ux = q.front().first;
        int uy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vx = ux + dx[i];
            int vy = uy + dy[i];
            if(inBound(vx,vy,n,n)&&(grid[vx][vy]=='.'||vx==tx&&vy==ty)&&visit[vx][vy]==false)
            {
                visit[vx][vy] = true;
                level[vx][vy] = level[ux][uy] + 1;
                grid[vx][vy] = '.';
                q.push({vx,vy});
            }
        }
        if(visit[tx][ty])   return level[tx][ty];
    }
    return -1;
}

int main()
{
    /// Suck my dick! HACKER -_-
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int t;
    cin>>t;

    for(int kase=1;kase<=t;kase++)
    {
        int n,k=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>grid[i];

            for(int j=0;j<n;j++)
            {
                if(isalpha(grid[i][j]))
                {
                    int id = grid[i][j] - 'A';
                    alpha[id][0] = i;
                    alpha[id][1] = j;
                    k++;
                }
            }

        }

        int ans = 0;

        for(int i=0;i+1<k;i++)
        {
            int sx = alpha[i][0];
            int sy = alpha[i][1];
            int tx = alpha[i+1][0];
            int ty = alpha[i+1][1];
            int dist = bfs(sx,sy,tx,ty,n);
            if(dist==-1)
            {
                ans = -1;
                break;
            }
            else    ans+=dist;
        }
        if(ans==-1)
            cout<<"Case "<<kase<<": Impossible"<<endl;
        else
            cout<<"Case "<<kase<<": "<<ans<<endl;
    }


    return 0;
}
