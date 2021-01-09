#include<bits/stdc++.h>
using namespace std;

void PrimeFacOf(int n, int d[]){
    cout<<endl<<"factors of "<<n<<" are ";
    while(n!=1)
    {
        cout<<d[n]<<" ";
        n/=d[n];
    }
}
// d[i] gives the first prime factor or smallest prime factor of i.
int main()
{
    const int N=1e2+5;
    static int d[N]; //static is for holding more variables

    vector<int> primes;
    
    for(int i=1;i<N;i++)
        d[i]=i;
    
    for(int i=2;i<N;i++)
    {
        if(d[i]==i)
        {   
            primes.push_back(i);
        }
        for(int j=0;j<primes.size()&&primes[j]<=d[i]&&i*primes[j]<N;j++)
        {
            d[i*primes[j]]=primes[j];
        }
    }
    for(int i=2;i<N;i++)
        if(d[i]==i)
            cout<<i<<" ";
    int x;
    cin>>x;
    PrimeFacOf(x, d);
}