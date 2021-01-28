#include<stdio.h>
int front = -1;
int rear = -1;
int size;
void enqueue(int *Q)
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
        if(rear == -1)
        {
        	front = front+1;
        	rear = rear+1;
		}
		else
		{
			rear = (rear+1)%size;
		}
		Q[rear] = ele;
    }
}
int dequeue(int *Q)
{
	int y;
    if(isEmpty())
    {
        printf("Queue underflow, cannot delete");
        return (front);
    }
    else
    {
        y = Q[front];
        if(front == rear)
        {
        	front = -1;
        	rear = -1;
		}
		else
		{
			front = (front+1)%size;
		}
		return y;
    }
}
int isEmpty()
{
	if(front == -1)
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
	if((rear+1)%size == front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void display(int *Q)
{
    int i;
    if(rear == -1)
    {
        printf("Queue is empty\n");
        return ;
    }
    else
    {
        for(i=front; i<=rear; i++)
        {
            printf("%d\t", Q[i]);
        }
    }
    printf("\n");
}
int main()
{
	int choice;
	char option='y';
	printf("Enter size of queue\t");
	scanf("%d",&size);
	int Q[size];
    printf("Queue has been created successfully\n");
    while(option=='y' || option=='Y')
    {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter Choice\t");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: enqueue(Q);
        break;
    case 2: dequeue(Q);
        break;
    case 3: display(Q);
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
