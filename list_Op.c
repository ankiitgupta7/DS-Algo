#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}
  node;

node *create();
void display(node *list);
node *insert(node *list);
node *delete(node *list);

int main()
{
  node *created,*inserted,*deleted;
  printf("Let's create a list\n");
  created=create();
  printf("The original list is as following:\n");
  display(created);
  printf("\n\nLet's insert some no. in this list\n");
  inserted=insert(created);
  printf("The modified list becomes:\n");
  display(inserted);
  printf("\nNow, Let's delete some element from this modified list\n");
  deleted=delete(inserted);
  printf("The final list after insertion and deletion\n");
  display(deleted);
}

node *create()
{
  int n,i;
  node *head=NULL,*p=NULL;
  printf("How many numbers in the list?\n");
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
node *insert(node *list)
{
  int num,pos,i=1;
  node *p=NULL,*tempo=NULL;
  printf("Enter the no. to be inserted and the position after which it's to be inserted, respectively:\n");
  scanf("%d %d",&num,&pos);
  p=list;
  while(i<pos)
    {
    p=p->next;
    i++;
    }
  tempo=(node *)malloc(sizeof(node));
  tempo->data=num;
  tempo->next=p->next;
  p->next=tempo;

  return list;
}
node *delete(node *list)
{
  int i=1,n;
  node *temp=list;
  printf("Which element no. do you want to delete from front: ");
  scanf("%d",&n);
  while(i<n-1)
    {
      temp=temp->next;
      i++;
    }
  temp->next=(temp->next)->next;
  return list;
}
