#include<bits/stdc++.h>
using namespace std;
#define N 200100
int n,q;
string s;
int a[N],b[N];
int l,r,mid1,mid2;
int idx,v[N],ll,rr,m,ans;
int main()
{
    cin>>n>>q>>s;
    s=' '+s;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')a[i]++;
        else if(s[i]=='2')b[i]++;
        else
        {
            idx++;
            v[idx]=i;
        }
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    while(q--)
    {
        cin>>ll>>rr;
        ans=0;
        l=lower_bound(v+1,v+idx+1,ll)-v;
        r=upper_bound(v+1,v+idx+1,rr)-v-1;
        if(l>r)
        {
            cout<<0<<endl;
            continue;
        }
        int p=1000;
        while(l<=r&&p--)
        {
            mid1=l+(r-l)/3;
            mid2=r-(r-l)/3;
            if(a[v[mid1]]-a[ll-1]<b[rr]-b[v[mid1]-1])
            {
                l=max(mid1-1,l+1);
            }
            else
            {
                r=min(mid2+1,r-1);
            }
            m=v[mid1];
            ans=max(ans,2*min(a[m]-a[ll-1],b[rr]-b[m-1])+1);
            m=v[mid2];
            ans=max(ans,2*min(a[m]-a[ll-1],b[rr]-b[m-1])+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
