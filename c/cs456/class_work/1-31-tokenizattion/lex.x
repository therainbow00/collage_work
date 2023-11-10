#include "expr.h"

char *input;
int pos = 0;

// Gets the next character, return -1 on end of input
int get(void) {
  if (input[pos] == '\0') return -1;
  return input[pos++];
}

// Unget a character:
void unget(int c)
{
  if (pos && c != -1) pos--;
}

// If the next character is c, then move past it and return TRUE, otherwise
// do nothing and return FALSE
bool next(int c) {
  if (input[pos] == c) {
    pos++;
    return TRUE;
  }
  return FALSE;
}

/**
 * Returns the next token. Fills value in with the value of a number for
 * T_NUMBER tokens.
 */
token_t lex(int *value)
{
  int c, n;

  // Skip over any white-space:
  do {
    c = get();
  } while (isspace(c));

  switch(c) {
    case -1: return T_EOE;
    case '(': return T_OPAREN;
    case ')': return T_CPAREN;
    case '+': return T_PLUS;
    case '-': return T_MINUS;
    case '*':
      if (next('*')) return T_EXP;
      return T_MULT;
    case '/': return T_DIV;
    default:
      if (isdigit(c)) {
        n=0;
        do {
          n *= 10;
          n += (c-'0');
        } while (isdigit(c = get()));
        *value = n;
        unget(c);
        return T_NUMBER;
      }
      // optionally return the back character back to the input.
      unget(c);
      return T_UNKNOWN;
  }
  // NOT REACHED
  return T_UNKNOWN;
}

void startlex(char *s)
{
  input = s;
  pos = 0;
}
