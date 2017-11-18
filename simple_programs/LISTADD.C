//Sum of linked lists!!
#include<stdio.h>

typedef struct node
{
int data;
struct node *next;
}Node;


Node* insertList(Node *head, int xEle)
{
 Node *newNode,*tmp;
 newNode = (Node*) malloc(sizeof(struct node));
 newNode->next =NULL;
 newNode->data=xEle;
 if(head->next == NULL)
  {
   head->next = newNode;
  }
  else
  {
    tmp = head->next;
    while(tmp->next != NULL)
    {
      tmp = tmp->next;
    }
    tmp->next = newNode;
  }
  return head;
}

void display(Node *head)
{
 Node *tmp = head->next;
 printf("\n\n");
 while(tmp != NULL)
 {
  printf(" %d " ,tmp->data);
  tmp =tmp->next;
 }
}

Node* addList(Node *head1, Node *head2)
{
  Node *head, *tmp1, *tmp2;
  int x, carry = 0;
  head = (Node*) malloc(sizeof(Node));
  head->next = NULL;
  if(head1 == NULL && head2 == NULL )
  {
    return head;
  }
  else
  {
   tmp1 = head1->next;
   tmp2 = head2->next;
   while(tmp1 != NULL)
   {
     x = tmp1->data + tmp2->data + carry;
     if(x > 9)
      carry =1;
     else
      carry = 0;
     head = insertList(head,x%10);
     tmp1 = tmp1->next;
     tmp2 = tmp2->next;
   }
  }
  return head;
}

main()
{
Node *head1;
Node *head2,*head3;
head1 = (Node*) malloc(sizeof(Node));
head1->next = NULL;
head2 = (Node*) malloc(sizeof(Node));
head2->next = NULL;
head1 = insertList(head1,3);
head1 = insertList(head1,1);
head1 = insertList(head1,5);
display(head1);
head2 = insertList(head2,9);
head2 = insertList(head2,1);
head2 = insertList(head2,2);
display(head2);

head3 = addList(head1,head2);
display(head3);

getch();
return 0;
}