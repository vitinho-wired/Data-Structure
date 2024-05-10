#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
  int data;
  struct node* next;
}Node;

Node* linked_list_tail(Node*,int);
Node* linked_list_add_head(Node*,int);
Node* append_linked_list(Node*,Node*);
void linked_list_display(Node*);
bool check_member(Node*,int);
void replace_match(Node*,int,int);
int count_matches(Node*,int);
Node* delete_match(Node*,int,int*);
void delete_duplicates(Node*);
void delete_linked_list(Node*);
void sort_list(Node*);
Node* insert_after(Node*,int,int);
Node* search(Node*,int);

int main()
{
  Node* head = NULL;
  Node* head_list2 = NULL;
  head = linked_list_add_head(head,1);
  head = linked_list_add_head(head,1);
  head = linked_list_add_head(head,1);
  head = linked_list_add_head(head,0);
  head = linked_list_tail(head,10);
  head = linked_list_tail(head,12);
  linked_list_display(head);
  head_list2 = linked_list_add_head(head_list2,199);
  linked_list_display(head_list2);
  delete_linked_list(head_list2);

  head = insert_after(head,17,10);
  linked_list_display(head);
  printf("member 10: %d\n",check_member(head,10));
  replace_match(head,10,20);
  linked_list_display(head);
  int res = count_matches(head,1);
  printf("%d\n",res);
  delete_duplicates(head);
  linked_list_display(head);
  sort_list(head);
  linked_list_display(head);
  return 0;
}


Node* linked_list_tail(Node* node,int data){
  Node* new_node = calloc(0,sizeof(Node));
  if(new_node == NULL){
    return NULL;
  }
  new_node->data = data;
  if(node == NULL) return new_node;
  else{
    Node* current = node;
    while(current->next != NULL) current = current->next;
    current->next = new_node;
    return node;
  }
}

void linked_list_display(Node* node)
{
  Node* current = node;
  while(current != NULL){
    printf("%d ",current->data);
    current = current->next;
  }
  printf("\n");
}

Node* linked_list_add_head(Node* node, int data){
  Node* new_node = calloc(0,sizeof(Node));
  if(new_node == NULL) return NULL;
  new_node->data = data;
  if(node == NULL) return new_node;
  else{
    Node* current = node;
    new_node->next = node;
    return new_node;
  }


}


Node* append_linked_list(Node* linkedl1,Node* linkedl2){
  if(linkedl1 == NULL) return linkedl2;
  Node* current = linkedl1;
  while(current->next != NULL) current = current->next;
  current->next = linkedl2;
  return linkedl1;
}



bool check_member(Node* node,int find_value){
  if(node == NULL) return false;
  else if(node->data == find_value) return true;
  else return check_member(node->next,find_value);
}

int count_matches(Node* node, int find_value)
{
  if(node == NULL) return 0;
  else if(node->data == find_value)
      return 1 + count_matches(node->next,find_value);
  else return count_matches(node->next,find_value);
}


void replace_match(Node* node, int find_value, int replace_value)
{

  if(node != NULL){
    if(node->data == find_value) node->data = replace_value;
    replace_match(node->next,find_value,replace_value); }
}

Node* delete_match(Node* head,int delete_value,int* num_deleted){
  if(head == NULL) return NULL;
  Node* current,*temp,*new_head;
  current = head;
  *num_deleted = 0;
  new_head = current;
  while(current->next != NULL){
    if(current->next->data == delete_value)
    {
      temp = current->next;
      current->next = current->next->next;
      free(temp);
      *num_deleted += 1;
    }
    else current = current->next;
  }
  return new_head;
}

void delete_duplicates(Node* head)
{
	if(head == NULL) return;
	if(head->next == NULL) return;
	Node* current1,*current2,*duplicate;
	current1 = head;
	while(current1 != NULL && current1->next != NULL)
	{
		current2 = current1;
		while(current2->next != NULL)
		{
			if(current1->data == current2->next->data)
			{
				duplicate = current2->next;
				current2->next = current2->next->next;
				free(duplicate);
			}
			else current2 = current2->next;
		}
		current1 = current1->next;
	}
}

void sort_list(Node* head){
  bool swapped = false;
  do{
    swapped = false;
    Node* current = head;
    Node* prev = NULL;
    while(current->next != NULL){
      prev = head;
      current = current->next;
      if(current != NULL){
        if(current->data < prev->data){
          int temp;
          temp = prev->data;
          prev->data = current->data;
          current->data = temp;
          swapped = true;
        }
      }

    }

  }while(swapped);
}

Node* insert_after(Node* head,int new_value,int after_value){
  Node* new_node = calloc(0,sizeof(Node));
  new_node->data = new_value;
  if(head == NULL) return new_node;
  else{
    Node* current = head;
    while(current->next != NULL){
      if(current->data == after_value){
        new_node->next = current->next;
        current->next =new_node;
        return head;
      }else current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
  }
}

void delete_linked_list(Node* head)
{
  if(head != NULL){
    delete_linked_list(head->next);
    free(head);
  }
  return;
}

Node* search(Node* head,int value){
  Node* new_head = head;
  while(new_head != NULL){
    if(new_head->data == value) return new_head;
    new_head = new_head->next;
  }
  return NULL;
}



