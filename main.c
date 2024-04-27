#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

int wins = 0;
int losses = 0;
int ties = 0;
int newChoice = 0;

char continuer[3] = "";
char userChoice[8] = "";

int clearTerminal()
{
  /* works on linux, idk about windows cuz i dont use it */
  printf("\e[1;1H\e[2J");
  return 1;
}

int game()
{
  /* user choice turns to number cuz i have no fucking idea on how to pick random thing from an array */
  /* rock = 1
   * paper = 2
   * scissors = 3
  */

  clearTerminal();
  printf("--[[ C Rock-Paper-Scissors ]]--\n--[[ Made this to learn C ]]--\n--[[ Wins: %d ]]--\n--[[ Losses: %d ]]--\n--[[ Ties: %d ]]--", wins, losses, ties);
  printf("\n[!] What do you choose? (rock, paper or scissors) ");
  scanf("%s", userChoice);
  
  if(strcmp(userChoice, "rock") && strcmp(userChoice, "paper") && strcmp(userChoice, "scissors"))
  {
    printf("[!] %s is not a valid option\n", userChoice);
    return 1;
  } else {
    if(strcmp(userChoice, "rock") == 0) 
    {
      newChoice = 1;
    } else if(strcmp(userChoice, "paper") == 0) 
    {
      newChoice = 2;
    } else if(strcmp(userChoice, "scissors") == 0) 
    {
      newChoice = 3;
    }

  int randChoice = rand() % 4;

  if(randChoice == 0) 
  {
    randChoice = 1;
  }

  printf("\n");

    /* bot chose rock, user choose paper
     * user wins
    */

    if(randChoice == 1 && newChoice == 2)
    {
      wins ++;
      printf("[!] I chose rock, you chose paper, you win!");
    }

    /* bot chose paper, user chose rock
     * bot wins
    */

    if(randChoice == 2 && newChoice == 1)
    {
      losses ++;
      printf("[!] I chose paper, you chose rock, I win!");
    }

    /* bot chose scissors, user chose rock 
     * user wins
    */

    if(randChoice == 3 && newChoice == 1)
    {
      wins ++;
      printf("[!] I chose scissors, you chose rock, you win!");
    }

    /* bot chose rock, user chose scissors 
     * bot wins
    */

    if(randChoice == 1 && newChoice == 3)
    {
      losses ++;
      printf("[!] I chose rock, you chose scissors, I win!");
    }

    /* bot chose scissors, user chose paper
     * bot wins
    */

    if(randChoice == 3 && newChoice == 2)
    {
      losses ++;
      printf("[!] I chose scissors, you chose paper, I win!");
    }

    /* bot chose paper, user chose scissors
     * user wins
    */

    if(randChoice == 2 && newChoice == 3)
    {
      wins ++;
      printf("[!] I chose paper, you chose scissors, you win!");
    }

    if(randChoice == newChoice)
    {
      ties ++;
      printf("[!] We both chose the same thing, its a tie!");
    }

    printf("\n");
  }

  return 0;
}

int main()
{
  srand(time(NULL));

  while(1)
  {
   printf("[!] Continue? (yes/no) ");
   scanf("%s", continuer);
   printf("");

   if(strcmp(continuer, "yes") == 0)
   {
     game();
   }
   else
   {
     printf("[!] Goodbye!");
     break;
   }
  }
}

