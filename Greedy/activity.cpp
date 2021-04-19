/*
Activity Selection
Send Feedback
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;

class activity {
    public:
    	int start = 0;
    	int finish = 0;
};
bool operator <(activity a, activity b){
    return a.finish < b.finish;
}
/*bool ValueCmp(ClassOne const & a, ClassOne const & b)
{
    return a.value < b.value;
}

std::sort(cone, cone + 10, ValueCmp);*/
int main()
{
    //Write your code here
    int n;
    cin>>n;
    activity val[n];

    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        val[i].start = a;
        val[i].finish = b;
    }
    sort(val, val+n);
    int count = 1, j=0;
    for(int i=1;i<n;i++){
        cout<<val[j].finish<<" "<<val[i].start<<" sad"<<endl;
        if(val[j].finish <= val[i].start){
            j=i;
            count++;
        }
    }
    cout<<count;
    return 0;
}