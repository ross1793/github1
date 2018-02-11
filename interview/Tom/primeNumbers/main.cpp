/* Goal : Print out the number of ones of a number in binary presentation.
 * Given a number n, please print out all the result that is less and equal
 * to n
 * Our goal is to finish this in O(n)
 */


#include<iostream>
#include<vector>
using namespace std;

vector<int> Twos(500,0);
int numberOfTwos(int n){
   if(Twos[n] != 0)
      return Twos[n];
   else if(n == 0)
      return 0;

   Twos[n] = numberOfTwos(n/2) + n % 2;
   return Twos[n];
}

int solution(int n){
   for(int i=1;i<=n;++i){
      cout << i << " : " << numberOfTwos(i) << endl;
   }
}

int main(){

   solution(20);
   




   return 0;
}
