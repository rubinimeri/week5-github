#include "tasks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tasklist_init(TaskList *list, size_t initial_capacity) {
  if (initial_capacity == 0)
    initial_capacity = 2;
  list->items = malloc(initial_capacity * sizeof(char *));
  if (list->items == NULL)
    return -1;
  list->count = 0;
  list->capacity = initial_capacity;
  return 0;
}

int tasklist_add(TaskList *list, const char *text) {
  if (list->count == list->capacity) {
    size_t new_capacity = list->capacity * 2;
    char **grown = realloc(list->items, new_capacity * sizeof(char *));
    if (grown == NULL)
      return -1;
    list->items = grown;
    list->capacity = new_capacity;
  }

  size_t len = strlen(text);
  char *copy = malloc(len + 1);
  if (copy == NULL)
    return -1;
  memcpy(copy, text, len + 1);

  list->items[list->count++] = copy;
  return 0;
}

void tasklist_print(const TaskList *list) {
  if (list->count == 0) {
    printf("No tasks yet.\n");
    return;
  }
  for (size_t i = 0; i < list->count; i++) {
    printf("Task %zu: %s\n", i + 1, list->items[i]);
  }
}

void tasklist_free(TaskList *list) {
  for (size_t i = 0; i < list->count; i++) {
    free(list->items[i]);
  }
  free(list->items);
  list->items = NULL;
  list->count = 0;
  list->capacity = 0;
}

void print_menu(void) {
  printf("1 (See tasks) - 2 (Create new task) - 3 (End program)\n");
}

ProgramState read_choice(void) {
  char line[32];
  if (fgets(line, sizeof line, stdin) == NULL)
    return STATE_QUIT; /* EOF: quit */

  char *end;
  long value = strtol(line, &end, 10);
  if (end == line || value < STATE_SHOW || value > STATE_QUIT) {
    printf("Please type 1, 2 or 3.\n");
    return STATE_MENU;
  }
  return (ProgramState)value;
}

int read_task(char *buffer, size_t size) {
  if (fgets(buffer, (int)size, stdin) == NULL)
    return -1;

  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[--len] = '\0';
  } else {
    /* Line was longer than the buffer: throw away the rest of it. */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
  }
  return len == 0 ? -1 : 0;
}
