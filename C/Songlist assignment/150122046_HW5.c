#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Alp Biricik 150122046

typedef struct Songs {

char songName[25];
char duration[10];
struct Songs *next;
}Songs;

typedef Songs *songPtr;

void menu();
void insertSong(songPtr *sPtr,char *songName,char *duration);
int compareDurations(char *duration1,char *duration2);
void printList(songPtr currentPtr);
int deleteSong(songPtr *head,char songName[25]);
void printListFile(songPtr currentPtr, FILE *output);

int main(void){
   FILE *songs = fopen("songs.txt","r");

   char firstList[200];   

   songPtr head = NULL;   

   while (fgets(firstList,200,songs) != NULL){
    char *songName = strtok(firstList,"\t");
    char *duration =strtok(NULL,"\n");
    insertSong(&head,songName,duration);
   }
    menu();
    int choice ;
    scanf("%d",&choice);   
   
    while (choice != 5){   
      fflush(stdin);
     switch (choice)
     {
       case 1: 
           printf("Enter the name of the song and its duration(ex. lose yourself 05:22): \n");
           char input[100];
           fgets(input, sizeof(input), stdin); 
           for (int i = 0; i < strlen(input); i++){
            if (input[i] == ':'){
              input[i-3] = '\t';
              char *songName1 = strtok(input,"\t");
              char *duration1 = strtok(NULL,"\n");
              insertSong(&head,songName1,duration1);
              break;
            }
           
           }
       break;
       case 2:
       printf("Enter name of the song you want to delete.\n");
       char songName[25];
       fgets(songName,sizeof(songName),stdin);
       if (head != NULL){
        if(deleteSong(&head,songName) == 1){
          printf("The song \"%s\" is deleted from the list!\n",songName);
        }
       }
       
       break;
       case 3: 
       printList(head);
       break;   

       case 4: 
        printf("Enter a file name:\n");
        char fileName[100];
        fgets(fileName,sizeof(fileName),stdin);
        fflush(stdin);
        fileName[strcspn(fileName, "\n")] = '\0';
        FILE *output = fopen(fileName,"w");

        if (output == NULL) {
        printf("File couldn't open.\n");
        }

        else{
        printListFile(head,output);
        }

       break;
 
       default:
      printf("Invalid option!!");
       break;
     }
     menu();
     scanf("%d",&choice);
    }
 
}
//This method prints the menu for the user.
void menu(){
  printf("Enter your choice:\n  1 to insert a song into the list.\n  2 to delete a song from the list.\n"
 "  3 to print the songs in the list.\n  4 to print the songs to an output file.\n  5 to end. \n? ");
} 
// This method inserts songs to the list
void insertSong(songPtr *sPtr,char *songName,char *duration){
 songPtr newPtr = malloc(sizeof(Songs));

 if (newPtr != NULL){
  strcpy(newPtr->songName,songName);
  strcpy(newPtr->duration,duration); 
  newPtr->next =NULL;
  
  songPtr previousPtr = NULL;
  songPtr currentPtr = *sPtr;

while (currentPtr != NULL && strcmp(duration,currentPtr->duration) > 0){
  previousPtr = currentPtr;
  currentPtr = currentPtr->next;
}
if (previousPtr == NULL){
  newPtr->next =*sPtr;
  *sPtr = newPtr;
}
else{
  previousPtr->next = newPtr;
  newPtr->next = currentPtr;
}
 }
 else{
  printf("\"%s\" not inserted. No memory avaible.\n",songName);
 }
 
 
}
//This method prints the list
void printList(songPtr currentPtr){
  char tempDuration[10];
  if(currentPtr == NULL){
    printf("List is empty\n");
  }
  else{
    printf("The list is:\n");
int k = 1;
    while (currentPtr != NULL) {
    strcpy(tempDuration,currentPtr->duration);
      int minute = atoi(strtok(tempDuration, ":"));
      int second = atoi(strtok(NULL, ":"));

      printf("%d. %s \t %d:%02d\n",k, currentPtr->songName, minute, second);
      currentPtr = currentPtr->next;
      k++;
    }
  }
    
  }
//This method deletes a song from list.
int deleteSong(songPtr *head,char songName[25]){

     char currentSongName[25]; 
     songName = strtok(songName,"\n");
     strcpy(currentSongName,(*head)->songName);
     strcpy(currentSongName,strtok(currentSongName,"\0"));

     if(strcmp(currentSongName,songName) == 0){
          songPtr temp = *head;
          *head = (*head)->next;
          free(temp);
          return 1;
     }
     else{
      songPtr previousPtr = *head;
      songPtr currenPtr = (*head)->next;

      strcpy(currentSongName,currenPtr->songName);
      strcpy(currentSongName,strtok(currentSongName,"\0"));

      while (currenPtr != NULL && strcmp(currentSongName,songName) != 0){
          previousPtr = currenPtr;
          currenPtr = currenPtr->next;
          strcpy(currentSongName,currenPtr->songName);
          strcpy(currentSongName,strtok(currentSongName,"\0"));
      }
      if(currenPtr != NULL){
        songPtr temp = currenPtr;
        previousPtr->next = currenPtr->next;
        free(temp);
        return 1;
      }
      return 0 ;
     }
  }
  //This method prints the list in to the output file.
void printListFile(songPtr currentPtr, FILE *output){
  char tempDuration[10];
  if(currentPtr == NULL){
    fprintf(output,"List is empty\n");
  }
  else{
    fprintf(output,"The list is:\n");
    
    int k = 1;
    while (currentPtr != NULL) {
    strcpy(tempDuration,currentPtr->duration) ;
      int minute = atoi(strtok(tempDuration, ":"));
      int second = atoi(strtok(NULL, ":"));

      fprintf(output,"%d. %s \t %d:%02d\n",k, currentPtr->songName, minute, second);
      currentPtr = currentPtr->next;
      k++;
    }
  }
    
  }

