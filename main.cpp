#include<iostream>
#include<signal.h>
#include<string.h>
using namespace std;
void inserts();
void inserte();
void insertp();
void deletes();
void deletee();
void deletep();
void display();
struct list
{
	char name[10];
	int no;
	list *add;
}*temp,*start,*temp1;
int  main()
{
	int ch,num;
	start=NULL;
	while(1)
	{
		cout<<"enter 1 for insertion at starting:"<<endl;
		cout<<"enter 2 for insertion at ending:"<<endl;
		cout<<"enter 3 for insertion at position:"<<endl;
		cout<<"enter 4 for deletion at starting:"<<endl;
		cout<<"enter 5 for deletion at ending:"<<endl;
		cout<<"enter 6 for deletion at positon:"<<endl;
		cout<<"enter 7 for display:"<<endl;
		cout<<"enter 8 for find exit:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			inserts();
			break;
			case 2:
			inserte();
			break;
			case 3:
			insertp();
			break;
			case 4:
			deletes();
			break;
			case 5:
			deletee();
			break;
			case 6:
			deletep();
			break;
			case 7:
			display();
			break;
			case 8:
			exit(0);

		}
	}
}
void inserts()   //insertion at the begining
{
	char a[10];
	int num,i;
	temp=new list;
	cout<<"enter the name:";
	cin>>a;
	num = strlen(a);
	for(i=0;i<num;i++)
	{
		temp->name[i]=a[i];
	}
	temp->add=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->add=start;
		start=temp;
	}
}
void inserte()                  //insertion atthe ending
{
	char a[10];
	int num,i;
	temp=new list;
	cout<<"enter the name:";
	cin>>a;
	num = strlen(a);
	for(i=0;i<num;i++)
	{
		temp->name[i]=a[i];
	}
	temp->add=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp1=start;
		while(temp1->add!=NULL)
		{
			temp1=temp1->add;
		}
		temp1->add=temp;
	}

}
void insertp()        //insertion by position
{
	int pos;
		char a[10];
	int num,i;
	temp=new list;
	cout<<"enter the name:";
	cin>>a;
	cout<<"enter the position";
	cin>>pos;
	num = strlen(a);
	for(i=0;i<num;i++)
	{
		temp->name[i]=a[i];
	}
	temp->add=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp1=start;
		for(i=1;i<pos-1;i++)
		{
			temp1=temp1->add;
		}
		temp->add=temp1->add;
		temp1->add=temp;
	}

}
void deletes()            //deletion at the begining
{
	if(start==NULL)
	{
		cout<<"no element";
	}
	else
	{
		temp=start;
		start=temp->add;
		delete(temp);
	}
}
void deletee()       //deletion at the end
{
	if(start==NULL)
	{
		cout<<"no element";
	}
	else
	{
		temp1=start;
		while(temp1->add->add!=NULL)
		{
			temp1=temp1->add;
		}
		temp=temp1->add;
		temp1->add=NULL;
		delete(temp);
	}
}
void deletep()                  //deletion by position
{
	int i,pos;
	cout<<"enter the position:";
	cin>>pos;
	if(start==NULL)
	{
		cout<<"no element";
	}
	else
	{
		temp1=start;
		for(i=1;i<pos-1;i++)
		{
			temp1=temp1->add;
		}
		temp=temp1->add;
		temp1->add=temp->add;
		delete(temp);
	}
}
void display()
{
	int i;
	if(start==NULL)
	{
		cout<<"no element"<<endl;
	}
	else
	{
		temp=start;
		for(i=0;i<10;i++)
		{
			cout<<temp->name[i];
		}
		while(temp->add!=NULL)
		{
			temp=temp->add;
			for(i=0;i<10;i++)
			{
				cout<<temp->name[i];
			}
			cout<<"\t";
			//break;
		}
	}
}
