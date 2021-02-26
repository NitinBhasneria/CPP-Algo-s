#include<bits/stdc++.h>
using namespace std;

bool possible(int n, int num){
	// cout<<"chla";
	// cout<<"possibibltyu "<<num<<endl;
	if(num==0)
		return false;
	int sharma=0, singh=0, balls=n;
	while(n>0){
		if(n-num<0){
			sharma+=n;
			break;
		}
		sharma+=num;
		n-=num;
		// cout<<sharma<<" "<<n;
		singh+=(n/10);
		n-=(n/10);
		// cout<<" "<<singh<<" "<<n<<endl;
	}
	// cout<<sharma<<" "<<singh<<endl;
	if((sharma*2)>=(balls))
		return true;
	return false;
}

int sol(int start, int end, int ans, int n){
    if(start>end){
		// cout<<"exited"<<" "<<start<<" "<<end<<" "<<ans<<endl;
		return ans;
	}
	// cout<<start<<" "<<end<<" "<<ans<<endl;
    int mid = (start+end)/2;
    if(possible(n,mid)){
        return sol(start,mid-1,mid, n);
    }
    else
        return sol(mid+1,end,ans, n);
        
}

int find_solution(int n){
    int start=0,end=n,ans=n;
    return sol(start,end,ans, n);
}

int main()
{
    int n;
	cin>>n;
	// if(possible(43,1))
	// 	cout<<"true";
    cout<<find_solution(n)<<endl; 
	return 0;
}
