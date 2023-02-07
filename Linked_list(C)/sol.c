#include <stdio.h>
#include <stdlib.h>
	// Define the structure for a node in the linked list
struct Node {
  int data;
  struct Node* next;
};
// Function to create a new node with a given data value
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  struct Node* temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to insert a new node at the specified index
void insertbyIndex(struct Node** head, int data, int indx) {
  struct Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  struct Node* current = *head;
  struct Node* prev = NULL;
  if(indx ==0){
      if(current->next==NULL){//only one node
          newNode->next = *head;
          *head = newNode;
          return;
      }
        struct Node* temp = current->next;
        newNode->next = temp;
        current->next = newNode;
        return;

  }
  while(indx){
        if(current == NULL){
            prev->next = newNode;//add at the end
            return;
        }
        prev = current;
        current = current->next;
        indx--;
    }
  prev->next = newNode;
  newNode->next = current;
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}

// Function to delete at the front of the Linked list
void deleteFront(struct Node** head) {
  struct Node* next_head = NULL;
  if (*head != NULL) {
      next_head = (*head)->next;
      (*head)->next=NULL;
      free(*head);
      *head = next_head;
  }
}

// Function to delete at the index of the Linked list
void removeByIdx(struct Node** head, int i) {
    struct Node* current = (*head);
    struct Node* prev =NULL;
    
    //only one node at the linked list or remove the first element
    if(current->next == NULL || i==0){
        deleteFront(head);
        return;
    }
    while(i){//move to the node to be removed
        if(current == NULL){
            printf("invalid index\n");
            return;
        }
        prev = current;
        current = current->next;
        i--;
    }
    prev->next = current->next;
    current->next = NULL;
    free(current);
}

// Function to delete by the value of the Linked list
void removeByVal(struct Node** head, int val) {
    struct Node* current = (*head);
    struct Node* prev =NULL;
    int flag =0;//flag to know if a target is found
    
    if(current->next == NULL){//only one node at the linked list
        deleteFront(head);
        return;
    }
    if(current->data == val){//the head is the target, no previous can be assigned
        deleteFront(head);
        return;
    }
    while(current!=NULL){//move to the node to be removed
        if(current->data ==val){
            flag=1;
            break;
        }
        prev = current;
        current = current->next;
        }
    if(flag==1){
        prev->next = current->next;
        current->next = NULL;
        free(current);
    }else{
        printf("target not found!\n");
    }

}



// Driver function to test the linked list implementation
int main() {
  struct Node* head = NULL;
  insertAtEnd(&head, 1);
  insertAtEnd(&head, 2);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);
  printf("Linked list: ");
  printList(head);
  printf("Linked list (after delete front): ");
  deleteFront(&head);
  printList(head);
  printf("Linked list (after delete index 1): ");
  removeByIdx(&head, 1);
  printList(head);
  printf("Linked list (after delete by a value): ");
  removeByVal(&head, 4);
  printList(head);
  printf("Linked list (insert by index): ");
  insertbyIndex(&head, 7,0);
  printList(head);
  
    printf("Linked list (insert by index): ");
      insertbyIndex(&head, 8,0);
      printList(head);
    printf("Linked list (insert by index): ");
      insertbyIndex(&head, 9,0);
      printList(head);
      
      printf("Linked list (insert by index): ");
      insertbyIndex(&head, 3,4);
      printList(head);
  return 0;
}
