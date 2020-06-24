#ifndef _TOKENIZER_
#define _TOKENIZER_

/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' '). 
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  //char c;
  if (c == ' ' || c == '\t')
    return 1;
  return 0;
}
  
/* Return ture (non-zero) if c is a non-whitespace
   character (not tab or space).
   zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  //char c;
  if (c != ' ' || c != '\t')
    return 1;
  return 0;
}

/* Returns a pointer to the first character of the next
   space-seperated word in zero-terminated str. Return a zero pointer if
   str does not conttain any words. */
char *word_start(char *str)
{
  while (*str){
    if (str == '\0')
      return *str;
    else if (space_char(*str))
      str++;
    else if (non_space_char(*str))
      return *str;
  }
  return 0;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while (*word){             
    if (non_space_char(word)       //check if the pointer value is a char
	word++;                    //if it is a char, move pointer to next location
	if(space_char(word)          
	   return *word;           //return the pointed value if a space was found
  }
  return 0;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int count = 0;
  int len = 0;
  if (*str == NULL)
    return 0;

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
  

}

/* Prints all tokens. */
