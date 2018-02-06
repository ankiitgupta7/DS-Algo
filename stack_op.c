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
		printf("\n\nEnter 1,2 & 3 for push, pop and top operation on stack\nOtherwise, Enter -1 to exit\n\n0");
		scanf("%d",&key);
		if(key==1)
		{
			printf("\nEnter the element to be pushed: ");
			scanf("%d",&num);
			push(num);
			printf("\nThe stack after recent push is :\n");
			display(head);
		}
		else if(key==2)
		{
			pop();
			printf("\nThe stack after recent pop is :\n");
			display(head);
		}
		else if(key==3)
			printf("\nThe top of stack presently is %d\n",head->data);
	}
	while(key==1 || key==2 || key==3);
}

void push(int num)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=num;
	temp->next=head;
	head=temp;
}

void pop()
{
	if(head==NULL)
		printf("\nThis stack is empty, you cannot pop\n");
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
