#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

typedef struct node {
        int key;
        int data;

        struct node *next;
} N ;

N *head = NULL;
N *current = NULL;

bool isEmpty(){
  return head == NULL;
}

int length(){
    int length = 0;

    if (head==NULL)
        return 0;

    current = head->next;
    while (current != NULL) {
          length++;
          current = current->next;
    }
    return length;
}

void insertFirst(int key,int data) {
     N *link = (N*)malloc(sizeof(N));
     link->key = key;
     link->data = data;

     if (isEmpty()) {
       head = link;
       head->next = head;
     }else{
       link->next = head;
       head = link;
     }
}

N *deleteFirst(){
    N *templink = head;
    if (head->next == NULL) {
        head = NULL;
        return NULL;
    }
    head = head->next;
    return templink;
}

void printList() {
    N *ptr = head;
    printf("[ " );
    if (head != NULL) {
      while (ptr->next != ptr) {
            printf("(%d, %d) ",ptr->key,ptr->data );
            ptr = ptr->next;
      }
    }
    printf(" ]\n" );
}

int main(int argc, char const *argv[]) {
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56);

  printf("Original list: \n" );
  printList();

  N *temp = deleteFirst();
  printf("Removed key = %d\n",temp->key );
  // while (!isEmpty()) {
  //       N *temp = deleteFirst();
  //       printf("Deleted value: \n" );
  //       printf("(%d, %d) ",temp->key,temp->data );
  // }

  printf("\nList after deleting all items\n" );
  printList();
  return 0;
}
