/*
 ============================================================================
 Name        : Prompt.c
 Author      : 
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int number;
	struct node *next;
}Node;

Node *head = NULL;

void put(int n){
	
	Node *newNo = (Node*) malloc(sizeof(Node));
	Node *last = head;
	
	newNo->number = n;
	newNo->next = NULL;
	
    if (head == NULL) {
        head = newNo;
		return; 
    }
    
    while(last->next != NULL){
		last = last->next; 	
	}
    last->next = newNo;  
}


void list(Node *no){
	
	if(no == NULL){
		printf("List Empty\n");
	}
	else{
		while(no != NULL){
			printf("%d ", no->number);
			no = no->next;
		}
			
	} 
}

void get(Node *no, int pos){
	
	Node *current = no;
	Node *auxCont = no;

	int cont = 0;
	while(auxCont != NULL){
		cont++;
		auxCont = auxCont->next;
	}
	 
	if((current == NULL) || (pos < 1) || (pos > cont)){
		printf("Position not exist!\n");
	}
	
	int aux = 1;	
	while(current != NULL){
		if(aux == pos){
			printf("%d ", current->number);
		}
		aux++;
		current = current->next;
	}
}

void first(Node *no){
	printf("%d ", no->number);
}

void last(Node *no){
	
	Node *current = no;
	
	while(current->next != NULL){
		current = current->next;
	}
	printf("%d ", current->number);

}

void clear(Node **no){
	*no = NULL;
}

void removeElement(Node **no, int pos){
	
	Node *previous = *no;

	if(previous == NULL){
         printf("Position not exist!\n");
	}
	
	if(pos == 1){
		*no = previous->next;
		printf("%d \n", previous->number);
		free(previous);
		return;
	}
	int i;
	for(i = 1; previous != NULL && i < pos-1; i++){
		previous = previous->next;
	}
	
	if (previous == NULL || previous->next == NULL) {
         printf("Position not exist!\n");
         return;
    }
    
    Node *next = previous->next->next;
	printf("%d \n", previous->next->number);    
    free(previous->next);  
    previous->next = next;  
	
}

void print_entry(char *entry) {
	printf("\nYou entered: %s\n", entry);
}

int main(int argc, char *argv[]) {

	char input[201];
	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}
		
		if (strncmp(input, "put", 3) == 0) {
		    put((int) input[4] - '0');
		}
		
		if (strncmp(input, "list", 4) == 0) {
			list(head);
		}
		
		if (strncmp(input, "get", 3) == 0) {
			get(head, (int) input[4] - '0');
		}
		
		if (strncmp(input, "first", 5) == 0) {
			first(head);
		}
		
		if (strncmp(input, "last", 4) == 0) {
			last(head);
		}
		
		if (strncmp(input, "clear", 5) == 0) {
			clear(&head);
		}
		
		if (strncmp(input, "remove", 6) == 0) {
			removeElement(&head, (int) input[7] - '0');
			list(head);
		}		

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		print_entry(input);
	}

	return EXIT_SUCCESS;
}
