#include<bits/stdc++.h>
using namespace std;
const int MAX = 3;
 
int main () {
   int  var[MAX] = {10, 100, 200};
   int *ptr[10];
 
   for (int i = 0; i < MAX; i++) {
      ptr[i] = &var[i]; // assign the address of integer.
   }
   
   for (int i = 0; i < 10; i++) {
      *ptr[i] = 10;
   }
   
   return 0;
}