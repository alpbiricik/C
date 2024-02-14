#include <stdio.h>
#include <math.h>
double calculateWeightBack_recursion(int row , int col);
double calculateWeightBack_iteration(int row , int col);

/*Alp Biricik 150122046
    This program calculates the weight every person carries in the pyramid*/

int main(void){
    printf("Enter row number please: ");
    int row;
     scanf("%d", &row);
    printf("Enter column number please: ");
    int col;
    scanf("%d", &col);
     /*printf("%.2f", calculateWeightBack_recursion(row,col));*/
     printf("%.2f", calculateWeightBack_iteration(row,col));
}

double calculateWeightBack_recursion(int row , int col){
    if (row >= 0 && col >=0)
    {
if(col == row){
    if(col== 0 && row==0){
      return 0;
}
    else{
      return ((80+calculateWeightBack_recursion(row-1,col-1))/2) ;
}
}
else if (col == 0)
{
  return ((80+calculateWeightBack_recursion(row-1,0))/2) ;
}
else{
   return ((calculateWeightBack_recursion(row-1,col)+calculateWeightBack_recursion(row-1,col-1)+80+80)/2);
}
    }
    else{
   return 0;
    }
}

double calculateWeightBack_iteration(int row , int col){
  if ((row >= 0) && (col >= 0)){
      double a[row+1][row+1];
      double result;
      for (int i = 0; i <= row ; i++) {
        for (int k = 0; k <= i; k++) {
          if(i==0){
           a[i][k] = 0;
          }
           else if ((k==0))
           {
            a[i][k] = (a[i-1][k] + 80)/2;
           }
           else if ((k == i))
           {
            a[i][k] = (a[i-1][k-1] + 80)/2;
           }
           else{
            a[i][k] = (a[i-1][k-1]+ a[i-1][k]+160)/2;
           } 
        }
      }
    result = a[row][col];
    return result;
  }
  else{
    return 0;
 }
}

