#include <iostream>
using namespace std;

struct node
{
    int a;
    node *pre;
};

node *top=NULL, *p=NULL, *s=NULL, *r=NULL;

void push()
{
    p = new node;
    int e;
    if(p==NULL)
    {
        cout<<"\nStack Overflow"<<endl;
        return;
    }
    
    cout<<"\nEnter the element to be pushed"<<endl;
    cin>>e;
    p->a=e;
    p->pre=NULL;
    
    if(top==NULL)
    {
        top=p;
    }
    else
    {
        p->pre=top;
        top=p;
    }
    
     cout<<"\nElement pushed successfully"<<endl<<endl;
}

void pop()
{
    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    
    s=top;
    top=top->pre;
    s->pre=NULL;
    cout<<s->a<<" successfully deleted"<<endl;
    delete s;
    
}

void display()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow"<<endl;
        return;
    }
    
    r=top;
    while(r!=NULL)
    {
        cout<<r->a<<" ";
        r=r->pre;
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
	cout<<"1. Push"<<endl;
	cout<<"2. Pop"<<endl;
	cout<<"3. Display"<<endl;
	cout<<"4. Exit"<<endl;
	int a;
	cin>>a;
	switch(a)
	{
		case 1 : push(); break;
		case 2 : pop();	 break;
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
}
