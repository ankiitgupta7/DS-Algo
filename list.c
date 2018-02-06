#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *link;
};

int main()
{
  struct node *head=NULL,*index=NULL;
  int i,num;
  
  for(i=1;i<=5;i++)
    {
      struct node *temp=(struct node *)malloc(sizeof(struct node));
      printf("Please enter number %d:\n",i);
      scanf("%d",&num);
      temp->data=num;
      temp->link=NULL;
  
      if(head==NULL)
	head=temp;
      else
	{
	index=head;
        while(index->link!=NULL)
	   index=index->link;
        index=temp;
	}
    }
  printf(" \n\n\n\nThe first elment you entered is %d @ %p and last element is %d @ %p\n\n ",head->data,head,index->data,index);
  index=head;
  while(index->link!=NULL)
    {
    printf(" %d @ %p location\n",index->data,index);
    index=index->link;
    }
    
    
  return 0;
}
