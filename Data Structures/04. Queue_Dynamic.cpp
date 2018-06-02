#include <iostream>
using namespace std;

struct node
{
    int a;
    node *next;
};

node *rear=NULL, *front=NULL, *p=NULL, *s=NULL, *r=NULL;

void enqueue()
{
    p = new node;
    int e;
    if(p==NULL)
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }
    
    cout<<"\nEnter the element to be enqueued"<<endl;
    cin>>e;
    p->a=e;
    p->next=NULL;
    
    if(front==NULL)
    {
        front=rear=p;
    }
    else
    {
        rear->next=p;
        rear=p;
    }
    
    cout<<"\nElement enqueued successfully"<<endl<<endl;
}

void dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue Underflow"<<endl;
        return;
    }
    
    s=front;
    if(front->next==NULL)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;
        s->next=NULL;
    }
    
    cout<<s->a<<" successfully dequeued."<<endl;
    delete s;
}

void display()
{
    if(front==NULL)
    {
        cout<<"Queue Underflow"<<endl;
        return;
    }
    
    r=front;
    while(r!=NULL)
    {
        cout<<r->a<<" ";
        r=r->next;
    }
    
}

void Exit()
{
    cout<<"\nThanks for using the code"<<endl<<endl;
    exit(0);
}

void choose()
{
	cout<<endl<<endl;
	cout<<"Choose"<<endl;
	cout<<"1. Enqueue"<<endl;
	cout<<"2. Dequeue"<<endl;
	cout<<"3. Display"<<endl;
	cout<<"4. Exit"<<endl;
	int a;
	cin>>a;
	switch(a)
	{
		case 1 : enqueue(); break;
		case 2 : dequeue();	 break;
		case 3 : display(); break;
		case 4 : Exit(); break;
		default : cout<<"Choose again"<<endl;
				choose();
	}
	
}



int main() 
{
	while(1)	
	    choose();	
return 0;
}
