#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char * data;
    struct node * next;
  };


struct list {
  
    struct node * head;

};

typedef struct list List;
typedef struct node node;


List make_list(void);
void insert(List list, char * data);
int delete_node(List list, int node_num);
void print_list(List list);

int main(void)
{
  List to_do_list;
  char input_str[200];
  char c;
  to_do_list = make_list();
  while(1){
    printf("Press 1 to add to to-do-list \n");
    printf("Press 2 to remove from to-do-list \n");
    printf("Press 3 to print to-do-list \n");
    printf("Press any other key to exit \n");

    scanf("%c",&c);
    getchar(); /*flush the \n scanf leaves to use fgets*/
    if(c == '1'){
      printf("Give item to add: \n");
      fgets(input_str,200,stdin);
      input_str[strlen(input_str) - 1] = '\0';
      insert(to_do_list,input_str);
    }
    else if(c == '2'){
      printf("Choose number to remove \n");
      fgets(input_str,200,stdin);
      if(delete_node(to_do_list, atoi(input_str)-1))
        printf("Done \n");
    }
    else if(c == '3'){
      print_list(to_do_list);
    }
    else{
      exit(0);
    }
  }
  return EXIT_SUCCESS;
}

List make_list(void){
    List list;
    node * head;
    head = malloc(sizeof(node));
    head->next = NULL;
    head->data = NULL;
    list.head = head;
    return list;
}
void insert(List list, char * data){
    node * new_node;
    char * data_str;
    data_str = malloc(sizeof(char)*200);
    strcpy_s(data_str,200, data);
    new_node = list.head;
    while(new_node->next != NULL)
      new_node = new_node->next;

    new_node->next = malloc(sizeof(node));
    new_node = new_node->next;
    new_node->data = data_str;
    new_node->next = NULL;
    return;
}
int delete_node(List list, int node_num){
    node * p_node;
    node * prev;
    int i=0;
    p_node = list.head->next;
    if(p_node == NULL) return 1;
    prev = list.head;
    while(i < node_num){
      if(p_node->next != NULL){ 
        prev = p_node;
        p_node = p_node->next;
      }
      else{printf("error lmao");return 1;}
      i++;
    }
    /* free node*/
    prev->next = p_node->next;
    free(p_node->data);
    free(p_node);
    return 0;
}

void print_list(List list){
    node * p_node;
    int i=0;
    p_node = list.head;
    while(p_node->next != NULL){
        i++;
        printf("%d. %s \n", i, (p_node->next)->data);
        p_node = p_node->next;
    } 
    return;
  
}
