#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define	K	1024

typedef enum {
  T_PLUS, T_MINUS, T_MULT, T_DIV, T_EXP, T_OPAREN, T_CPAREN,
  T_NUMBER, T_EOE, T_UNKNOWN
} token_t;

struct oper {
  token_t op;       // The operator token
  int prec;         // The operator precedence
  int dir;          // The associativity (0 = left-to-right, 1=right-to-left)
  int unary;        // Flag if the operator is the unary version.
};

typedef enum { NUMBER, OPERATOR } flag_t;
typedef enum { TRUE=1, FALSE=0 } bool;

// lex.c:
token_t lex(int *value);
void startlex(char *s);

// expr.c:
int expr(char *str);
