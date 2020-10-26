#include<bits/stdc++.h>
#define ll long long int
#define vi vector<long long int>

using namespace std;

int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        ll n,k;
        cin>>n>>k;
        vi a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        vi diff(2*k+2,0);
        vi freq(2*k+2,0);
        for(int i=0;i<=(n/2)-1;i++)
        {
            freq[a[i]+a[n-i-1]]++;
            diff[min(a[i],a[n-1-i])+1]++;
            diff[max(a[i],a[n-i-1])+k+1]--;
        }
        //for(auto it:diff)
        //    cout<<it<<" ";
        for(int i=1;i<=2*k+1;i++)
        {
            diff[i]+=diff[i-1];
        }
        ll ans=1e9;
        for(int i=2;i<=2*k;i++)
        {
            ans=min(ans,diff[i]-freq[i]+2*(n/2-diff[i]));
        }
        cout<<ans<<endl;
    }
}
