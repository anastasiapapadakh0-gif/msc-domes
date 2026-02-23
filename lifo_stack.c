#include <stdio.h>
#define max 10

struct stack 
{
    int data[max];
    int top;
};

void push(struct stack *s)
{
    if (s->top == max-1)
    {
        printf("Stack is full! Please remove an element before adding a new one.\n");
    }
    else
    {
        int value;
        printf("Enter the number you want to push onto the stack: ");
        scanf("%d", &value);
        s->top++;
        s->data[s->top] = value;
        printf("Successfully pushed %d onto the stack.\n", value);
    }
}

void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty! There are no elements to remove.\n");
    }
    else
    {
        printf("Successfully popped %d from the stack.\n", s->data[s->top]);
        s->top--;
    }
}

void peek(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty! There are no elements to view.\n");
    }
    else
    {
        printf("Top element: %d\n", s->data[s->top]);
    }
}

void view(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty! There are no elements to display.\n");
    }
    else
    {
        printf("Current stack contents (top to bottom):\n");
        printf("[");
        printf("%d", s->data[0]);
        for (int i = 1; i <= s->top; i++)
        {
            printf(", %d", s->data[i]);
        }
        for (int i = s->top+1; i < max; i++)
        {
            printf(", -");
        }
        printf("]\n");
        printf("(%d/%d slots used)\n", s->top+1, max);
    }
}

int main()
{
    struct stack s;
    s.top = -1;

    int choice = 1;
    while (choice != 5)
    {
        printf("\n=== LIFO Stack Menu ===\n");
        printf("1. Push  (add element)\n");
        printf("2. Pop   (remove element)\n");
        printf("3. Peek  (view top element)\n");
        printf("4. View  (view full stack)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            printf("Goodbye!\n");
            return 0;
        }
        else if (choice == 4)
        {
            view(&s);
        }
        else if (choice == 3)
        {
            peek(&s);
        }
        else if (choice == 2)
        {
            pop(&s);
        }
        else if (choice == 1)
        {
            push(&s);
        }
        else
        {
            printf("Invalid option! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}