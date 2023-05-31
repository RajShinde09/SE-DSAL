#include<iostream>
using namespace std;

class tree{
	struct node{
		char data[20];
		node *left, *right;
	};
	
	public:
		node *New, *root;
		tree(){
			root=NULL;
		}
		void create();
		void insert(node *, node *);
		void display(node *root);
		void printlevel(node *root,int level);
		int height(node *);
		
};

void tree::create(){
	char ans='y';
	do{
		New=new node;
		cout<<"Enter Element: ";
		cin>>New->data;
		New->left = New->right = NULL;
		
		if(root==NULL)
		{
			root = New;
		}
		else
		{
			insert(root,New);
		}
		
		cout<<"Do you want to insert more elements(y/n): ";
		cin>>ans;
	} while(ans=='y');
}

void tree::insert(node *root,node *New)
{
	char c;
	cout<<"Where to insert "<<root->data<<"(l/r): ";
	cin>>c;
	
	if(c=='l'){
		if(root->left==NULL){
			root->left=New;
		}
		else{
			insert(root->left,New);
		}
	}
	
	else if(c=='r')
	{
		if(root->right==NULL)
		{
			root->right=New;
		}
		else
		{
			insert(root->right,New);
		}
	}
}

int tree::height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int rh=height(root->right);
		int lh=height(root->left);
		if(lh>=rh)
		{
			return lh+1;
		}
		if(rh>lh)
		{
			return rh+1;
		}
	}
}

void tree::printlevel(node *root,int level)
{
	if(root==NULL)
	{
		return;
	}
	if(level==1)
	{
		cout<<" "<<root->data;
	}
	
	else if(level>1)
	{
		printlevel(root->left,level-1);
		printlevel(root->right,level-1);
	}
}

void tree::display(node *root)
{
	int h=height(root);
	for(int i=1;i<=h;i++)
	{
		cout<<"\n";
		printlevel(root,i);
	}
}

int main()
{
	int ch;
	tree t;
	while(true)
	{
		cout<<"\n1.Create \n2.Display \n3.Exit";
		cout<<"\nEnter choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				t.create();
				break;
				
			case 2:
				t.display(t.root);
				break;
				
			case 3:
				exit(0);
				break;
		}
	}
}




