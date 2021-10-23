#ifndef H_STACK
#define H_STACK

#define S_MAX_SIZE 100

typedef Item SEltype;

typedef struct stack
{
  SEltype buffer[S_MAX_SIZE];
  int idxTop;
} Stack;

void s_create_stack(Stack* s);

boolean s_is_empty(Stack s);
boolean s_is_full(Stack s);

void s_push(Stack* s, SEltype item);
void s_pop(Stack* s, SEltype* item);

SEltype s_get_top(Stack s);

#endif