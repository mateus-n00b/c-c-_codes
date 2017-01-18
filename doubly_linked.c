#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

typedef struct node {
      int data;
      int key;

      struct node *next;
      struct node *prev;
}N;
N *head = NULL;
N *last = NULL;
N *current = NULL;

bool isEmpty(){
    return head == NULL;
}

int length(){
  int length = 0;
  N *current;

  for (current = head;current != NULL; current = current->next){
      length++;
  }

  return length;
}

void displayForward() {
    N *ptr = head;

    printf("\n[ " );
    while (ptr != NULL) {
        printf("(%d, %d) ",ptr->key,ptr->data );
        ptr = ptr->next;
    }
    printf(" ]\n" );
}

void displayBackward() {
  N *ptr = last;

  printf("\n[ ");
  while (ptr != NULL) {
        printf("(%d,%d) ",ptr->key,ptr->data );
        ptr = ptr->prev;
  }
  printf(" ]\n" );
}

void insertFirst(int key,int data) {
      N *link = (N*)malloc(sizeof(N));
      link->key = key;
      link->data = data;

      if (isEmpty())
      {
        last = link;
      }
      else
      {
        head->prev = link;
      }

      link->next = head;
      head = link;
}

void  insertLast(int key,int data) {
      N *link = (N*)malloc(sizeof(N));
      link->key = key;
      link->data = data;

      if (isEmpty()) {
          last = link;
      }else
      {
        last->next = link;
        link->prev = last;
      }
      last = link;
}

N* deleteFirst() {
    N *temp = head;
    if (head->next == NULL) {
        last = NULL;
    }
    else{
        // O proximo no apontava para head, que agora sera
        // deletado, por isso next->prev, que aponta para head, recebe null;
        // (Head sera apagado)
        head->next->prev = NULL;
    }
    head = head->next;
    return temp;
}

N* deleteLast(){
   N *temp = last;
   if (head->next == NULL) {
      head = NULL;
   }else{
     last->prev->next = NULL;
   }
   last = last->prev;
   return temp;
}

N* delete(int key){
   N *current = head;
   N *previous = NULL;

   if (head == NULL) {
      return NULL;
   }

   while (current->key != key) {
         if (current->next == NULL) {
             return NULL;
         }else{
            previous = current;

            current = current->next;
         }
   }

   if (current == head) {
       head = head->next;

   }else{
        current->prev->next = current->next;

   }

   if (current == last) {
       last = current->prev;
   }else{
      current->next->prev = current->prev;
   }

   return current;
}

bool insertAfter(int key, int newKey, int data){
    N *current = head;

    if (head == NULL) {
        return false;
    }

    while (current->key != key) {
          if (current->next == NULL) {
            return false;
          }else{
            current = current->next;
          }
    }

    N *newLink = (N*)malloc(sizeof(N));
    newLink->key = key;
    newLink->data = data;

    if (current == last) {
        newLink->next = NULL;
        last = newLink;
    }else{
        newLink->next = current->next;
        current->next->prev = newLink;

    }
    newLink->prev = current;
    current->next = newLink;

    return true;
}

int main(int argc, char const *argv[]) {
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56);

  printf("First to last \n");
  displayForward();

  printf("\nLast to first \n");
  displayBackward();

  printf("\nFirst node deleted!\n" );
  deleteFirst();
  displayForward();

  printf("\nLast node deleted!\n" );
  deleteLast();
  displayForward();

  printf("Inserting after the key 4\n" );
  insertAfter(4,7,13);
  displayForward();

  printf("\nDeleting key 4\n" );
  delete(4);
  displayForward();
  return 0;
}
