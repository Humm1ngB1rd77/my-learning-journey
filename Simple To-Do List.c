#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10 //maximum number of tasks allowed
#define MAX_LENGTH 100

void addTask(char tasks[][MAX_LENGTH], int *count);
void viewTasks(char tasks[][MAX_LENGTH], int count);
void deleteTask(char tasks[][MAX_LENGTH], int *count);

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- To-Do List ---\n");
        printf("1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1: addTask(tasks, &count); break;
            case 2: viewTasks(tasks, count); break;
            case 3: deleteTask(tasks, &count); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void addTask(char tasks[][MAX_LENGTH], int *count) {
    if (*count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter task: ");
    fgets(tasks[*count], MAX_LENGTH, stdin);
    tasks[*count][strcspn(tasks[*count], "\n")] = '\0'; // Remove newline
    (*count)++;
    printf("Task added successfully!\n");
}

void viewTasks(char tasks[][MAX_LENGTH], int count) {
    if (count == 0) {
        printf("No tasks available.\n");
        return;
    }
    printf("\nYour Tasks:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void deleteTask(char tasks[][MAX_LENGTH], int *count) {
    if (*count == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    int taskNumber;
    printf("Enter task number to delete: ");
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > *count) {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = taskNumber - 1; i < (*count) - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    (*count)--;
    printf("Task deleted successfully!\n");
}

