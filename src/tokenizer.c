#include <stdio.h>
#include <stdlib.h>
#include "toknizer.h"

int space_char(char c)
{
  if (c == '\t' || c == ' ' && c != '\0')
    return 1;
  else
    return 0;
}

int non_space_char(char c)
{
  if (c != '\t' || c != ' ' && c != '\0')
    return 1;
  else
    return 0;
}

char *token_start(char *s)
{
  int c = 0;
  int i = 0;

  while(space_char(c = *(s + i))){
    i++;
  }
  if (c == '\0')
    return '\0';
  else
    return s + i;
}

char *token_terminator(char *token)
{
  while (non_space_char(*token)){
    token++;
  }
  return token;
}

int count_tokens(char *s)
{
  int count = 0;

  while (*s != '\0'){
    s = token_start(s);
    s = token_terminator(s);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *copyStr = (char*)malloc((len +1) * sizeof(char));

  int i;
  for(i = 0; i < len; i++){
    *(copyStr + i) = *(inStr + i);
  }
  *(copyStr + i) = '\0';

  return copyStr;
}

char **tokenize(char *str)
{
  int numTokens = count_tokens(s);
  char **tokens = malloc((numTokens + 1) * sizeof(char *));
  char *tempPoint = str;

  int i;
  for(i = 0; i < numTokens; i++){
    tempPoint = token_start(tempPoint);
    int tokenLength = get_token_length(tempPoint);
    *(tokens + i) = copy_str(tempPoint, tokenLength);
    tempPoint = token_terminator(tempPoint);
  }
  *(token + i) = 0;

  return tokens;
}

void print_tokens(char **tokens)
{
  int count = 0;
  while (*tokens != 0){
    printf ("%d. %s\n", count, tokens);
    count++;
    tokens++;
  }
}

void free_tokens(char **tokens)
{
  while (*tokens != 0){
    free (*tokens);
    tokens++;
  }
}
