#include<stdio.h>
#include<stdlib.h>
int data;
int key;
void add_beg(int);
void add_end(int);
void del_beg();
void del_end();
void disp();
void search(int);
struct node
{
int info;
struct node *next;
}*start=NULL;
int main()
{
int d;
printf("\n\n 1. Add At Beginning \n 2. Add At End \n 3. Delete from Beginning \n 4. Delete from End \n 5. Search Element");
while(1)
{
printf("\n\n Select Option Number: ");
scanf("%d",&d);
switch(d)
{
case 1: printf("\n Enter Element to add: ");
scanf("%d",&data);
add_beg(data);
break;
case 2: printf("\n Enter Element to add: ");
scanf("%d",&data);
add_end(data);
break;
case 3: del_beg();
break;
case 4: del_end();
break;
case 5: printf("\n Enter Element to search: ");
scanf("%d",&key);
search(key);
break;
default: printf("Invalid Option");
}
}
return 0;
}
void add_beg(int data)
{

struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->info=data;
newnode->next=start;
start=newnode;
disp();
}
void add_end(int data)
{
struct node *temp;
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->info=data;
newnode->next=NULL;
temp=start;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
disp();
}
void del_beg()
{
struct node *temp;
temp=start;
start=start->next;
free(temp);
disp();
}
void del_end()
{
struct node *temp,*ptr;
temp=start;
while(temp->next->next!=NULL)
{
temp=temp->next;
}
ptr=temp->next;
temp->next=NULL;
free(ptr);
disp();
}
void disp()
{
struct node *temp;
temp=start;
if(start==NULL)
{
printf("\n List Is Empty");
}
else
{
while(temp!=NULL)
{
printf("\n Data %d present at %u Next Address= %u",temp->info,temp,temp->next);
temp=temp->next;
}
}
}
void search(int key)
{
struct node *temp;
temp=start;
if(start==NULL)
printf("\n List is Empty");
else
{
while(temp->info!=key)
temp=temp->next;
printf("Element found at address=%u",temp);
}
}
