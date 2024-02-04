//Comments there for explaining any function or operation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int piece1 = 0, piece2 = 0, piece3 = 0, piece4 = 0, comp = 0;

void delay(int seconds) {
  int milsec = 1000 * seconds;
  clock_t startTime = clock();
  while(clock() < (startTime + milsec));
}

//Function to check if player got a snake on his current tile

int snake(int snakeStart[], int snakeEnd[], int count, int num) {
    for (int i = 0; i <= 6; i++) {
        if (num == snakeStart[i]) {
            num = snakeEnd[i];
            count++;
            printf("Oops!! The piece was eaten by a snake, New location of the piece: %d\n", num);
            break;
        }
    }
    return num;
}

//Function to check if player got a ladder on his current tile, if player gets 100 or crosses 100 he wins

int ladder(int ladderStart[], int ladderEnd[], int count, int num) {
    if (count == 0) {
        for (int i = 0; i < 6; i++) {
            if (num == ladderStart[i]) {
                num = ladderEnd[i];
                printf("Bingo!! Ladder received. The piece is boosted to new location: %d\n", num);
                break;
            }
        }
    }
    return num;
}

int computer(int diceNumbers[], int ladderStart[], int ladderEnd[], int snakeStart[], int snakeEnd[], int c) {
    int temp, number, count = 0;
    printf("\n\n\n");
        number = rand() % 6;
        temp = c;
        c = c + diceNumbers[number];

//This if checks for sixes on the dice if any

        if (c - temp == 6 && c < 100) {
          while(c-temp == 6){
            printf("Computer got a 6, his turn again: \n");
            
                number = rand() % 6;
                temp = c;
                c = c + diceNumbers[number];
            
          }
                if (c < 100) {
                    printf("Computer's piece got %d and his piece is on %d Square\n", diceNumbers[number], c);
                    c = snake(snakeStart, snakeEnd, count, c);
                    c = ladder(ladderStart, ladderEnd, count, c);
                }

                  //If piece counting variable crosses 100 or reaches 100 then it ends the code by printing the winner

                else if (c >= 100) {
                    printf("Opps!! Computer got the price.");
                    exit(1);
                }
                // break;
          // return c;
        } 
        else if (c - temp != 6 && c < 100) {
            printf("Computer got %d on dice, his piece is on %d Square\n", diceNumbers[number], c);
            c = snake(snakeStart, snakeEnd, count, c);
            c = ladder(ladderStart, ladderEnd, count, c);
            // break;
          // return c;
        }

          //If piece counting variable crosses 100 or reaches 100 then it ends the code by printing the winner

        else if (c >= 100) {
            printf("Opps!! Computer got the price");
            exit(1);
        }
    return c;
}
//Player function which will return the new location of the pieces

int player1(char name1[], int diceNumbers[], int ladderStart[], int ladderEnd[], int snakeStart[], int snakeEnd[], int c) {
    int temp, number, count = 0;
    printf("\n\n\n*****[ Press enter to run the piece for %s ]*****\n", name1);
    while (getchar() == '\n') {
        number = rand() % 6;
        temp = c;
        c = c + diceNumbers[number];

//This if checks for sixes on the dice if any

        if (c - temp == 6 && c < 100) {
          while(c-temp == 6){
            printf("Bingo you got a 6, press enter again: \n");
            if (getchar() == '\n') {
                number = rand() % 6;
                temp = c;
                c = c + diceNumbers[number];
            }
          }
                if (c < 100) {
                    printf("You got a %d on dice, Your piece is on %d square\n", diceNumbers[number], c);
                    c = snake(snakeStart, snakeEnd, count, c);
                    c = ladder(ladderStart, ladderEnd, count, c);
                }
                
                  //If piece counting variable crosses 100 or reaches 100 then it ends the code by printing the winner
                
                else if (c >= 100) {
                    printf("Congratulations!! %s is the winner.", name1);
                    exit(1);
                }
                break;
          // return c;
        } 
        else if (c - temp != 6 && c < 100) {
            printf("You got %d on dice, Your piece is on %d location\n", diceNumbers[number], c);
            c = snake(snakeStart, snakeEnd, count, c);
            c = ladder(ladderStart, ladderEnd, count, c);
            break;
          // return c;
        }
        
          //If piece counting variable crosses 100 or reaches 100 then it ends the code by printing the winner
        
        else if (c >= 100) {
            printf("Congratulations!! %s is the winner.", name1);
            exit(1);
        }
    }
  return c;
}

int main() {
    printf("----------------------Welcome to Snakes and Ladders Game------------------\n\n\nBeware of snakes on position - 43,50,56,74,84,87,98\nBut grab as many ladders as possible from positions - 2,6,20,52,57,71\nYour pieces start from 0th location\n\n\n");
    srand(time(NULL));
    char name1[100], name2[100], name3[100], name4[100];
    int diceNumbers[6] = {1, 2, 3, 4, 5, 6};
    int number, temp, count = 0;
  char num[50];
    int snakeStart[7] = {43, 50, 56, 74, 84, 87, 98}, snakeEnd[7] = {17, 5, 8, 15, 58, 49, 40}, ladderStart[6] = {2, 6, 20, 52, 57, 71}, ladderEnd[6] = {23, 45, 59, 72, 96, 92};
    printf("Enter 1 for single player / Play with Computer, 2 for two players, 3 for three players and 4 for four player game: \n");
    scanf("%s", num);

//Here three if else conditions are used to check the input and decide the number of players
  
    if (strcmp(num,"two")==0 || strcmp(num,"2")==0) {
        printf("Enter the name of each player serially: \n");
        scanf("%s", name1);
        scanf("%s", name2);
        printf("Let the match begin: \n");
      getchar();
        while (1) {
            piece1 = player1(name1, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece1);
          sleep(1);
            piece2 = player1(name2, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece2);
          sleep(1);
        }
    } else if (strcmp(num,"three")==0 || strcmp(num,"3")==0) {
        printf("Enter the name of each player serially: \n");
        scanf("%s", name1);
        scanf("%s", name2);
        scanf("%s", name3);
        printf("Let the match begin: \n");
      getchar();
        while (1) {
            piece1 = player1(name1, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece1);
          sleep(1);
            piece2 = player1(name2, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece2);
          sleep(1);
            piece3 = player1(name3, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece3);
          sleep(1);
        }
    } else if (strcmp(num,"four")==0 || strcmp(num,"4")==0) {
        printf("Enter the name of each player serially: \n");
        scanf("%s", name1);
        scanf("%s", name2);
        scanf("%s", name3);
        scanf("%s", name4);
        printf("Let the match begin: \n");
      getchar();
        while (1) {
            piece1 = player1(name1, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece1);
          sleep(1);
            piece2 = player1(name2, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece2);
          sleep(1);
            piece3 = player1(name3, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece3);
          sleep(1);
            piece4 = player1(name4, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece4);
          sleep(1);
        }
    }
      else if(strcmp(num,"one")==0 || strcmp(num,"1")==0){
        printf("Enter the name of player: \n");
        scanf( "%s", name1);
        getchar();
        while(1){
          sleep(1);
        comp = computer(diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, comp);
          sleep(1);
          piece1 = player1(name1, diceNumbers, ladderStart, ladderEnd, snakeStart, snakeEnd, piece1);
        }
      }
  else{
    printf("Invalid input!!");
  }
    return 0;
}
