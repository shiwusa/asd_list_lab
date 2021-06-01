#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    char data;
    struct list* next;
} l_list;

l_list * l_list_init(char item) {
  l_list *l_p ;
  l_p = malloc(sizeof(struct list));
  *l_p = (l_list){ 
    .data = item,
    .next = NULL
  };
  return l_p;
};

l_list * add_list(l_list *l_p, char item){
  struct list *node_p ;
  node_p = malloc(sizeof(struct list));
  node_p->data = item;
  node_p->next = l_p;
  return node_p;
}

void printList(l_list * head) {
    l_list * current = head;
    while (current != NULL) {
        printf("data = %c, adress = %d, next adress = %d\n", current->data,(int)current, (int)current->next);
        current = current->next;
    }
}

void sort(l_list *start)
{
    l_list *tmp;
    l_list *a;
    char t=0;
    int flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if((tmp->data)>(a->data))
            {
                t=tmp->data;
                tmp->data=a->data;
                a->data=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
}
void deleteList(l_list *head) {
    l_list* prev = NULL;
    while (head->next) {
        prev = head;
        head = head->next;
        free(prev);
    }
    free(head);
}

int main(void) {
  int n;
  struct list* list_p;
  char alph[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  printf ("Enter n:");
  scanf ("%i", &n);
  list_p = l_list_init('?');
  for(int i = 0; i < n-1; i++){
    if(i >= 26) list_p = add_list(list_p, '!');
    else list_p = add_list(list_p, alph[i]);
  }

  printf("\nUnsorted list:\n");
  printList(list_p);
  printf("\nSorted list:\n");
  sort(list_p);
  printList(list_p);
  deleteList(list_p);
  return 0;
}
