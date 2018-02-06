#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head=NULL;

void display(node *);
void push(int);
void pop();

void main()
{
	int key,num;
	do
	{
		printf("\n\nEnter 1,2 & 3 for push, pop and top operation on queue\nOtherwise, Enter -1 to exit\n\n");
		scanf("%d",&key);
		if(key==1)
		{
			printf("\nEnter the element to be pushed: ");
			scanf("%d",&num);
			push(num);
			printf("\nThe queue after recent push is :\n");
			display(head);
		}
		else if(key==2)
		{
			pop();
			printf("\nThe queue after recent pop is :\n");
			display(head);
		}
		else if(key==3)
			printf("\nThe top of queue presently is %d\n",head->data);
	}
	while(key==1 || key==2 || key==3);
}

void push(int num)
{
	node *p=head,*temp=(node *)malloc(sizeof(node));
	temp->data=num;
	temp->next=NULL;
	if(head==NULL)
	   head=temp;
	else
	{
	while(p->next!=NULL)
	    p=p->next;
	p->next=temp;
  }
}

void pop()
	{
		if(head==NULL)
			printf("\nThis queue is empty, you cannot pop\n");
		else
			head=head->next;
	}

void display(node *list)
	{
	  while(list!= NULL)
	    {
	    printf("%d ",list->data);
	    list=list->next;
	    }
	}
