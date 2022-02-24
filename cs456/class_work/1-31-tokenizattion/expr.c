#include "expr.h"

//               +,  -,  *,  /, **,  (,  )      Used when unary =
int  prec[] = { 60, 60, 65, 65, 70,  0,  0};    //  false
int uprec[] = { 75, 75, -1, -1, -1, -1, -1};    //  true
int   dir[] = {  0,  0,  0,  0,  0,  0,  0};    //  false
int  udir[] = {  1,  1,  0,  0,  0,  0,  0};    //  true

void die(char *why) {
  fprintf(stderr,"%s\n", why);
  exit(1);
}

// Number stack:
int numstack[K];
int nsp = 0;

void push_num(int n) {
  numstack[nsp++] = n;
}
int pop_num(void) {
  if (nsp <= 0) die("Stack underflow");
  return numstack[--nsp];
}

// Operator stack:
struct oper opstack[K];
int osp = 0;

void push_op(token_t op, int unary, int prec, int dir) {
  opstack[osp++] = (struct oper){.op=op, .unary=unary, .prec=prec, .dir=dir};
}

struct oper pop_op(void) {
  if (osp <= 0) die("Op stack underflow");
  return opstack[--osp];
}
/**
 * Function to "peek" at the top of the op stack, T_UNKNOWN means the stack
 * is empty.
 */
token_t peek_op(void) {
  if (osp <= 0) return T_UNKNOWN;
  return opstack[osp-1].op;
}
/**
 * Peak at the just the precedence of operator at the top of the op stack:
 */
int peek_prec(void) {
  if (osp <= 0) return -1;
  return opstack[osp-1].prec;
}

void action(void)
{
  struct oper op;
  int l, r, v;

  // Get the operator:
  op = pop_op();

  // Right side is at the top of the stack, left would be underneath it,
  // unless it's a unary op
  r = pop_num();
  if (op.unary == FALSE) l = pop_num();
  else l = 0;

  // Should not be needed, we already checked at the office:
  if (uprec[op.op] == -1 && op.unary)
    die("Malformed unary expression in action.");

  // Perform the operation:
  switch(op.op) {
    case T_PLUS:  v = l + r; break;
    case T_MINUS: v = l - r; break;
    case T_MULT:  v = l * r; break;
    case T_DIV:   v = l / r; break;
    default:
      die("Illegal operation.");
  }
  // Push the result onto the stack:
  push_num(v);
}

int expr(char *str)
{
  startlex(str);
  token_t tok;
  flag_t flag = NUMBER;
  int num, p, d;

  while ((tok = lex(&num)) != T_EOE) {
    switch(tok) {
      case T_NUMBER:
        if (flag != NUMBER) die("Syntax error");
        push_num(num);
        flag = OPERATOR;
        break;
      case T_OPAREN:
        push_op(T_OPAREN, 0, 0, 0);
        flag = NUMBER;
        break;
      case T_CPAREN:
        // Drain the op stack until it reaches it's matching open paren:
        while ((tok = peek_op()) != T_UNKNOWN) {
          if (tok == T_OPAREN) break;
          action();
        }
        if (tok == T_UNKNOWN) die("Mismatched parenthesis.");
        // Removes the opening paren:
        pop_op();
        flag = OPERATOR;
        break;
      case T_PLUS:
      case T_MINUS:
      case T_MULT:
      case T_DIV:
      case T_EXP:
        // Get the precedence and direction of the current operator:
        p = (flag == NUMBER)? uprec[tok] : prec[tok];
        if (p == -1) die("Malformed expression, operator not a valid unary operator.");
        d = (flag == NUMBER)? udir[tok] : dir[tok];

        // Drain the op stack of operators of higher precedence (and equal to if
        // this op is left-assoc):
        if (d == 1) {   // Right associative
          while (peek_prec() > p)
            action();
        } else {        // Left associative
          while (peek_prec() >= p)
            action();
        }
        // Finally push the operator to the op stack:
        push_op(tok, flag==NUMBER, p, d);
        flag = NUMBER;
        break;
      default:
        die("Syntax error");
    }
  }
  // Drain the operator stack until it's empty:
  while(peek_op() != T_UNKNOWN)
    action();

  // The result of the entire expression should be the last and only value left:
  return pop_num();
}
