#include <iostream>
using namespace std;
//define node structure
struct node{
	int data;
	node *next;
	node *prev;
};

class dlist{
	node *head, *tail;
	public:
	//default constructor
	dlist(){
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
int dlist::countItems(){
	node *cur=new node;
	cur=head;
	int i=0; //keeps track of the number of nodes 
	//traverses the list
	while(cur!=NULL){
		cur=cur->next;
		++i;	}
	return i;
}
void dlist::insert(int data){//inserts node at the end of list
	node *temp= new node;
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(head == NULL){ //checks if there is only one element in the list
		head=temp;
		tail=temp;
	}else{
		temp->prev=tail; //inserts temp at the end
		tail->next=temp;
		tail=temp;
	}
}
void dlist::insertpos(int pos,int data){//inserts at a particular position
	node *cur=new node;
	node *temp=new node; 
	temp->data=data;
	temp->prev=NULL;
	temp->next=NULL;
	int i;
	cur=head;
	if(pos==1){//checks if there is only one element in the list
		head->prev=temp;
		temp->next=head;
		head=temp;
	}else{
		for(i=1;i<pos;i++){ //checks if list has enough elements
			if(cur == NULL){
				cout<<"Linked List does not have enough elements\n";
				i=pos+5;
			}else{
				cur=cur->next;		
			}
		}
		if(i==pos && i!=1){//inserts node if the the position has been reached and there are enough elements
			(cur->prev)->next=temp; //link b/w prev node and temp
			temp->prev=cur->prev; //link b/w temp and prev node
			temp->next=cur; //link b/w temp and cur node
			cur->prev=temp; //link b/w cur and temp
		}	
	}
}

void dlist::Delete(){ // deletes at the end
	node *cur=new node;
	cur=tail;
	tail=cur->prev; //points tail at last but one node
	tail->next=NULL;
	cur->prev=NULL;
	delete cur;
}
void dlist::deletepos(int pos){ //deletes at particular position
	node *cur=new node;
	cur=head; 
	int i;
	if(pos==1){ //checks if need to delete 1st node
		head=cur->next;
		cur=NULL;
		delete cur;
	}else{
		for(i=1;i<pos;i++){ //traverses list till it reaches the position
			cur=cur->next;
		}
		cur->prev->next=cur->next; //links the prev node and next node
		cur->next->prev=cur->prev;
		cur=NULL;
		delete cur;
	}
}	
void dlist::display(){ //displays all the nodes in the list
	node *cur= new node;
	cur=head;
	while(cur!=NULL){
		cout<< cur->data << "->";
		cur=cur->next;
	}
		cout<<"NULL\n";
} 
int main(){
	dlist dl;	
	int choice,pos,data;
	//makes a menu
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
