#include <iostream>
using namespace std;

struct node{ //defines a node structure
	int data;
	node *next;
	node *prev;
};

class cdlist{ 
	node *head, *tail;
	public:
	cdlist(){ //default constructor
		head=NULL;
		tail=NULL;
	}
	//functions
	int countItems();
	void insert(int data);
	void insertpos(int pos, int data);
	void Delete();
	void deletepos(int pos);
	void display();
};

int cdlist::countItems(){
	node *cur=new node;
	cur=head;
	int i=0;
	while(cur!=tail){ //traverses the list 
		cur=cur->next;
		++i;	}
	return i+1; //+1 to include tail 
}

void cdlist::insert(int data){
	node *temp= new node;
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(head == NULL){//if there are no elements in the list
		head=temp;
		tail=temp;
		tail->next=head;
		head->next=tail;
	}else{
		tail->next=temp; //links last node to temp and vice versa
		temp->prev=tail;
		temp->next=head;//links temp to head and vice versa
		head->prev=temp;
		tail=temp; //points tail at temp as it is the last node
	}
}

void cdlist::insertpos(int pos, int data){
	node*temp=new node;
	node*cur=new node;
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	int i;
	cur=head;
	if(pos==1){//if you need to insert at beginning
		temp->next=head;
		head->prev=temp;
		tail->next=temp;
		temp->prev=tail;
		head=temp;
	}
	else{
		for(i=1;i<pos;i++){ 
			if(cur == NULL){//checks if list has enough elements
				cout<<"Linked List does not have enough elements\n";
				i=pos+5;
			}else{
				cur=cur->next;		
			}
		}
		if(i==pos && i!=1){
			if(cur!=tail){ //if inserting is not at the end
			(cur->prev)->next=temp;
			temp->prev=cur->prev;
			temp->next=cur;
			cur->prev=temp;
			}else{ //inserting at the end
			temp->next=head;
			head->prev=temp;
			tail->next=temp;
			temp->prev=tail;
			head=temp;
			}
		}
			
	}
}

void cdlist::Delete(){
	node*cur=new node;
	cur=tail;
	(cur->prev)->next=head; //links the head with the last but one node
	head->prev=cur->prev;
	cur=NULL;
	delete cur;
}
void cdlist::deletepos(int pos){
	node*cur=new node;
	cur=head;
	for(int i=1;i<pos;++i){
		cur=cur->next;
	}
	(cur->prev)->next=cur->next; //links the node before and after cur
	(cur->next)->prev=cur->prev;
	cur=NULL;
	delete cur;
}
void cdlist::display(){
	node *cur= new node;
	cur=head;
	while(cur!=tail){ //traverses the list and prints the data
		cout<< cur->data << "->";
		cur=cur->next;
	}
		cout<<cur->data;//prints data in the last node
}
int main(){
	cdlist cdl;
	int choice,pos,data;
	while (1){    //makes a menu   
		cout<<"1.Insert node at begining"<<endl;
		cout<<"2.Add at particular position"<<endl;
		cout<<"3.Delete"<<endl;
		cout<<"4.Delete at particular position"<<endl;
		cout<<"5.Display"<<endl;
		cout<<"6.Count"<<endl;           
		cout<<"Enter your choice : ";
		cin>>choice;
		switch ( choice ){
			case 1:
			    cout<<"Enter the data: ";
			    cin>>data;
			    cdl.insert(data);
			    cout<<endl;
			    break;
			case 2:
			    cout<<"Enter the data: ";
			    cin>>data;
			    cout<<"Enter the position: ";
			    cin>>pos;
			    cdl.insertpos(pos,data); 
			    cout<<endl;
			    break;
			case 3:
			    cdl.Delete() ;
			    cout<< "last node has been deleted" << endl;
			    break;
			case 4:
			    cout<<"Enter the position: ";
			    cin>>pos;
			    cdl.deletepos(pos);
			    cout<<"node has been deleted"<<endl;
			    break;
			case 5:
			    cdl.display();
			    cout<<endl;
			    break;
			case 6:
			    cout<<"the number of items in the list are "<<cdl.countItems()<<endl;
			    break;    
			default:
			    cout<<"Wrong choice"<<endl;
		}
   	 }
}

