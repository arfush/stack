#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef void *stack_object_t;

typedef struct stack_s stack_t;

stack_t *create_stack();

stack_object_t stack_shift(stack_t *stack);

void stack_push(stack_t *stack, stack_object_t object);

void stack_free(stack_t *stack);

#endif //STACK_STACK_H
