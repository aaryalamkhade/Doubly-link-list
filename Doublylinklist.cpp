#include<iostream>
using namespace std;

class node
{
	public:
	int value;
	node*left;
	node*right;
};

class dll
{
	public:
node*head;
int value;
dll()
{
head=NULL;	
}
	
void insert_be();
void insert_ls();
void insert_pos();
void delete_l();
void update_l();
void display();
};

void dll::insert_be()
{
int value;
node*temp,*p;
temp=new node;
cout<<"enter the value:";
cin>>value;
temp->value=value;
temp->left=NULL;
if(head==NULL)
{
	head=temp;
	head->right=NULL;
}
else
{
p=head;
head=temp;
head->right=p;
p->left=head;	
}
}


void dll::insert_ls()
{
int value;
node*temp,*p;
temp=new node;
cout<<"enter the value:";
cin>>value;
temp->value=value;
temp->right=NULL;
if(head==NULL)
{
	head=temp;
	head->left=NULL;
}
else
{
	p=head;
	while(p->right=NULL)
	{
		p=p->right;
	}
	p->right=temp;
	temp->left=p;
	
}
	
}

void dll::insert_pos()
{
	int value,pos;
node*temp,*p,*q;
temp=new node;
cout<<"enter the pos:";
cin>>pos;
cout<<"enter the value:";
cin>>value;
temp->value=value;
p=head;
for(int i=1;i<pos;i++)
{   q=p;
	p=p->right;
}
p->left->right=temp;
temp->left=p->left;
temp->right=p;
p->left=temp;
}

void dll::delete_l()
{
	int N;
	cout<<"enter the no. you want to delete";
	cin>>N;
	node*p=head;
	
	while(p->value!=N)
	{
		p=p->right;
	}
	p->left->right=p->right;
	p->right->left=p->left;


}

void dll::update_l()
{
node*p,*temp;
p=head;
int pos,value;
cout<<"enter the position of update:";
cin>>pos;
cout<<"enter the value:";
cin>>value;
temp=new node;
temp->value=value;
for(int i=1;i<pos;i++)
{
p=p->right;	
}
p->left->right=temp;
p->right->left=temp;
temp->left=p->left;
temp->right=p->right;
}

void dll::display()
{
node*p;
p=head;
if(p==NULL)
{
	cout<<"list is empty:";
}
else
{int c;
cout<<"enter the 1 for normal link list reverse list other than 1:"<<endl;
cin>>c;

  if(c==1)
  {
	while(p->right!=NULL)
	{
		cout<<p->value<<"->";
		p=p->right;
	}
	if(p!=NULL)
	{
	  	cout<<p->value<<endl;
	}
}
else
{
	while(p->right!=NULL)
	{
		p=p->right;
	}
	while(p->left!=NULL)
	{
		cout<<p->value<<"->";
		p=p->left;
	}
	if(p!=NULL)
	{
	  	cout<<p->value<<endl;
	}
	
}
}
}


int main()
{
	dll d;
	char ch;
	int value;
	
	do
	{
	int choice;
	
	cout<<"enter the choice 1.insert at begin 2.insert at last 3.insert at pos 4.delete 5.update 6.display"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			d.insert_be();
			break;
		case 2:
			d.insert_ls();
			break;	
		case 3:
			d.insert_pos();
			break;
		case 4:
			d.delete_l();
			break;
		case 5:
		     d.update_l();
			 break;			
		case 6:
			d.display();
			break;
			
	}	
	cout<<"press y to continue:"<<endl;
	cin>>ch;
	}while(ch=='y');
}
