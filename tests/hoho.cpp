#include <bits/stdc++.h> 
using namespace std; 
bool ispalin(string n) 
{
    for (unsigned long long int i = 0; i < n.size() / 2; i++){
	 if (n[i] != n[n.size() - 1 - i]){ 
	   return false; }
    }  
    return true; 
} 
long long int palin(unsigned long long int num) 
{
  while (!ispalin(to_string(num))){ 
	num--; }
 return num;
} 
int main()
{
    unsigned long long int n;
    cin>>n;
    cout<<palin(n)<<" "<<n-palin(n);

	return 0;
}