//Binary search tree using linked lists
#include <iostream>
using namespace std;

struct node
{
    int a;
    node *parent;
    node *left;
    node *right;
};

node *root=NULL, *p=NULL, *it=NULL;

void ins(node *p)           //Insert "it" node in the tree
{
    if(root==NULL)          //1st node in the tree
    {
        root=p;
    }
    else                    //Tree exists
    {
        it=root;
        while(1)
        {
            if(it->a > p->a)   //Node is greater than element
            {
                if(it->left==NULL)
                {
                    it->left = p;
                    p->parent=it;
                    break;
                }
                else
                {
                    it=it->left;
                }
            }
            else            //Node is smaller than element
            {
                if(it->right==NULL)
                {
                    it->right=p;
                    p->parent=it;
                    break;
                }
                else
                {
                    it=it->right;
                }
            }
        }
    }
    
}


void Insert()
{
    p=new node;
    int e;
    if(p==NULL)
    {
        cout<<"\nOverflow"<<endl;
        return;
    }
    
    cout<<"\nEnter the value to be inserted"<<endl;
    cin>>e;
    p->a=e;
    p->parent = p->left = p->right = NULL;
    
    ins(p);
    cout<<"\nNode inserted successfully"<<endl;
    
}

void search()
{
    if(root==NULL)
    {
        cout<<"\nUnderflow"<<endl;
        return;
    }
    
    int e,depth=0;
    cout<<"\nEnter the element to be searched"<<endl;
    cin>>e;
    
    it=root;
    while(1)
    {
       if(it->a==e)
       {
           cout<<"\nElement found at depth "<<depth<<endl;
           break;
       }
       else if(it->a > e)
       {
           it=it->left;
           depth++;
       }
       else
       {
           it=it->right;
           depth++;
       }
       
       if(it==NULL)
       {
           cout<<"\nElement not found"<<endl;
           return;
       }
       
    }
}

void del(node *it)           //Delete node at "it"
{
    node *pa=it->parent;
    node *l=it->left;
    node *r=it->right;
    
    if(l==NULL && r==NULL)          //No child
    {
        it->parent=NULL;    //Delinking
        if(pa==NULL)            root=NULL;
        else if(pa->left==it)    pa->left=NULL;
        else if(pa->right==it)    pa->right=NULL;
        delete it;
    }
    else if(l==NULL && r!=NULL)    //Only right child
    {
        if(pa==NULL)            root=r;
        else if(pa->left==it)   pa->left=r;
        else if(pa->right==it)  pa->right=r;
        
        r->parent=pa;
        it->right=NULL;
        it->parent=NULL;
        
        delete it;
    }
    else if(l!=NULL && r==NULL)     //Only left child
    {
        if(pa==NULL)            root=l;
        else if(pa->left==it)   pa->left=l;
        else if(pa->right==it)  pa->right=l;
        
        l->parent=pa;
        it->left=NULL;
        it->parent=NULL;
        
        delete it;
        
    }
    else                            //Both children are present
    {
        if(pa==NULL)            root=r;
        else if(pa->left==it)   pa->left=r;
        else if(pa->right==it)  pa->right=r;
        r->parent=pa;
        it->parent=NULL;
        
        it->left=it->right=NULL;
        l->parent=NULL;
        delete it;
        
        ins(l);
    }
}

void Delete()
{
    if(root==NULL)
    {
        cout<<"\nUnderflow"<<endl;
        return;
    }
    
    int e,depth=0;
    cout<<"\nEnter the element to be deleted"<<endl;
    cin>>e;
    
    it=root;
    while(1)
    {
       if(it->a==e)
       {
           cout<<"\nElement found at depth "<<depth<<endl;
           del(it);
           cout<<"Element deleted successfully"<<endl;
           break;
       }
       else if(it->a > e)
       {
           it=it->left;
           depth++;
       }
       else
       {
           it=it->right;
           depth++;
       }
       
       if(it==NULL)
       {
           cout<<"\nElement not found"<<endl;
           return;
       }
       
    }
    
}

void print(node *it)
{
    if(it->left!=NULL)  print(it->left);
    cout<<it->a<<" ";
    if(it->right!=NULL) print(it->right);
}

void display()
{
    if(root==NULL)
    {
        cout<<"\nUnderflow"<<endl;
        return;
    }
    
    it=root;
    print(root);
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
	cout<<"3. Search"<<endl;
	cout<<"4. Display"<<endl;
	cout<<"5. Exit"<<endl;
	int a;
	cin>>a;
	switch(a)
	{
		case 1 : Insert(); break;
		case 2 : Delete();	 break;
		case 3 : search(); break;
		case 4 : display(); break;
		case 5 : Exit(); break;
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
