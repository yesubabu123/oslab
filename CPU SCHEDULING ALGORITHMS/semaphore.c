#include<stdio.h>
#include<stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0; // Shared variables

// Function prototypes
void producer();
void consumer();
int wait(int);
int signal(int);

int main() {
    int n;

    printf("\n1. Producer\n2. Consumer\n3. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n) {  // Fixed the switch statement
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full!\n");
                break;
            case 2:#include<stdio.h>
#include<stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0; // Shared variables

// Function prototypes
void producer();
void consumer();
int wait(int);
int signal(int);

int main() {
    int n;

    printf("\n1. Producer\n2. Consumer\n3. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n) {  // Fixed the switch statement
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full!\n");
                break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex); // Decrease mutex
    full = signal(full); // Increase full
    empty = wait(empty); // Decrease empty
    x++; // Increase produced item count
    printf("\nProducer produces item %d\n", x);
    mutex = signal(mutex); // Release mutex
}

void consumer() {
    mutex = wait(mutex); // Decrease mutex
    full = wait(full);   // Decrease full
    empty = signal(empty); // Increase empty
    printf("\nConsumer consumes item %d\n", x);
    x--; // Decrease consumed item count
    mutex = signal(mutex); // Release mutex
}
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex); // Decrease mutex
    full = signal(full); // Increase full
    empty = wait(empty); // Decrease empty
    x++; // Increase produced item count
    printf("\nProducer produces item %d\n", x);
    mutex = signal(mutex); // Release mutex
}

void consumer() {
    mutex = wait(mutex); // Decrease mutex
    full = wait(full);   // Decrease full
    empty = signal(empty); // Increase empty
    printf("\nConsumer consumes item %d\n", x);
    x--; // Decrease consumed item count
    mutex = signal(mutex); // Release mutex
}