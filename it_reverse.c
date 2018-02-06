#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}
  node;

node *create();
void display(node *);
node *ireverse(node *);

void main()
{
node *list=create();
printf("\nThe original list is as following:\n");
  display(list);
printf("\nThe reversed list is:\n");
  list=ireverse(list);
display(list);
}

node *create()
{
  int n,i;
  node *head=NULL,*p=NULL;
  printf("\nHow many numbers in the list?\n");
  scanf("%d",&n);
   for(i=1;i<=n;i++)
    {
      node *temp=(node *)malloc(sizeof(node));
      printf("Please enter number %d:\n",i);
      scanf("%d",&(temp->data));
      temp->next=NULL;
  
      if(head==NULL)
	head=temp;
      else
	{
	 p=head;
        while(p->next!=NULL)
	   p=p->next;
        p->next=temp;
	}
    }
   return head;
}

void display(node *list)
{
  while(list!= NULL)
    {
    printf("%d ",list->data);
    list=list->next;
    }
}

node *ireverse(node *list)
{
    node *temp,*current=list,*prev=NULL;
    while(current!=NULL)
    {
       temp=current->next;
       current->next=prev;
       prev=current;
       current=temp;
    }
    return prev;
}







