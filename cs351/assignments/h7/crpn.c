#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define K	1024

/**
 * Enums are a lot like #defines, they are integer values that are given names.
 * The value for T_NUMBER is 0, T_PLUS is 1, etc.  You can convert these to
 * %defines in assembly.
 */
typedef enum { TRUE=1, FALSE=0 } bool;
typedef enum {
  T_NUMBER, T_PLUS, T_MINUS, T_MULT, T_DIV, T_EXP, T_OPAREN, T_CPAREN, T_EOE,
  T_UNKNOWN
} token_t;

// These prototypes should remain even after you comment out the C function:
int get(void);
void unget(void);
bool next(int c);
token_t lex(int *value);
void push(int v);
int pop(void);

// (1pt):
char *input;
int pos;
int numstack[K];
int nsp;

// (1pt)
// Gets the next character, returns -1 on end of input:
int get(void)
{
  if (input[pos] == '\0') return -1;
  return input[pos++];
}

// (1pt)
// Unget a character:
void unget(void)
{
  if (pos && input[pos] != '\0') pos--;
}

// (2pts)
// If the next character matches c, then move past it and return TRUE,
// otherwise do nothing and return FALSE
bool next(int c)
{
  if (input[pos] == c) {
    pos++;
    return TRUE;
  }
  return FALSE;
}

/** (7pts)
 * Returns the next token. Fills value in with the value of the number for
 * T_NUMBER tokens.
 */
token_t lex(int *value)
{
  int c, n;

  // Skip over any white-space:
  do {
    c = get();
  } while(isspace(c));

  switch(c) {
    case -1: return T_EOE;
    case '+': return T_PLUS;
    case '-': return T_MINUS;
    case '/': return T_DIV;
    case '(': return T_OPAREN;
    case ')': return T_CPAREN;
    case '*':
      if (next('*')) return T_EXP;
      return T_MULT;
    default:
      if (isdigit(c)) {
	n = 0;
	do {
	  n *= 10;
	  n += (c-'0');
	} while (isdigit(c = get()));
	unget();
	*value = n;
	return T_NUMBER;
      }
      return T_UNKNOWN;
  }

  // NOT REACHED
  return T_UNKNOWN;
}



// (1pt)
void push(int v)
{
  numstack[nsp++] = v;
}

// (2pts)
int pop(void)
{
  if (nsp == 0) {
    printf("Stack underflow.\n");
    exit(1);
  }
  return numstack[--nsp];
}

// (5pts)
int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: <expression-string>\n");
    return 0;
  }
  input = argv[1];
  int num, l, r;
  token_t tok;

  while ((tok = lex(&num)) != T_EOE) {
    switch(tok) {
      case T_NUMBER:
	push(num);
	break;
      case T_PLUS:
	r = pop();
	l = pop();
	push(l+r);
	break;
      case T_MINUS:
	r = pop();
	l = pop();
	push(l-r);
	break;
      case T_MULT:
	r = pop();
	l = pop();
	push(l*r);
	break;
      case T_DIV:
	r = pop();
	l = pop();
	push(l/r);
	break;
    }
  }
  printf("%d\n", pop());

  return 0;
}
