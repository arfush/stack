#include <stdlib.h>

#include <stack.h>

typedef struct stack_entity_s stack_entity_t;
struct stack_entity_s {
    stack_object_t object;
    stack_entity_t *next;
};

stack_entity_t *create_stack_entity(stack_object_t object, stack_entity_t *next) {
    stack_entity_t *entity = malloc(sizeof(stack_entity_t));
    entity->object = object;
    entity->next = next;

    return entity;
}

void stack_entry_free(stack_entity_t *stack_entity) {
    free(stack_entity);
}


struct stack_s {
    stack_entity_t *head;
};


stack_t *create_stack() {
    stack_t *stack = malloc(sizeof(stack_t));
    stack->head = NULL;

    return stack;
}

stack_object_t stack_shift(stack_t *stack) {
    stack_entity_t *head = stack->head;
    if (head == NULL) {
        return NULL;
    }
    stack_object_t object = head->object;
    stack->head = head->next;
    stack_entry_free(head);
    return object;
}

void stack_push(stack_t *stack, stack_object_t object) {
    stack_entity_t *entity = create_stack_entity(object, stack->head);
    stack->head = entity;
}

void stack_free(stack_t *stack) {
    stack_entity_t *current = stack->head;
    stack_entity_t *next;
    while (current != NULL) {
        next = current->next;
        stack_entry_free(current);
        current = next;
    }
    free(stack);
}
