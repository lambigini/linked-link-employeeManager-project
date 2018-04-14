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
void deleteAtHead(List *);
void deleteAtTail(List *);
void inputDataFromFile(List *, char *);
void outputToFile(List *);
Node *find(List *, char [], int, Node **);

void menu() {

  printf("Welcome to Employee Manager App Using Linkedlist\n");
  printf("Please chose options as follow\n");
  printf("Enter 1: Insert At Head\n");
  printf("Enter 2: Insert At Tail\n");
  printf("Enter 3: Delete At Head\n");
  printf("Enter 4: Delete At Tail\n");
  printf("Enter 5: Open input file and write data to the Linked list\n");
  printf("Enter 6: Output to File \n");
  printf("Enter 7: Print list detail \n");
  printf("Enter 8: Find specific node in the linked list\n");
  printf("Enter 9: Delete specific node\n");

  printf("Enter 0: Exit \n");

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

void deleteAtHead(List * listPointer) {

	// check if the list is empty or not

	if (listPointer->numberOfNode == 0) {

		printf("List is empty, please input data first");
	}
	else if (listPointer->numberOfNode == 1) {
    // the list has only 1 node

		listPointer->head = listPointer->tail = NULL;

	}
	else {
    printf("Data to be deleted\n");
    printf("Name: %s\n", listPointer->head->name);
    printf("Age: %d\n", listPointer->head->age);
		listPointer->head = listPointer->head->next;
    printf("Success fully deleted data \n");
	}

  listPointer->numberOfNode--;

}
void deleteAtTail(List * listPointer) {

	// check if the list is empty or not

	if (listPointer->numberOfNode == 0) {

		printf("List is empty, please input data first");
	}
	else if (listPointer->numberOfNode == 1) {
    // the list has only 1 node

		listPointer->head = listPointer->tail = NULL;

	}
	else {
    // creat a new pointer type node to track the previous node of tail node
    Node *current = listPointer->head ;

    printf("Tail's data  to be deleted\n");
    printf("Name: %s\n", listPointer->tail->name);
    printf("Age: %d\n", listPointer->tail->age);

    // loop until find the previous of tail node
    while(current->next != listPointer->tail){
      //jump to the next node, until found the node previous to the tail then exit
      current = current->next;
    }
    // found the previous node,set the tail to previous node, and the tail pointer to null
    listPointer->tail = current;
    listPointer->tail->next = NULL;
    free(current);
	}

  listPointer->numberOfNode--;

}

void inputDataFromFile(List *listPointer, char *fileName){

  FILE *ifp;
  char *mode = "r";
  char username[12]; // 11 chatacters + 1 "/0" character
  int age;

  ifp = fopen(fileName, mode);

  if ( ifp == NULL) {
    fprintf(stderr, "Can't open input file %s\n",fileName );
    exit(1);
  }



  while (!feof(ifp)){

    if((fscanf(ifp,"%s %d",username, &age))!=2)
    /*
    Since our format is "%s %d", we expect it to read in 2 values
    Now, if we get 2 values, the loop continues. If we don't get 2 values,
    either because we are at the end of the file or some other problem occurred
    (e.g., it sees a letter when it is trying to read in a number with %d), then the loop will end.
      */
    break;
    insertAtTail(listPointer,username, age);

  }

    fclose(ifp);
}

void outputToFile(List *listPointer){

  FILE  *ofp;

  char outputFilename[] = "outList2.txt";

  ofp = fopen(outputFilename, "w");

  if (ofp == NULL){
    fprintf(stderr, "Can't write data to output file \n" );
    exit(1);
  }

  Node * current = listPointer->head;
  if (listPointer->numberOfNode == 0){

    printf("LIST IS EMPTY\n");
  } else {

    while(current != NULL){
      fprintf(ofp,"%s %d\n",current->name,current->age);
      current = current->next; // move to the next pointer
    }

  }
    free(current);
    fclose(ofp);
}
Node *find(List *listPointer, char findName[], int findAge, Node **previousPtr){

Node *current = listPointer->head;
*previousPtr = NULL;

while (current != NULL){

  if ((strcmp(current->name, findName) == 0) && (current->age == findAge)) {
    break;
  }

  *previousPtr = current;
  current = current->next;
}
  return current;
}

void deleteTarget(List *listPointer,char findName[], int findAge){
  Node *current = NULL, *prev = NULL;
  current = find(listPointer, findName, findAge, &prev);

  if (current == NULL){
    printf("list empty\n");
  }

  if (current == listPointer->head){
    printf("Target node deleted: name %s age %d \n", current->name, current->age);
  } else if ( current == listPointer->tail){
    deleteAtTail(listPointer);
    printf("Target node deleted: name %s age %d \n", current->name, current->age);
  } else {
    prev->next = current->next;
    free(current);
    listPointer->numberOfNode--;
    printf("Target node deleted: name %s age %d \n", current->name, current->age);
  }

}



int main() {

  char name[10];
  int age, quit = 0, userChoice;
  List employeeList;
  Node *currentNode = NULL, *previousNode = NULL;

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
      insertAtHead(&employeeList,name,age );
      break;

      case 2:
      printf("Insert at tail\n");
      printf("Please enter your age\n");
      scanf("%d",&age);
      printf(" Please enter your name\n");
      scanf("%s",name);

      insertAtTail(&employeeList,name,age );
      break;

      case 3:
      printf("Delete at Head operation\n");
      deleteAtHead(&employeeList);
      break;

      case 4:
      printf("Delete at Tail operation\n");
      deleteAtTail(&employeeList);
      break;

      case 5:
      inputDataFromFile(&employeeList,"employee.txt");
      break;
      case 6:
      outputToFile(&employeeList);
      break;

      case 7:
      printListDetail(&employeeList);
      break;

      case 8:
      printf("please enter name you want to find\n");
      scanf("%s",name);
      printf("please enter age you want to find\n");
      scanf("%d",&age);
      currentNode = find(&employeeList,name,age,&previousNode);

      if (currentNode == NULL){
        printf("Not found those data\n");
      } else {
        printf("Found data, address of the target node %p previous node %p \n", currentNode, previousNode);
      }
      break;

      case 9:
      printf("please enter name you want to delete\n");
      scanf("%s",name);
      printf("please enter age you want to delete\n");
      scanf("%d",&age);
      deleteTarget(&employeeList,name,age);
      break;


      case 0:
      quit = 1;
      break;

      default:
      printf("Please enter a valid choice\n");

    }
    printListDetail(&employeeList);

  }






  return 0;
}
