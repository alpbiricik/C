#include <stdio.h>
#include <math.h>
void reverseN(int *number, int N);
/*Alp Biricik 150122046
    This program reverse a number from 
    its Nth index you will enter the N*/
int main(void){
  
    int number ;
    int N;

    printf("Please enter a number: ");
    scanf("%d", &number);
    printf("Please enter the N: ");  
    scanf("%d", &N);
    reverseN(&number,N);
    return 0;
}
void reverseN(int *number, int N) {
    if ((int) pow(10,N) > *number){
      if(*number >= (int) pow(10,N-1)){
     int temp = *number;
     int k[N];
     for (int i = 0 ; i < N ; i++) {
      k[i] = (temp)% 10;
       (temp) /= 10;
     }
     
     temp = 0 ;
     for(int i = 0 ,z = N-1 ; i< N ; i++,z--){
      temp += k[i] * (int) pow(10,z);
     }
     printf("%d", temp);
      }
      else{
        printf("N must be less than %d",((int) (log10((double)*number))+2));
      }
    }
    else{
         int temp = *number;
         int k[N];
       for (int i = 0 ; i < N ; i++) {
         k[i] = (temp) % 10;
         (temp) /= 10;
       }
      temp*= (int) pow(10,N);
       for (int i = 0 ,z = N-1 ; i < N ; i++,z--){
            temp += k[i] * (int) pow(10,z);
        }
        printf("%d",temp);
       
     }
    
}



