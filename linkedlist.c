#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void printList(Node* head) {
    if(head == NULL) {
        printf("Your list is empty.");
        return;
    }
    int idx = 0;
    Node* curr = head;
    while(curr != NULL) {
        printf("->%d", curr->value);
        int value = curr->value;
        curr = curr->next;
        idx++;
    }
    printf("\n");
}

void addToHead(Node** head, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

void addToTail(Node* head, int value) {
    Node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    curr->next = newNode;
}

void addAtIndex(Node* head, int value, int index) {
    int i = 0;
    Node* curr = head;
    while(i+1 != index) {
        curr = curr->next;
        i++;
    }
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;

    Node* currNext = curr->next;
    curr->next = newNode;
    newNode->next = currNext;
}

void deleteAtIndex(Node* head, int index) {
    int i = 0;
    Node* curr = head;
    while(i+1 != index) {
        curr = curr->next;
        i++;
    }

    Node* currNext = curr->next;
    curr->next = curr->next->next;
    free(currNext);
}

void freeLinkedList(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        Node* nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
}

int main(int argc, char *argv[]) {
    Node* list = malloc(sizeof(Node));
    list->value=1;
    Node* newNode = malloc(sizeof(Node));
    list->next = newNode;

    addToTail(list, 123);
    addToHead(&list, 222);
    addToTail(list, 111);
    addToHead(&list, 444);
    addAtIndex(list, 8008, 3);
    deleteAtIndex(list, 2);

    printList(list);
    freeLinkedList(list);
    return 0;
}
