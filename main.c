/*

Data Structure Project using Linkedlist.
Empoyee manager app

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


void insertAtHead(List * listPointer, char name[],int age){

// creat a new node to insert to the linkedList
  Node *newNode = (Node *)malloc(sizeof(Node));

// check if new node created or not

if (newNode == NULL){
  printf("There is a error, CAN'T create new node\n");
  return;
} else {
  printf("Node created successfully\n");
  strcpy(newNode->name, name); // in C can't assign string value to array directly
                               // have to use strcpy
  newNode->age = age;
  newNode->next = NULL;   // pointer to the second node
}

// start insert new node to linkedList

if (listPointer->numberOfNode == 0){

  printf("List is Empty, head and tail poiter point to same data\n");
  listPointer->head = newNode;
  listPointer->tail = newNode;

} else {

  printf("List is Not Empty\n");
  newNode->next = listPointer->head;
  listPointer->head = newNode;
}

// increase the number of node in the list
listPointer->numberOfNode++;
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

   printf("head value %p\n",&(list->head) );
   printf("tail value %p\n",&(list->tail) );
   printf("number of nodes %d\n",list->numberOfNode);

}


int main() {

  char name[10];
  int age,quit = 0, userChoice;
  List moneyManagerList;


  while(quit != 1){

    printf("Please enter your choice\n");
    scanf("%d",&userChoice);

    switch (userChoice) {

      case 1:
      printf("Insert at head\n");
      printf("Please enter your age\n");
      scanf("%d",&age);
      printf(" Please enter your name\n");
      scanf("%s",name);

      insertAtHead(&moneyManagerList,name,age );
      break;
      default:
      printf("Please enter a valid choice\n");

    }

    print_Struct_Element(&moneyManagerList);

    printf("Enter 1 if you want to quit, otherwise enter \"0\" \n");
    scanf("%d",&quit);
  }






  return 0;
}
