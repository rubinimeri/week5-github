#ifndef TASKS_H
#define TASKS_H

#include <stddef.h>

/* Maximum length of one task, including the terminating '\0'. */
#define MAX_LIMIT 100

/* The menu options. Values match the numbers the user types. */
typedef enum {
  STATE_MENU = 0,
  STATE_SHOW = 1,
  STATE_ADD = 2,
  STATE_QUIT = 3
} ProgramState;

/* A growable list of tasks. */
typedef struct {
  char **items;    /* array of task strings (each one malloc'd) */
  size_t count;    /* how many tasks are stored */
  size_t capacity; /* how many fit before we must grow */
} TaskList;

/* Task list management */
int tasklist_init(TaskList *list,
                  size_t initial_capacity); /* 0 on success, -1 on failure */
int tasklist_add(
    TaskList *list,
    const char *text); /* copies text; 0 on success, -1 on failure */
void tasklist_print(const TaskList *list);
void tasklist_free(TaskList *list);

/* User input / output */
void print_menu(void);
ProgramState read_choice(void); /* returns STATE_MENU on invalid input */
int read_task(char *buffer, size_t size); /* 0 on success, -1 on EOF/empty */

#endif /* TASKS_H */
