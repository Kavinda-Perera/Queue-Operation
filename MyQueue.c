#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1,   rear= -1;

void enqueue(int value){
	if(rear == MAX_SIZE -1){
		printf("Error:Queue is full");
	}
	if(front == -1)
		front = 0;
	rear ++;
	queue[rear]=value;
}

void dequeue(){
	if(front == -1){
		printf("Error:Queue is full");
		return;
	}
	front++;
	if(front>rear)
		front = rear = -1;
	
}

int frontValue(){
	if(front == -1){
		printf("Error:Queue is empty");
		return -1;
	}
	return queue[front];
	
}

int rearValue(){
	if(rear == -1){
		printf("Error:queue is epmty");
		return -1;
	}
	return queue[rear];
}

void display(){
	if(front == -1){
		printf("Error:queue is empty");
		return;
	}
	
	printf("Queue elements:");
	for(int i=front;i<=rear;i++){
		printf("%d",queue[i]);
	}
	printf("\n");
}

int main(){
	int value,choice;
	
	do{
		printf("\n-- Queue Operation --\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Front Value\n");
		printf("4.Rear Value\n");
		printf("5.Diaply queue\n");
		printf("6.exit\n");
		printf("Enetr your choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("Enter value to enqueue:");
				scanf("%d",&value);
				enqueue(value);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				printf("Front value:%d\n",frontValue());
				break;
			case 4:
				printf("Rear value:%d\n",rearValue());
				break;
			case 5:
				display();
				break;
			case 6:
				printf("Exiting..");
				break;
			default:
				printf("Invalid choice");
				break;		
		}
		
	}while(choice!=6);
	return 0;
}

