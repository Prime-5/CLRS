//Sorted circular linked list

#include <iostream>
using namespace std;

struct node
{
    int a;
    node *next;
    node *pre;
};

node *se=NULL, *p=NULL, *s=NULL, *r=NULL, *i1=NULL, *i2=NULL, *d1=NULL, *d2=NULL; 
node *it;               // "se" points to sentinel, "it" is the iterator



void Insert()
{
    p=new node;
    int e;
    if(p==NULL)
    {
        cout<<"\nOverflow"<<endl;
        return;
    }
    
    cout<<"\nEnter the element to be inserted"<<endl;
    cin>>e;
    p->a=e;
    
    if(se==NULL)       //Linked list is empty
    {
        se=new node;
        se->a=-1;
        se->next=p;
        se->pre=p;
        
        p->pre=se;
        p->next=se;
    }    
    else                //Else the list had some elements
    {
        it=se;
        it=it->next;
        while(it->a <=e && it->a!=-1)
        {
            it=it->next;
        }
        i1=it->pre;
        i2=it;
        
        //Insert the node between i1 and i2
        i1->next=p;
        p->pre=i1;
        i2->pre=p;
        p->next=i2;
        
    }
    
    cout<<"Node inserted successfully"<<endl;
            
}


void Delete()
{
    if(se==NULL)
    {
        cout<<"\nUnderflow"<<endl;
        return;
    }
    
    int e;
    cout<<"\nEnter the element to be deleted"<<endl;
    cin>>e;
    
    it=se;
    it=it->next;        //1st Node
    
    if(it->next->a==-1)    //It is only Node
    {
        if(it->a==e)    //Only node and to be deleted; empty the list
        {
            se->next=NULL;
            se->pre=NULL;
            it->next=NULL;
            it->pre=NULL;
            
            delete it;
            delete se;
            it=se=NULL;
            cout<<"\nDeleted successfully"<<endl;
        
        }
        
        else            //Only node but not to be deleated
        {
            cout<<"\nElement not found"<<endl;
            return;
        }
    }
    else                //Noy an only node
    {
        while(it->a!=e && it->a!=-1)
        {
            it=it->next;
        }
        if(it==se)      //Element not found
        {
            cout<<"\nElement not found"<<endl;
            return;
        }
        
        d1=it->pre;
        d2=it->next;
        //Delete "it", join d1 and d2
        
        it->pre=it->next=NULL;
        d1->next=NULL;
        d2->pre=NULL;
        delete it;
        it=NULL;
        
        d1->next=d2;
        d2->pre=d1;
        cout<<"\nDeleted successfully"<<endl;
    }
    
}


void display()
{
    if(se==NULL)
    {
        cout<<"\nUnderflow"<<endl;
        return;
    }
    
    it=se->next;
    while(it->a!=-1)
    {
        cout<<it->a<<" ";
        it=it->next;
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
	cout<<"1. Insert"<<endl;
	cout<<"2. Delete"<<endl;
	cout<<"3. Display"<<endl;
	cout<<"4. Exit"<<endl;
	int a;
	cin>>a;
	switch(a)
	{
		case 1 : Insert(); break;
		case 2 : Delete();	 break;
		case 3 : display(); break;
		case 4 : Exit(); break;
		default : cout<<"Choose again"<<endl;
				choose();
	}
	
}

 main()
{
    while(1)
        choose();
        
    return 0;
}
