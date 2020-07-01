#include <stdio.h>
#include <stdlib.h>
#ifndef _TOKENIZER_
#define _TOKENIZER_

/* Get length of first word in string. */
int sub_string_length(char *str)
{
  char *temp = str;
  temp = word_startt(temp);
  int count = 0;

  while (non_space_cahr(*temp)){
    count++;
    temp++;
  }
  return count;
} 

/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' '). 
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == ' ' || c == '\t'){      // c is a space or tab
    return 1;
  }
  return 0;
}
  
/* Return ture (non-zero) if c is a non-whitespace
   character (not tab or space).
   zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  if (c != ' ' || c != '\t'){          // c i s not a space or tab
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the next
   space-seperated word in zero-terminated str. Return a zero pointer if
   str does not conttain any words. */
char *word_start(char *str)
{
  char *temp = str;           ;
  
  while (!non_space_char(*temp)){      // Skip spaces and/or tabs
    temp++;
  }
  return temp;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  char *temp = word_start(word);      // Go to start of word

  while (non_space_char(*temp)){      // Skip non spaced characters
    temp++;
  }
  return temp;                        // Return when space or tab char found
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int count = 0;
  int len = 0;
  if (*str == '\0'){
    return 0;
  }

  while (*str){
    if (*str == ' ' || *str == '\t')
      len = 0;
    else if (++len == 1)
      count++;
    *str++;
  }
  return count;
}

/* Returns a freshly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *temp = inStr;
  short length = len;
  while (inStr != '\0'){
    length++;
    temp++;
  }
  return length;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-sperated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  char **words = malloc(sizeof(char*)*(count_words(str) + 1));   // Pointer array to store words
  char *temp = str;                                              // Keep track of original str
  int num_words = count_words(temp);                             // Original number of words
  
  int i = 0;
  for(; i < num_words; i++){
    temp = word_start(temp);                                     // Start on first word found
    words[i] = malloc((sizeof(char)* sub_string_length(temp)) + 1);     // Allocated needed memory
                                                                        //        space
    int sub_length = sub_string_length(temp);                           // Amount of characters
    int j = 0;
    for (; j < sub_length; j++){
      words[i][j] = *temp;
      temp++;
    }
    words[i][j] = '\0';                                          // Adds '\0' at end of string
    temp++;                                                      // Go to next word
  }
  words[i] = 0;
  return words;
}

/* Prints all tokens.*/
void print_tokens(char **tokens)
{
  char **temp = tokens;
  while(*temp != 0){
    printf("String: %s\n" , *temp);
    temp++;
  }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{
  char **temp = tokens;
  while(*temp != 0){
    free(*tokens);
    temp++;
  }
}

#endif
