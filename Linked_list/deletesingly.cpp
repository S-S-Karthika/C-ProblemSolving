#include<iostream>
using namespace std;


class Node{

public:
	int data;
	Node* next;
	Node(int val){
	   data=val;
	   next=nullptr;
	}
};


class LinkedList{

private:
	Node* head;

public:
	LinkedList(){
		head=nullptr;
	}
	
	void insertend(int val){
		Node* newnode = new Node(val);
		if(!head){
			head=newnode;
			return;
		}
		Node* temp=head;
		while(temp->next != nullptr){
			temp=temp->next;
		}
		temp->next=newnode;
		return;
	}


	void deletebegin(){
		if(!head){
		  cout<<"Nothing to delete head is null"<<endl;
	 	  return ;
		}

		Node*temp=head;
		head=head->next;
		delete temp;

	}

	void deleteend(){
		if (!head) {
			cout << "List is empty.\n";
			return;
		}
		if (!head->next) {
			delete head;
			head = nullptr;
			return;
		}
		Node*temp =head;
		while(temp->next->next!=nullptr){
			temp=temp->next;
		}
		Node * delnode=temp->next;
		temp->next=nullptr;
		delete delnode;
		return ;

	}

	void deleteatpos(int pos){
		if (pos <= 0 || !head) {
			cout << "Invalid position.\n";
			return;
		}
		if(pos==1){
			deletebegin();
			return ;
		}
		Node*temp=head;
		for(int i=1; temp && i<pos-1; i++){
			temp=temp->next;
		}
		if(!temp || !temp->next){
			cout<<"pos out of bound.\n";
			return;
		}
		Node* delnode =temp->next;
		temp->next=delnode->next;
		delete delnode;
		return ;
	}

	void deleteval(int val){
		if(!head){
			cout<<"List is empty.\n";
			return;
		}
		if(head->data==val){
			Node*del=head;
			head=head->next;
			delete del;
			return;
		}
		Node*temp=head;
		while(temp->next && temp->next->data != val){
			temp=temp->next;
		}
		if(!temp->next){
			cout<<"element not found";
			return;
		}
		Node* delnode =temp->next;
		temp->next=delnode->next;
		delete delnode;
		return ;
	}



	
	void display(){
		Node*temp =head;
		while(temp){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
		return;
	}

	~LinkedList(){
		Node*temp=head;
		while(head!=nullptr){
			temp=head;
			head=head->next;
			delete temp ;
		}
	}
	

};


int main(){

	LinkedList list;


	 list.insertend(10);
         list.insertend(20);
         list.insertend(30);
         list.insertend(40);
         list.insertend(50);

        cout << "Original list:\n";
        list.display();

	list.deletebegin();
	cout << "\nList after deletion begin:\n";
    	list.display();
	cout<<endl;

	list.deleteend();
	cout << "\nList after deletions end:\n";
    	list.display();cout<<endl;

	list.deleteatpos(2);
	cout << "\nList after deletions pos 2:\n";
    	list.display();cout<<endl;

	list.deleteval(30);
	cout << "\nList after deletions val 30:\n";
    	list.display();cout<<endl;


return 0;
}

