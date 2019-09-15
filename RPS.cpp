/*in this program we going to study rock scissor paper(tradition game)in finit size population
at first we assume the the population equal to 100 and the network is fully connected and then we consider
0----rock
1----paper
2----scissor
and we will see....
--------------------------------------------------------*/
#include "iostream"
#include "fstream"
#include "cstdlib"
#include "ctime"
#include "math.h"
using namespace std;
const int N=1000;
const double R0_num=100;
const double P0_num=200;
const double S0_num=700;
double net[N];
int t_max=1000;

//--------------------------------------------
int main() {
  ofstream output("./RPS.txt");
  unsigned seed=time(NULL);
  srand(seed);

  int i=0;
  int r_1,r_2,r;
  int t=0;

   for (int j=0 ; j<N ; j++) {
    net[j]=2;
   }
   while (i<P0_num) {
     r_1=rand()%N;
     if (net[r_1]==2) {
       net[r_1]=1;
       i++;
     }

   }

   i=0;
   while (i<R0_num) {
     r_2=rand()%N;
     if (net[r_2]==2) {
       net[r_2]=0;
       i++;
     }
   }

    output<<t<<"\t"<<double(R0_num)/N<<"\t\t"<<double(P0_num)/N<<"\t\t"<<double(S0_num)/N<<"\t\t"<<endl;
///////////////////////////////////////////////////////////////////////////////////////
double R_num;
double P_num;
double S_num;
/*R_num=R0_num;
 P_num=P0_num;
 S_num=S0_num;*/
t++;
  //while (t_start<t_max&&R_num>=0&&P_num>=0&&S_num>=0){

       R_num=R0_num;
       P_num=P0_num;
      S_num=S0_num;

         while (t<t_max&&R_num>=0&&P_num>=0&&S_num>=0) {
         for (size_t i = 0; i < 35; i++) {


          int r1=rand()%N;
          int r2=rand()%N;

         if (net[r1]==0 && net[r2]==1) {
           net[r1]=1;
           //net[r2]=1;
           R_num--;
           P_num++;
           }
        else if(net[r1]==0 && net[r2]==2){
           net[r2]=0;
          // net[r1]=0;
           R_num++;
           S_num--;
         }
       else if(net[r1]==2 && net[r2]==1){
           net[r2]=2;
           //net[r1]=2;
           S_num++;
           P_num--;
         }
         else if(net[r1]==2 && net[r2]==0){
           net[r1]=0;
          // net[r2]=0;
           S_num--;
           R_num++;
         }
       else if(net[r1]==1 && net[r2]==0){
           net[r2]=1;
          // net[r1]=1;
           P_num++;
           R_num--;
         }
         else if(net[r1]==1 && net[r2]==2){
           net[r1]=2;
          // net[r2]=2;
           P_num--;
           S_num++;
         }
}
output<<t<<"\t"<<double(R_num)/(N)<<"\t\t"<<double(P_num)/(N)<<"\t\t"<<double(S_num)/(N)<<"\t\t"<<endl;
    t++;

      }
return 0;
}
