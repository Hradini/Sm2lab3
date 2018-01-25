#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

class dlist{
	node *head, *tail;
	public:
	dlist(){
		head=NULL;
		tail=NULL;
	}
	void insert(int data);
	void insertpos(int pos, int data);
	void Delete();
	void deletepos(int pos);
	int countItems();
	void display();
};

void dlist::insert(int data){
	node *temp= new node;
	temp->data=data;
	temp->next= NULL;
	temp->prev=NULL;
	if(head == NULL){
		head=temp;
		tail=temp;
	}else{
		temp->prev=tail;
		tail->next=temp;
		tail=temp;
	}
}
void dlist::insertpos(int pos,int data){
	node *cur=new node;
	node *temp=new node;
	temp->data=data;
	temp->prev=NULL;
	temp->next=NULL;
	int i;
	cur=head;
	for(i=1;i<pos;i++){
		if(cur == NULL){
			cout<<"Linked List does not have enough elements\t";
			i=pos+5;
		}else{
			cur=cur->next;		
		}
	}
	if(i==pos && i==1){
		head=temp;
		temp->next=NULL;
		tail=temp;
	}else if(i==pos && i!=1){
		cur->prev->next=temp;
		temp->prev=cur->prev;
		temp->next=cur;
		cur->next=temp;
	}
}
void dlist::Delete(){
	node *cur=new node;
	cur=tail;
	tail=cur->prev;
	tail->next=NULL;
	cur->prev=NULL;
	delete cur;
}
void dlist::deletepos(int pos){
	node *cur=new node;
	cur=head;
	int i;
	for(i=1;i<pos;i++){
		cur=cur->next;
	}
	cur->prev->next=cur->next;
	cur->next->prev=cur->prev;
	cur->next=NULL;
	cur->prev=NULL;
	delete cur;
}

int dlist::countItems(){
	node *cur=new node;
	int i=0;
	cur=head;
	while(cur!=NULL){
		cur=cur->next;
		++i;
	}
	return i;
}	
void dlist::display(){
	node *cur= new node;
	cur=head;
	while(cur!=NULL){
		cout<< cur->data << "->";
		cur=cur->next;
	}
		cout<<"NULL\n";
}




int main(){
	dlist list1;
	list1.insert(32);
	list1.insert(45);
	list1.insert(65);
	list1.insert(9);
	list1.insert(23);
	list1.display();
	//list1.insertpos(2,89);
	//list1.display();
	//list1.insertpos(6,9);
	//list1.display();
	list1.Delete();
	list1.display();
	list1.deletepos(3);
	list1.display();
cout <<"the number of items on the list are " <<list1.countItems()<<endl;
}

