//Program to impliment linked list
//Author-Subhamrit Bimali
//Reference- Data structure using C and C++
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatfirst(nodeptr*,int);
int deletefromlist (nodeptr*);
void displaylist(nodeptr);

int main()
{
	nodeptr list;
	list=NULL;
	insertatfirst(&list,5);
	insertatfirst(&list,6);
	insertatfirst(&list,7);
	displaylist(list);
	deleteatfirst(&list);
	deleteatfirst(&list);
	displaylist(list);
	
}
nodeptr getnode()
{
	return (nodeptr)malloc(sizeof(nodeptr));
}

void freenode(nodeptr p)
{
	free(p);
}

void insertatfirst(nodeptr *p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}
int deleteatfirst(nodeptr *p)
{
	if(*p==NULL)
	{
		printf("Underflow");
		exit(0);
	}
	else
	{
	nodeptr q;
	int x;
	q=*p;
	x=q->info;
	*p=q->next;
	freenode(q);
	return x;
	}
}
void displaylist(nodeptr p)
{
	nodeptr ptr=p;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->next;
	}
}

