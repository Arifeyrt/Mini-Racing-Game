#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printMap(char gamearea[15][30]);
int dice(); // it generates a random integer between [1, 6] 
int startGame();





int main()
{srand(time(NULL));   // Initialization, should only be called once.
char gamearea[15][30];
int i,j;
int z;
    for(i=0;i<15;i++){
        for(j=0;j<30;j++){
            if((j==0 || j==29) && i!=0 && i!=14) gamearea[i][j] = ':';
            else if (i==0 || i==14) gamearea[i][j] = '.';
            else if((j>=2 && j<=27) &&  (i==2 || i==12))gamearea[i][j]= '.';
            else if ((j>=4 && j<=25) && (i==4 || i==10)) gamearea[i][j]= '.';
            else if((j==2 || j==27) && 3<=i && i<=11 ) gamearea[i][j] = ':';
            else if ((j==4 || j==25) && 5<=i && i<=9) gamearea[i][j]=':';
            else gamearea[i][j]=' ';

        }
    }

gamearea[1][14]='X';//player 1 penalty points
gamearea[7][28]='X';//player 1 penalty points
gamearea[13][14]='X';//player 1 penalty points
gamearea[3][10]='X';//player 2 penalty points
gamearea[3][18]='X';//player 2 penalty points
gamearea[5][26]='X';//player 2 penalty points
gamearea[10][26]='X';//player 2 penalty points
gamearea[11][10]='X';//player 2 penalty points
gamearea[11][18]='X';//player 2 penalty points
gamearea[2][1]='_';//player 1 finish line
gamearea[4][3]='_';//player 2 finish line
gamearea[1][1]='1';
gamearea[3][3]='2';
printMap(gamearea);
int t=startGame();
char c;
if(t==1){
printf("*PLAYER 1 will start the game... *\n");
}
else printf("*PLAYER 2 will start the game... *\n");
int a=1;
int b=1;
int x=3;
int y=3;
int ranplayer1,ranplayer2;
int player1finish,player2finish;
do{
switch(t){
    case 1: //first player will start
    printf("\033[0;33m");
    printf("PLAYER 1... press ENTER to dice\n");
    scanf("%c",&c);
    ranplayer1=dice();
    printf("DICE: %d\n",ranplayer1);
    printf("\033[0m");
    
 if(b+ranplayer1<28 && a == 1)  //player one goes to right
    {
    gamearea[a][b]=' ';
    b=b+ranplayer1;
          if(b==14 ){ //penalty place
           b=b-2;
           printf("\033[0;33m");
           printf("Penalty for player 1...\n");
           printf("\033[0m");}
    gamearea[a][b]='1';
           }
else if(b+ranplayer1>=28 && a==1){ //it moves around the corner
      gamearea[a][b]=' ';
      z=28-b;
      ranplayer1 = ranplayer1 - z;
      b = b + z;
      a=a+ranplayer1;
      gamearea[a][b]='1';
          }


 else if (b==28 && a+ranplayer1<13){ // it goes downwards
       gamearea[a][b]=' ';
       a=a+ranplayer1;
              if(a==7){
               a=a-2;
               printf("\033[0;33m");
               printf("Penalty for player 1...\n");
                printf("\033[0m");}
       gamearea[a][b]='1';

    }
    else if(a+ranplayer1>=13 && b==28){//it moves around the corner
        gamearea[a][b]=' ';
        z=13-a;
        ranplayer1=ranplayer1 - z;
        a=a+z;
        b=b-ranplayer1;
        gamearea[a][b]='1';
    }
    else if(b-ranplayer1>1 && a==13) // it goes to left
    {
        gamearea[a][b]=' ';
        b=b-ranplayer1;
               if(b==7){
                   b=b-2;
                    printf("\033[0;33m");
                    printf("Penalty for player 1...\n");
                    printf("\033[0m");}
        gamearea[a][b]='1';
    }

   else if(b-ranplayer1<=1 && a==13){ //it moves around the corner
     gamearea[a][b]=' ';
     z=b-1;
     ranplayer1=ranplayer1-z;
     b=b-z;
     a=a-ranplayer1;
     gamearea[a][b]='1';
   }
   else if(a-ranplayer1>1 && b==1) //it goes upwards
   {
        gamearea[a][b]=' ';
        a=a-ranplayer1;
        gamearea[a][b]='1';
       if(a == 2) player1finish = 1;
   }
   else if(a-ranplayer1<=1 && b==1) //it moves around the corner
   {
     player1finish = 1;
     gamearea[a][b]=' ';
     z=a-1;
     ranplayer1=ranplayer1-z;
     a=a-z;
     b=b+ranplayer1;
      gamearea[a][b]='1';
   }
 printf("\033[0;34m");
printf("PLAYER 2... press ENTER to dice\n");
scanf("%c",&c);
ranplayer2=dice();
printf("DICE: %d\n",ranplayer2);
 printf("\033[0m");
if(y+ranplayer2<26 && x == 3) //player one goes to right
    {gamearea[x][y]=' ';
    y=y+ranplayer2;
           if(y==10){
              y=y -2;
               printf("\033[0;34m");
              printf("Penalty for player 2...\n");
               printf("\033[0m");}
           if(y==18){
             y=y -2;
              printf("\033[0;34m");
             printf("Penalty for player 2...\n");
              printf("\033[0m");}   
    gamearea[x][y]='2';
    }
else if(y+ranplayer2>=26 && x==3){ //it moves around the corner
    gamearea[x][y]=' ';
    z=26-y;
    ranplayer2 = ranplayer2 - z;
    y = y + z;
    x=x+ranplayer2;
    gamearea[x][y]='2';
           }
else if (y==26 && x+ranplayer2<11){ // it goes downwards

     gamearea[x][y]=' ';
     x=x+ranplayer2;
           if(x==5){
             x=x-2;
              printf("\033[0;34m");
             printf("Penalty for player 2...\n");
              printf("\033[0m");}
           if(x==10){
             x=x-2;
              printf("\033[0;34m");
             printf("Penalty for player 2...\n");
              printf("\033[0m");}
    gamearea[x][y]='2';
    }
else if(x+ranplayer2>=11 && y==26){ //it moves around the corner
        gamearea[x][y]=' ';
        z=11-x;
        ranplayer2=ranplayer2 - z;
        x=x+z;
        y=y-ranplayer2;
        gamearea[x][y]='2';
    }
else if(y-ranplayer2>3 && x==11)//it goes to left
    {
        gamearea[x][y]=' ';
        y=y-ranplayer2;
              if(y==10){
                y=y-2;
                 printf("\033[0;34m");
                printf("Penalty for player 2...\n");
                 printf("\033[0m");}
             if(y==18){
                y=y-2;
                 printf("\033[0;34m");
                printf("Penalty for player 2...\n");
                 printf("\033[0m");}
        gamearea[x][y]='2';
    }

else if(y-ranplayer2<=3 && x==11){ //it moves around the corner

     gamearea[x][y]=' ';
     z=y-3;
     ranplayer2=ranplayer2-z;
     y=y-z;
     x=x-ranplayer2;
     gamearea[x][y]='2';
   }
else if(x-ranplayer2>3 && y==3)//it goes upwards
   {
        gamearea[x][y]=' ';
        x=x-ranplayer2;
        gamearea[x][y]='2';
       if(x==2)player2finish = 1;
   }
else if(x-ranplayer2<=3 && y==3) //it moves around the corner
   { player2finish = 1;
     gamearea[x][y]=' ';
     z=x-3;
     ranplayer2=ranplayer2-z;
     x=x-z;
     y=y+ranplayer2;
     gamearea[x][y]='2';
   }
printMap(gamearea);
break;
case 2:
 printf("\033[0;34m");
printf("PLAYER 2... press ENTER to dice\n");
scanf("%c",&c);
ranplayer2=dice();
printf("DICE: %d\n",ranplayer2);
 printf("\033[0m");
if(y+ranplayer2<26 && x == 3) //player one goes to right
    {gamearea[x][y]=' ';
    y=y+ranplayer2;
           if(y==10){
              y=y -2;
               printf("\033[0;34m");
              printf("Penalty for player 2...\n");
               printf("\033[0m");}
           if(y==18){
             y=y -2;
              printf("\033[0;34m");
             printf("Penalty for player 2...\n");
              printf("\033[0m");}   
    gamearea[x][y]='2';
    }
else if(y+ranplayer2>=26 && x==3){ //it moves around the corner
    gamearea[x][y]=' ';
    z=26-y;
    ranplayer2 = ranplayer2 - z;
    y = y + z;
    x=x+ranplayer2;
    gamearea[x][y]='2';
           }
else if (y==26 && x+ranplayer2<11){ // it goes downwards

     gamearea[x][y]=' ';
     x=x+ranplayer2;
           if(x==5){
             x=x-2;
              printf("\033[0;34m");
             printf("Penalty for player 2...\n");
              printf("\033[0m");}
           if(x==10){
             x=x-2;
              printf("\033[0;34m");
             printf("Penalty for player 2...\n");
              printf("\033[0m");}
    gamearea[x][y]='2';
    }
else if(x+ranplayer2>=11 && y==26){ //it moves around the corner
        gamearea[x][y]=' ';
        z=11-x;
        ranplayer2=ranplayer2 - z;
        x=x+z;
        y=y-ranplayer2;
        gamearea[x][y]='2';
    }
else if(y-ranplayer2>3 && x==11)//it goes to left
    {
        gamearea[x][y]=' ';
        y=y-ranplayer2;
              if(y==10){
                y=y-2;
                 printf("\033[0;34m");
                printf("Penalty for player 2...\n");
                 printf("\033[0m");}
             if(y==18){
                y=y-2;
                 printf("\033[0;34m");
                printf("Penalty for player 2...\n");
                 printf("\033[0m");}
        gamearea[x][y]='2';
    }

else if(y-ranplayer2<=3 && x==11){ //it moves around the corner

     gamearea[x][y]=' ';
     z=y-3;
     ranplayer2=ranplayer2-z;
     y=y-z;
     x=x-ranplayer2;
     gamearea[x][y]='2';
   }
else if(x-ranplayer2>3 && y==3)//it goes upwards
   {   
        gamearea[x][y]=' ';
        x=x-ranplayer2;
        gamearea[x][y]='2';
        if(x==4)player2finish = 1;
   }
else if(x-ranplayer2<=3 && y==3) //it moves around the corner
   { player2finish = 1;
     gamearea[x][y]=' ';
     z=x-3;
     ranplayer2=ranplayer2-z;
     x=x-z;
     y=y+ranplayer2;
     gamearea[x][y]='2';
   }
 printf("\033[0;33m");
printf("PLAYER 1... press ENTER to dice\n");
scanf("%c",&c);
    ranplayer1=dice();
    printf("DICE: %d\n",ranplayer1);
     printf("\033[0m");
 if(b+ranplayer1<28 && a == 1) //player one goes to right
    {
    gamearea[a][b]=' ';
    b=b+ranplayer1;
          if(b==14 ){
             b=b-2;
             printf("\033[0;33m");
             printf("Penalty for player 1...\n");
              printf("\033[0m");}
   gamearea[a][b]='1';
           }
else if(b+ranplayer1>=28 && a==1){ //it moves around the corner
      gamearea[a][b]=' ';
      z=28-b;
      ranplayer1 = ranplayer1 - z;
      b = b + z;
      a=a+ranplayer1;
   gamearea[a][b]='1';
          }
else if (b==28 && a+ranplayer1<13){// it goes downwards
           gamearea[a][b]=' ';
           a=a+ranplayer1;
              if(b==7){
                b=b-2;
                 printf("\033[0;33m");
                printf("Penalty for player 1...\n");
                 printf("\033[0m");}
           gamearea[a][b]='1';

    }
else if(a+ranplayer1>=13 && b==28){ //it moves around the corner
        gamearea[a][b]=' ';
        z=13-a;
        ranplayer1=ranplayer1 - z;
        a=a+z;
        b=b-ranplayer1;
        gamearea[a][b]='1';
    }
    else if(b-ranplayer1>1 && a==13)//it goes to left
    {
        gamearea[a][b]=' ';
        b=b-ranplayer1;
            if(b==14 ){
               b=b-2;
                printf("\033[0;33m");
               printf("Penalty for player 1...\n");
                printf("\033[0m");}
        gamearea[a][b]='1';
    }

   else if(b-ranplayer1<=1 && a==13){ //it moves around the corner
     gamearea[a][b]=' ';
     z=b-1;
     ranplayer1=ranplayer1-z;
     b=b-z;
     a=a-ranplayer1;
     gamearea[a][b]='1';
   }
   else if(a-ranplayer1>1 && b==1)//it goes upwards
   {
        gamearea[a][b]=' ';
        a=a-ranplayer1;
        gamearea[a][b]='1';
         if(a == 2) player1finish = 1;
   }
   else if(a-ranplayer1<=1 && b==1) //it moves around the corner
   {   player1finish = 1;
       gamearea[a][b]=' ';
       z=a-1;
       ranplayer1=ranplayer1-z;
       a=a-z;
       b=b+ranplayer1;
       gamearea[a][b]='1';


   }

printMap(gamearea);


   break;
}}while(player1finish != 1 && player2finish != 1);

   if(t == 1){
   
     if(player1finish == 1){   //player 1 is the first one who gets to the finish line
       printf("\033[0;33m");
       printf("Player 1 won the game!\n");
       printf("\033[0m");
       }
        else{
          printf("\033[0;34m");
          printf("Player 2 won the game!\n");
          printf("\033[0m");
          }
   }else{
      if(player2finish == 1){  //player 2 is the first one who gets to the finish line
      printf("\033[0;34m");
       printf("Player 2 won the game!\n");
       printf("\033[0m");
       }
        else{
          printf("\033[0;33m");
          printf("Player 1 won the game!\n");
          printf("\033[0m");
          }
   }
    return 0;
}
void printMap(char gamearea[15][30]){
int i,j;
char a;

for(i = 0;i < 15;i++){
     for(j = 0;j < 30;j++){
      a = gamearea[i][j];
      if(a == '1'){
        printf("\033[0;33m");
        printf("%c",a);
        printf("\033[0m");
      }else if(a == '2'){
        printf("\033[0;34m");
        printf("%c",a);
        printf("\033[0m");
      }else if(a == '_'){
        printf("\033[0;32m");
        printf("%c",a);
        printf("\033[0m");
      }else if(a == 'X'){
        printf("\033[0;31m");
        printf("%c",a);
        printf("\033[0m");
      }else printf("%c",a);
     }
     printf("\n");
     }
}
int dice()
{
  int r = rand()%6+1; // Returns a pseudo-random integer between 0 and RAND_MAX.
  return r;
}
int startGame()
{
int player1,player2;
printf("to start to game , players shoruld dice ande decide who is going to star fisrt according to it...\n");
char c;
printf("\033[0;33m");
printf("PLAYER 1... press ENTER to dice\n");
scanf("%c",&c);
player1=dice();  //
printf("DICE: %d\n",player1);
printf("\033[0m");

printf("\033[0;34m");
printf("PLAYER 2... press ENTER to dice\n");
scanf("%c",&c);
player2=dice();
printf("DICE: %d\n",player2);
printf("\033[0m");

while(player1==player2){ //if the dices equal the each other
printf("same dice value... please try again\n");
printf("\033[0;33m");
printf("PLAYER 1... press ENTER to dice\n");
scanf("%c",&c);
player1=dice();
printf("DICE: %d\n",player1);
printf("\033[0m");

printf("\033[0;34m");
printf("PLAYER 2... press ENTER to dice\n");
scanf("%c",&c);
player2=dice();
printf("DICE: %d\n",player2);
printf("\033[0m");

}
if(player1>player2){
return 1;}
else
return 2;
}
