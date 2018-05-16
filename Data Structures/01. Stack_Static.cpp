#include <iostream>
using namespace std;
int top=-1, size=10;
int node[10];

void push()
{
    int e;
    if(top==size-1)
    {
        cout<<"\nStack overflow"<<endl;
        return;
    }
    
    cout<<"\nEnter the element to be pushed"<<endl;
    cin>>e;
    node[++top]=e;
    cout<<"\nElement pushed successfully"<<endl<<endl;
}

void pop()
{
    if(top==-1)
    {
        cout<<"\nStatck underflow"<<endl;
        return;
    }
    
    cout<<node[top--]<<" successfully deleted"<<endl<<endl;
}

void display()
{
    if(top==-1)
    {
        cout<<"\nStatck underflow"<<endl;
        return;
    }
    
    int i=0;
    while(i<=top)
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
	return 0;
}
