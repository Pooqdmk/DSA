/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each command
typedef struct Command {
    char* action;
    char* response;
    struct Command* next;
} Command;

// Function to create a new command node
Command* createCommand(char* action, char* response) {
    Command* newCommand = (Command*)malloc(sizeof(Command));
    if (newCommand == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newCommand->action = strdup(action);
    newCommand->response = strdup(response);
    newCommand->next = NULL;
    return newCommand;
}

// Function to add a new command to the end of the linked list
void addCommand(Command** head, char* action, char* response) {
    Command* newCommand = createCommand(action, response);
    if (*head == NULL) {
        *head = newCommand;
    } else {
        Command* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCommand;
    }
}

// Function to search for a command in the linked list and return its response
char* getResponse(Command* head, char* action) {
    Command* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->action, action) == 0) {
            return temp->response;
        }
        temp = temp->next;
    }
    return "Command not found.";
}

// Function to free the memory allocated for the linked list
void freeCommands(Command* head) {
    Command* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp->action);
        free(temp->response);
        free(temp);
    }
}

int main() {
    Command* head = NULL;

    // Adding commands to the voice assistant
    addCommand(&head, "hello", "Hello! How can I assist you?");
    addCommand(&head, "time", "The current time is 12:00 PM.");

    // Simulating user input and getting responses from the voice assistant
    char userInput[100];
    printf("You: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = 0; // Removing newline character
    printf("Voice Assistant: %s\n", getResponse(head, userInput));

    // Freeing memory
    freeCommands(head);

    return 0;
}