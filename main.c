/*

Data Structure Project using Linkedlist.
Money manager app
Ask user for the amount of money he/she is saving each month.
User have a choice for add,delete, find, print.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
  char name[10] ;
  int age;
  struct Node *next;
}Node;

typedef struct{
  struct Node *head;
  struct Node *tail;
  int numberOfNode;
} List;

// function prototypes

void initList(List *);
void print_Struct_Element(List *);
void insertAtHead(List *, char [],int);

void insertAtHead(List *listPtr, char name[], int age){
  Node *newNodePtr = (Node*)malloc(sizeof(Node));
  if (newNodePtr == NULL){
    printf("Unable to allocate new node\n");
    return;
  }
  strcpy(newNodePtr->name, name);
  newNodePtr->age = age;
  newNodePtr->next = NULL;


  if (listPtr->numberOfNode == 0){
    // this is the case when the list is empty
    listPtr->head = newNodePtr;
    listPtr->tail = newNodePtr;
  }
  else{
    // this is the case when the list is not empty
    newNodePtr->next = listPtr->head;
    listPtr->head = newNodePtr;
  }
  listPtr->numberOfNode++;
}

void initList(List * listPointer) {
  listPointer->head = NULL;
  listPointer->tail = NULL;
  listPointer->numberOfNode = 0;
}

void print_Struct_Element(List *list) {
   printf("String name: %s\n",list->head->name);
   printf("Age data: %d\n",list->head->age);

   printf("head address %p\n",list->head );
   printf("tail address %p\n",list->tail );
   printf("head value %p\n",&list->head );
   printf("tail value %p\n",&list->tail );
}


int main() {

  char name[10];
  int age, count;
  // printf("Please enter your name and age  \n ");
  //  sscanf("harrison 30", "%s %d",name, &age );
  printf("Please enter your age ");
    //fgets(age, 5, stdin);

   scanf("%d\n",&age);

  printf(" Please enter your name\n");
   fgets(name,10, stdin);
    //scanf("%s\n",name);

  List moneyManagerList;
  insertAtHead(&moneyManagerList,name,age );
  //moneyManagerList.head->name = strcpy(moneyManagerList.head->name, name );
  //printf("head string name %s\n",moneyManagerList.head->name );
  print_Struct_Element(&moneyManagerList);

  return 0;
}
