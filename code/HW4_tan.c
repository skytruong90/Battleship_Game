/************************************
Program Name: HW4_tan.c 
Programmer: David Tan
Class: CS 3335 
HW: 4
****************************************/

//this is the library use in C
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

//This is where I declare my function
void setBoard(int*);
void setComputerBoard(int*);
int playGame(int*, int*);
int main(){
    int y[2], z[2], t;
   
    setBoard(y);
    srand(time(0));
    setComputerBoard(z);
    
    t = playGame(y, z);
    if(t==1){
        printf("\nHuman wins!");
    }
    else{
        printf("\nComputer wins!");
    }
  
    return 0;
}
//This function to set the human board
void setBoard(int *x){
    
    for(int i=0; i<2; i++){
      printf("Enter %dst position: ", i+1);
      scanf("%d", &*(x+i) );
      
    }
}
//This function set the computer board
void setComputerBoard(int*x){
    
    int slot1, slot2;
    slot1 = rand()%10;
    if(slot1==9){
        slot1==8;
        slot2==9;
    }
    else {
        slot2 = slot1+1;
    }
    
    
  *x = slot1;
  *(x+1) = slot2;
    
}
//This is the function to set the game
int playGame(int *x, int *y){
    // n is the input number from user, b is random number
    int n, b; 
    int r =0; 
    int a=0; 

//This is the arrays of lements on human board
    char array[10]; 
    char array1[10]; 
    for(int e=0; e<10; e++){
         array[e] = '*';
         array1[e]= '*';
         
    }
    //This invoke S to printed off in the slots where the human ship is located
    array[*x]='S';
    array[*(x+1)]= 'S';
    array1[*y]='S';
    array1[*(y+1)]= 'S';
    
    while ( r<2 && a<2) {
     //This invoke the computer to guess
      b=rand()%10-1;
      printf("\nComputer guess %d\n", b);
     //This set the condition when computer hit human ship
      if(b==*(x) || b==*(x+1)){
            
            printf("HIT!\n");
            array[b]='H';
            r++;
       }
      else{
            printf("MISS!\n");
            array[b]='M';
      }
     //This invoke a print statement for the human and computer board when computer guesses.
     
     printf("\nHuman Board:\n0 1 2 3 4 5 6 7 8 9\n");
     
     for(int k=0; k<10; k++){
        printf("%c ", array[k]);
     }
     
     printf("\nComputer Board:\n0 1 2 3 4 5 6 7 8 9\n");
    
     for(int l = 0; l<10; l++){
         printf("%c ", array1[l]);
     }
     //This invoke the second for the human guesses 
     printf("\nEnter guess: ");
     scanf("%d", &n);
     printf("\nyou guessed %d\n", n);
     
    
        if(n==*y|| n==*(y+1)){
            
            printf("HIT ");
            
            array1[n]='H';
            a++;
        }
        else{
            printf("MISS ");
            array1[n]='M';
          
        }
     
     // Again this is my print statement for the human and computer board when human guesses
     printf("\nHuman Board:\n0 1 2 3 4 5 6 7 8 9\n");
     for(int k=0; k<10; k++){
        printf("%c ", array[k]);
     }
     printf("\nComputer Board:\n0 1 2 3 4 5 6 7 8 9\n");
     for(int l = 0; l<10; l++){
         printf("%c ", array1[l]);
     }
      
     
    }
    //This function return 1 if the human wins, 
    // and 0 if the computer wins 
    if(a>r){
        return 1;
    }
    else if(a<r) {
        return 0;
    }
        
}