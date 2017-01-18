#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

typedef struct node{
      int data;
      int key;
      struct node *next;
} N, *NP;

N *head = NULL;
N *current = NULL;

void printList(void){
    N *ptr = head;
    printf("[ " );
    while (ptr != NULL ) {
        printf("(%d, %d) ",ptr->key,ptr->data );
        ptr = ptr->next;
    }
    printf(" ]\n");

}

void insertFirst(int key,int data){
     N *link = (NP)malloc(sizeof(N));
     link->key=key;
     link->data= data;

     link->next = head;
     // This is the first node
     head=link;
}

NP deleteFirst(){
   N *tempLink = head;

   head = head->next;

   return tempLink;
}

bool isEmpty(){
     return head == NULL;
}

int length(){
    int length=0;
    N *current;

    for (current = head;  current != NULL; current = current->next) {
        length++;
    }
    return length;
}

NP find(int key){
    N *current = head;

    if (head == NULL) {
      return NULL;
    }

    while (current->key != key) {
          if (current->next == NULL) {
            return NULL;
          }else{
            current = current->next;
          }
    }
    return current;
}

NP delete(int key){
   N *current = head;
   N *previus = NULL;

  if (head==NULL){
    return NULL;
  }

  while (current->key != key) {
        if (current->next == NULL) {
          return NULL;
        }else{
          previus = current;
          current = current->next;
        }
  }
  if (current == head) {
    head = head->next;
  }else{
    previus->next = current->next;
  }
  return current;
}

void sort(){
    int i,j,k,tempKey,tempData;

    N *current;
    N *next;

    int size = length();
    k = size;

    for ( i = 0; i < size-1; i++) {
      current = head;
      next = current->next;

      for ( j = 1; j < k;j++) {

          if (current->data > next->data) {
              tempData = current->data;
              current->data = next->data;
              next->data = tempData;

              tempKey = current->key;
              current->key = next->key;
              next->key = tempKey;
          }
          current = current->next;
          next = next->next;
      }

    }

}
void reverse(N **head_ref) {
    N *prev = NULL;
    N *current = *head_ref;
    N *next;

    while (current != NULL) {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;

    }
    *head_ref = prev;
}


int main(int argc, char const *argv[]) {
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56);

  printf("Original list\n");
  printList();

  while (!isEmpty()) {
        N *temp = deleteFirst();
        printf("Deleted value: \n" );
        printf("(%d, %d)\n",temp->key,temp->data );
  }
  printf("List after deletion\n" );
  printList();

  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56);

  N *foundLink = find(4);
  if (foundLink != NULL){
    printf("Element found!\n" );
    printf("(%d, %d) \n",foundLink->key,foundLink->data );
  }else{
    printf("Element not found!\n" );
  }

  delete(4);

  printf("Elements after the deletion: \n" );
  printList();

  foundLink = find(4);
  if (foundLink != NULL){
    printf("Element found!\n" );
    printf("(%d, %d) \n",foundLink->key,foundLink->data );
  }else{
    printf("Element not found!\n" );
  }

  sort();
  printf("List after sorting- \n" );
  printList();
  reverse(&head);
  printf("List after reversing- \n" );
  printList();
  return 0;
}
