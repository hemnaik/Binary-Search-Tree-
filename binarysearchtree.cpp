//binary search tree/
//data structure//
//author:=hem.v.naik//
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct nodeoftree
{
    int data;
	struct nodeoftree *rightnode,*leftnode;	
}*root=NULL,*newnode=NULL;
int choice,flag,search;
struct nodeoftree *insert(struct nodeoftree *root,struct nodeoftree *newnode)
{
	if(root==NULL)
	{
		root=newnode;
		root->rightnode=root->leftnode=NULL;
		return root;
	}
	if(root->data>newnode->data)
	{
		if(root->leftnode==NULL)
		{	
		root->leftnode=newnode;
		newnode->leftnode=newnode->rightnode=NULL;
	    }
	    insert(root->leftnode,newnode);
	}
	if(root->data<newnode->data)
	{
		if(root->rightnode==NULL)
		{
 	      root->rightnode=newnode;
     	  newnode->leftnode=newnode->rightnode=NULL;
        }
        insert(root->rightnode,newnode);
	}
}
void searchintree(struct nodeoftree *root,int search)
{
	if(root==NULL)
	{
		return;
	}
	if(root->data==search)
	{
		flag=1;
	}
	if(root->leftnode!=NULL&&flag==0)
	{
		searchintree(root->leftnode,search);
	}
	if(root->rightnode!=NULL&&flag==0)
	{
		searchintree(root->rightnode,search);
	}
}
void inorder(struct nodeoftree *root)
{
	if(root!=NULL)
	{
		inorder(root->leftnode);
		std::cout<<root->data<<endl;
		inorder(root->rightnode);
	}
}
void preorder(struct nodeoftree *root)
{
	if(root!=NULL)
	{
		std::cout<<root->data<<endl;
		preorder(root->leftnode);
		preorder(root->rightnode);
	}
}

void postorder(struct nodeoftree *root)
{
	if(root!=NULL)
	{
		postorder(root->leftnode);
		postorder(root->rightnode);
		std::cout<<root->data<<endl;
	}
}
int main()
{
	 for(;;)
	 {
	 	std::cout<<"1--->INSERT"<<endl;
	 	std::cout<<"2--->SEARCH"<<endl;
	 	std::cout<<"3--->INORDER"<<endl;
	 	std::cout<<"4--->PREORDER"<<endl;
	 	std::cout<<"5--->POPSTORDER"<<endl;
	 	std::cout<<"6--->EXIT"<<endl;
	 	std::cout<<"ENTER CHOICE:";
	 	std::cin>>choice;
	 	switch(choice)
	 	{
	 	   case 1:
		   if(root==NULL)
		   {
		   	   newnode=(struct nodeoftree*)malloc(1*sizeof(struct nodeoftree));
		   	   std::cout<<"ENTER DATA:";
		   	   std::cin>>newnode->data;
		   	   root=insert(root,newnode);
		   }
		   else
		   {
		   	   newnode=(struct nodeoftree*)malloc(1*sizeof(struct nodeoftree));
		   	   std::cout<<"ENTER DATA:";
		   	   std::cin>>newnode->data;
		   	   insert(root,newnode);
		   }
		   break;
		   case 2:
		   if(root==NULL)
		   {
		     	std::cout<<"TREE EMPTY"<<endl;
		   }
		   else
		   {
		   	    std::cout<<"ENTR SEARCH:";
		   	    std::cin>>search;
		   	    flag=0;
		   	    searchintree(root,search);
		   	    if(flag==1)
		   	    std::cout<<"DATA FOUND"<<endl;
		   	    else
		   	    std::cout<<"DATA NOT FOUND"<<endl;
		   }
		   break;
		   case 3:
		   if(root==NULL)
		   {
		      	std::cout<<"TREE EMPTY"<<endl;
	       }
	       else
	       {
	       	    std::cout<<"INORDER TRAVERSAL"<<endl;
	       	    inorder(root);
		   }
		   break;
		   case 4:
		   if(root==NULL)
		   {
		      	std::cout<<"TREE EMPTY"<<endl;
	       }
	       else
	       {
	       	    std::cout<<"PREORDER TRAVERSAL"<<endl;
	       	    preorder(root);
		   }
		   break;
		   case 5:
		   if(root==NULL)
		   {
		      	std::cout<<"TREE EMPTY"<<endl;
	       }
	       else
	       {
	       	    std::cout<<"POSTORDER TRAVERSAL"<<endl;
	       	    postorder(root);
		   }
		   break;
		   case 6:
		   	exit(1);
		   default:
		   	std::cout<<"INVALID CHOICE!!!"<<endl;
	    }
	 }
	 getch();
	 return 0;
}


