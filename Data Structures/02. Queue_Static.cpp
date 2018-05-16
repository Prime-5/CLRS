#include <iostream>
using namespace std;
int head=-1, tail=-1, size=10;
int node[10];

void enqueue()
{
    int e;
    if(tail==size-1)
    {
        cout<<"\nQueue overflow"<<endl;
        return;
    }
    
    if(head==-1)
    {
        head++;
    }
    
    cout<<"\nEnter the element to be enqueued"<<endl;
    cin>>e;
    node[++tail]=e;
    cout<<"\nElement enqueued successfully"<<endl<<endl;
}

void dequeue()
{
    if(head==-1)
    {
        cout<<"\nQueue underflow"<<endl;
        return;
    }
    
    cout<<node[head]<<" successfully dequeued"<<endl<<endl;
    
    if(head==tail)
    {
        tail=-1;
        head=-1;
    }
    else
    {
        head++;
    }
    
}

void display()
{
    if(head==-1)
    {
        cout<<"\nQueue underflow"<<endl;
        return;
    }
    
    int i=head;
    while(i<=tail)
    {
        cout<<node[i]<<" ";
        i++;
    }
    cout<<endl<<endl;
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
