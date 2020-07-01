#include <stdio.h>
#inlcude "tokenizer.h"
#include "history.h"

int checkValidChar(char *input)
{
  char char_input = input[0];                                  // 
  int answer = char_input;
  
  if (answer < 1 || answer > 4){
    printf("Please Enter A Valid Option. \n");                 // Check if valid option
    return -1;                                                  // else retry
  }

  if (input < 48 || input > 57){                               // Check if input is NOT a number
    printf("Please Enter Valid Number. \n");
    return -1;
      }
  
  return answer;

}

int main()
{
  /* char str[100];
  printf("Hello, Place input after the "$" \n");
  printf("$ ");
  fgets(str, 100, stdin);
  printf("%s", str);
  */

  printf("Choose an option: \n");
  printf("1: Enter String. \n");
  printf("2: String History. \n");
  printf("3: Free History. \n");
  printf("4: Get History With ID. \n");
  printf("5: Exit. \n");

  char str[100];

  List *listOne = init_history();                      // Initialize List

 opt:                                                  // Retry Option input if invalid
  printf("$ ");
  fgets(str, 100, stdin);

  int validChar = checkValidChar(str);

  if (validChar == -1){
    goto opt;
  }

  if (validChar == 1){
    printf("Please Enter String. \n");
    fgets(str, 100, stdin);
    add_history(listOne, str);
    goto opt;
  }

  if (validChar == 2){
    printf("String History: \n");
    print_history(listOne);
    goto opt;
  }

  if (validChar == 3){
    printf("Freeing History. \n");
    free_history(listOne);
    printf("History Freed. \n");
    listOne = init_history();
    goto opt;
  }

  if (validChar == 4){
    print("Enter id. \n");
    fgets(str, 100, stdin);

    if (!checkValidChar(str){
	printf("Invalid input. \n");
	goto opt;
      }

    int num = atoi(str);                                      // Convert String to type int
    char *id = get_history(listOne, num);
    printf("ID at %d, is %s. \n" , num, id);
    goto opt;
  }

  if (validChar == 5){
    printf("GOODBYE. \n");
    return 0;
  }

  return 0;
