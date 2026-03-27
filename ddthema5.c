#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void push(struct Stack *s) // προσθήκη στοιχείου στο stack
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    int value;
    printf("Enter the number you want to push: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = s->top;   // το νεο κομβος δειχνει στην παλια κορυφη
    s->top = newNode;         // ο νεος κομβος γινεται η κορυφη
    printf("Successfully pushed %d.\n", value);
}

void pop(struct Stack *s) // αφαίρεση στοιχείου από το stack
{
    if (s->top == NULL)
    {
        printf("Stack is empty! There are no elements to remove.\n");
        return;
    }
    struct Node *temp = s->top;
    printf("Successfully popped %d.\n", temp->data);
    s->top = s->top->next;  // η κορυφη μετακινειται στον επομενο κομβο
    free(temp);
}

void peek(struct Stack *s) // εμφάνιση του στοιχείου που βρίσκεται στην κορυφή του stack
{
    if (s->top == NULL)
    {
        printf("Stack is empty! There are no elements to view.\n");
    }
    else
    {
        printf("Top element: %d\n", s->top->data);
    }
}

void view(struct Stack *s) // εμφάνιση όλων των στοιχείων που βρίσκονται στο stack
{
    if (s->top == NULL)
    {
        printf("Stack is empty! There are no elements to display.\n");
        return;
    }
    printf("Stack contents (top to bottom):\n[");
    struct Node *current = s->top;
    printf("%d", current->data);
    current = current->next;
    while (current != NULL)
    {
        printf(",%d", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main()
{
    struct Stack s;
    s.top = NULL; 

    int choice = 1;
    while (choice != 5)
    {
        printf("\n=== LIFO Stack Menu ===\n");
        printf("1. Push   (add element)\n");
        printf("2. Pop    (remove element)\n");
        printf("3. Peek   (view top element)\n");
        printf("4. View   (view full stack)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            push(&s);
        }
        else if (choice == 2)
        {
            pop(&s);
        }
        else if (choice == 3)
        {
            peek(&s);
        }
        else if (choice == 4)
        {
            view(&s);
        }
        else if (choice == 5) printf("Goodbye!\n");
        else printf("Invalid option! Please enter a number between 1 and 5.\n");
    }
    return 0;
}