/**
 * Stacks are LIFO (Last In/First Out)
 */
#define K	1024

int stack[K];
int sp = -1;

// Adds value to the stack:
void push(int value)
{
  if (sp >= K) abort("Stack overflow");
  stack[++sp] = value;
}

// Returns the value from the top of the stack:
int pop(void)
{
  if (sp < 0) abort("Stack underflow");
  int value = stack[sp--];
}

// Like pop(), but does not remove the value:
int peek(void)
{
  if (sp < 0) abort("Stack underflow");
  int value = stack[sp];
}
