#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Alp Biricik 150122046
*/
 typedef struct{
  char str[51]; 
  int length;
 }String;

int charAt(String *s,int index);
String *concat(String *s1, String *s2);
unsigned int strSearch(String *s1, String *s2);
int containsAllCharacters(const char *str, const char *characters);
unsigned int findScore(String *s1);


int main(){
String s1;
String s2;
printf("Enter a string  ");
scanf("%s",(s1.str));
printf("Enter another string  ");
scanf("%s",(s2.str));
s1.length= strlen(s1.str);
s2.length= strlen(s2.str);

  //charAt("%s \n",charAt(&s1,2));
  printf("%s \n",concat(&s1,&s2)->str);
  printf("%d \n",strSearch(&s1,&s2));
  printf("%d \n",findScore(&s1));
  
}

int charAt(String *s,int index) {
  if(index >= s->length || index < 0){
      return -1;
  }
  else{
    return s->str[index];
  }
}

String *concat(String *s1, String *s2){
  String temp;
   for (int i = 0,k = 0; i < (s1->length+s2->length) ; i++) {
    if(k == 0){
    if( s1->str[i] == '\0'){
       s1->str[i] = s2->str[k];
       k++;
       }
    }
    else{
       s1->str[i] = s2->str[k];
       k++;
    }
  }
   
   return s1;
}

unsigned int strSearch(String *s1, String *s2){
  String temp;
  for (int i = 0; i < s1->length; i++)  {
      temp.str[i] = s1->str[i];
      temp.str[i+1] = '\0';
      if(containsAllCharacters(temp.str, s2->str) == 1){
         return strlen(temp.str);
      }
      
}
  return 0;
}
int containsAllCharacters(const char *str, const char *characters) {
 for (int i = 0; i < strlen(characters); i++) {
        if (strchr(str, characters[i]) == NULL) {
            return 0;
        }
    }
    return 1;
}

unsigned int findScore(String *s1){
  char temp[50];
  int score = 0;
   for (int i = 0; i < s1->length; i++){
      temp[i] = toupper(s1->str[i]);
      switch (temp[i])
      {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
      case 'L':
      case 'N':
      case 'R':
      case 'S':
      case 'T':
        score += 1;
       break;
      case 'D':
      case 'G':
        score += 2 ;
       break;
      case 'B':
      case 'C':
      case 'M':
      case 'P':
        score += 3;
       break;
      case 'F':
      case 'H':
      case 'v':
      case 'W':
      case 'Y':
        score += 4;
       break;
      case 'K':
        score += 5 ;
        break;
      case 'J':
      case 'X':
        score += 8;
       break;
      case 'Q':
      case 'Z':
        score += 10 ;
       break;
      }
      
   }
   return score;
}
