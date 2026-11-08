#include "tasks.h"
#include <stdio.h>

int main(void) {
  TaskList tasks;
  if (tasklist_init(&tasks, 2) != 0) {
    fprintf(stderr, "Out of memory\n");
    return 1;
  }
  tasklist_add(&tasks, "Go to the gym");
  tasklist_add(&tasks, "Study programming");

  ProgramState state = STATE_MENU;

  while (state != STATE_QUIT) {
    if (state == STATE_SHOW) {
      tasklist_print(&tasks);
    } else if (state == STATE_ADD) {
      char task[MAX_LIMIT];
      printf("Input task with maximum of %d characters: ", MAX_LIMIT - 1);
      if (read_task(task, sizeof task) == 0) {
        if (tasklist_add(&tasks, task) == 0) {
          printf("The new task: %s\n", task);
        } else {
          printf("Could not save the task (out of memory).\n");
        }
      } else {
        printf("Empty task, nothing added.\n");
      }
    }

    print_menu();
    state = read_choice();
  }

  printf("Shutting down program...\n");
  tasklist_free(&tasks);
  return 0;
}
