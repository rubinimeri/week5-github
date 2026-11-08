#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 100

int main() {
  int program_state = 0;
  int capacity = 2;
  char **tasks = malloc(capacity * sizeof(char *));
  tasks[0] = "Go to the gym";
  tasks[1] = "Study programming";

  while (1) {
    if (program_state == 0) {
      printf("1 (See tasks) - 2 (Create new task) - 3 (End program)\n");
      scanf("%d", &program_state);
    } else if (program_state == 1) {
      for (int i = 0; i < 2; i++) {
        printf("Task %d: %s\n", i + 1, tasks[i]);
      }

      printf("1 (See tasks) - 2 (Create new task) - 3 (End program)\n");
      scanf("%d", &program_state);
    } else if (program_state == 2) {
      char task[MAX_LIMIT];
      printf("Input task with maximum of 100 characters: ");
      fgets(task, MAX_LIMIT, stdin);
      printf("The new task: %s", task);

      printf("1 (See tasks) - 2 (Create new task) - 3 (End program)\n");
      scanf("%d", &program_state);
    } else if (program_state == 3) {
      printf("Shutting down program...");
      break;
    }
  }

  return 0;
}
