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
	int countItems();
	void insert(int data);
	void insertpos(int pos, int data);
	void Delete();
	void deletepos(int pos);
	void display();
};
int dlist::countItems(){
	node *cur=new node;
	cur=head;
	int i=0;
	while(cur!=NULL){
		cur=cur->next;
		++i;	}
	return i;
}
void dlist::insert(int data){
	node *temp= new node;
	temp->data=data;
	temp->next=NULL;
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
	if(pos==1){
		head->prev=temp;
		temp->next=head;
		head=temp;
	}else{
		for(i=1;i<pos;i++){ 
			if(cur == NULL){
				cout<<"Linked List does not have enough elements\n";
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
			(cur->prev)->next=temp;
			temp->prev=cur->prev;
			temp->next=cur;
			cur->prev=temp;
		}	
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
	if(pos==1){
		head=cur->next;
		cur=NULL;
		delete cur;
	}else{
		for(i=1;i<pos;i++){
			cur=cur->next;
		}
		cur->prev->next=cur->next;
		cur->next->prev=cur->prev;
		cur=NULL;
		delete cur;
	}
}	
void dlist::display(){
	node *cur= new node;
	cur=head;
	while(cur!=NULL){
		cout<< cur->data << "->";
		cur=cur->next;
	}
		cout<<"NULL\n";
} //Make menu based.
int main(){
	dlist dl;	
	int choice,pos,data;
	while (1) {       
		cout<<"1.Insert node at begining"<<endl;
		cout<<"2.Add at particular position"<<endl;
		cout<<"3.Delete"<<endl;
		cout<<"4.Delete at particular position"<<endl;
		cout<<"5.Display"<<endl;
		cout<<"6.Count"<<endl;           
		cout<<"Enter your choice : ";
		cin>>choice;
		switch ( choice ) {
			case 1:
			    cout<<"Enter the data: ";
			    cin>>data;
			    dl.insert(data);
			    cout<<endl;
			    break;
			case 2:
			    cout<<"Enter the data: ";
			    cin>>data;
			    cout<<"Enter the position: ";
			    cin>>pos;
			    dl.insertpos(pos,data); 
			    cout<<endl;
			    break;
			case 3:
			    dl.Delete() ;
			    cout<< "last node has been deleted" << endl;
			    break;
			case 4:
			    cout<<"Enter the position: ";
			    cin>>pos;
			    dl.deletepos(pos);
			    cout<<"node has been deleted"<<endl;
			    break;
			case 5:
			    dl.display();
			    cout<<endl;
			    break;
			case 6:
			    cout<<"the number of items in the list are "<<dl.countItems()<<endl;
			    break;    
			default:
			    cout<<"Wrong choice"<<endl;
       		 }
   	 }
}
