#include "linked_list.h"

struct linked_list *linked_list_initialization() {
  struct linked_list *list = malloc(sizeof(*list));
  if (list == NULL) {
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  list->length = 0;
  return list;
}

struct linked_list_node *linked_list_add_in_head(struct linked_list *list, void *new_data) {
  struct linked_list_node *node_new = malloc(sizeof(*node_new));
  if (list == NULL || node_new == NULL) {
    exit(EXIT_FAILURE);
  }
  node_new->data = new_data;
  node_new->next = list->head;
  list->head = node_new;
  list->length = list->length + 1;
  return node_new;
}

void linked_list_delete_in_head(struct linked_list *list) {
  if (list == NULL) {
    exit(EXIT_FAILURE);
  }
  if (list->head != NULL) {
    struct linked_list_node *node_to_remove = list->head;
    list->head = list->head->next;
    list->length = list->length - 1;
    free(node_to_remove);
  }
}

struct linked_list_node *linked_list_add_after_last(struct linked_list *list, void *new_data) {
  if (list->head == NULL) {
    return linked_list_add_in_head(list, new_data);
  }
  struct linked_list_node *node_new = malloc(sizeof(*node_new));
  if (list == NULL || node_new == NULL) {
    exit(EXIT_FAILURE);
  }
  node_new->data = new_data;
  node_new->next = NULL;
  struct linked_list_node *node_current_last = list->head;
  size_t index = 0;
  while (index < list->length - 1) {
    node_current_last = node_current_last->next;
    index++;
  }
  node_current_last->next = node_new;
  list->length = list->length + 1;
  return node_new;
}

struct linked_list *linked_list_reverse(struct linked_list *list) {
  struct stack *stack = stack_initialization();
  struct linked_list_node *linked_list_node_current = list->head;
  while (linked_list_node_current != NULL) {
    stack_push(stack, linked_list_node_current->data);
    linked_list_node_current = linked_list_node_current->next;
  }
  struct linked_list *linked_list_reversed = linked_list_initialization();
  struct stack_node *stack_node_current = stack->first;
  while (stack_node_current != NULL) {
    linked_list_add_after_last(linked_list_reversed, stack_node_current->data);
    stack_node_current = stack_node_current->next;
  }
  return linked_list_reversed;
}

void linked_list_reverse_mutate(struct linked_list *list) {
  struct linked_list_node **current = &list->head;
  struct linked_list_node *previous = NULL;
  while (true) {
    struct linked_list_node *temporary_current = (*current)->next;
    (*current)->next = previous;
    previous = *current;
    if (temporary_current == NULL) {
      break;
    }
    (*current) = temporary_current;
  }
}
