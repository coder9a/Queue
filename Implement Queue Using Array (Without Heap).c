#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int front;
	int rear;
	int arr[4];
};
struct queue q;
int isEmpty()
{
	if(q.rear == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isFull()
{
	if(q.rear == 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue()
{
    int ele;
    if(isFull())
    {
        printf("Queue overflow, cannot insert");
        return;
    }
    else
    {
    	printf("Enter Element\t");
        scanf("%d",&ele); 
        if(q.rear == -1)
        {
        	q.front = q.front+1;
        	q.rear = q.rear+1;
		}
		else
		{
			q.rear = q.rear+1;
		}
		q.arr[q.rear] = ele;
    }
}
int dequeue()
{
	int y;
    if(isEmpty())
    {
        printf("Queue underflow, cannot delete");
        return (q.front);
    }
    else
    {
        y = q.arr[q.front];
        if(q.front == q.rear)
        {
        	q.front = -1;
        	q.rear = -1;
		}
		else
		{
			q.front = q.front+1;
		}
		return y;
    }
}
void display()
{
    int i;
    if(q.rear == -1)
    {
        printf("Queue is empty\n");
        return ;
    }
    else
    {
        for(i=q.front; i<=q.rear; i++)
        {
            printf("%d\t", q.arr[i]);
        }
    }
    printf("\n");
}
int main()
{
	int choice;
	char option='y';
	q.front = -1;
	q.rear = -1;
	while(option=='y' || option=='Y')
    {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter Choice\t");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: enqueue();
        break;
    case 2: dequeue();
        break;
    case 3: display();
        break;
    case 4: 
        return 0;
    default: printf("Wrong Choice");
        break;
    }
    fflush(stdin);
    printf("Do you want to continue (Type y or n)? \t");
    scanf("%c",&option);
    }
}
