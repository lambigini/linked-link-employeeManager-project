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

void menu();
void initList(List *);
void insertAtHead(List *, char [],int);
void insertAtTail(List *, char [],int);
void printListDetail(List *);

void menu() {
  printf("Welcome to Employee Manager App Using Linkedlist\n");
  printf("Please chose options as follow\n");
  printf("Enter 1: Insert At Head\n");
  printf("Enter 2: Insert At Tail\n");
}

void initList(List * listPointer) {
  listPointer->head = NULL;
  listPointer->tail = NULL;
  listPointer->numberOfNode = 0;
}

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

void insertAtTail(List *listPointer, char name[],int age){

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

    listPointer->tail->next = newNode;
    listPointer->tail = newNode;
  }

  // increase the number of node in the list
  listPointer->numberOfNode++;
}

void printListDetail(List * listPointer){
  Node * current = listPointer->head;
  if (listPointer->numberOfNode == 0){

    printf("LIST IS EMPTY\n");
  } else {
    printf("HEAD ADDRESS %p\n",listPointer->head);
    while(current != NULL){

      printf("[%s - %d | %p] ",current->name,current->age, current);

      current = current->next; // move to the next pointer
    }
    printf("\nTAIL ADDRESS %p\n",listPointer->tail);
    printf("\n");
  }
}

int main() {

  char name[10];
  int age,quit = 0, userChoice;
  List moneyManagerList;


  while(quit != 1){
    menu();
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


      case 2:
      printf("Insert at tail\n");
      printf("Please enter your age\n");
      scanf("%d",&age);
      printf(" Please enter your name\n");
      scanf("%s",name);

      insertAtTail(&moneyManagerList,name,age );
      break;

      default:
      printf("Please enter a valid choice\n");

    }
    printListDetail(&moneyManagerList);


    printf("Enter 0 to Continue, to Quit enter \"1\" \n");
    scanf("%d",&quit);
  }






  return 0;
}
