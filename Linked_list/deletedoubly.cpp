#include<iostream>
using namespace std;

class Node {

public:
	int data ;
	Node* next;
	Node* prev;
	Node(int val){
		data=val;
		next=nullptr;
		prev=nullptr;
	}

};



class LinkedList{

private:
	Node*head;
public:
	LinkedList(){
		head=nullptr;
	}
	
	void insert(int val){

		Node * newnode = new Node ( val);
		if(head==nullptr){
			head=newnode;
			return;
		}
		Node*temp=head;
		while(temp->next!=nullptr){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}


	void deletebegin(){
		if(!head){
			cout<<"There is nothing to delete"<<endl;
			return;
		}
		Node*temp =head;
		head=head->next;
		delete temp;
	}


	void deleteend(){
		if(!head){
			cout<<"There is nothing to delete"<<endl;
			return;
		}
		if(head->next == nullptr){
			deletebegin();
			return;
		}
		Node*temp=head;
		while(temp->next->next != nullptr){
			temp=temp->next;
		}
		Node* delnode=temp->next;
		temp->next=nullptr;
		delete delnode;
		
	}

	void deletepos(int pos){
		if(pos<=0){
			cout<<"Invalid position"<<endl;
			return;
		}
		if(pos==1){
			deletebegin();
			return;
		}
		Node* temp = head;
		for(int i=0;temp && i<pos;i++){
			temp=temp->next;
		}
		if(!temp){
			cout << "Position out of bounds" << endl;
			return;
		}
		if(temp->prev)temp->prev->next=temp->next;
		if(temp->next)temp->next->prev=temp->prev;
		delete temp;
		
	}



	void deleteval(int val){
		if(!head){
			cout<<"List is empty ";
			return;
		}
		Node*temp=head;
		if(head->data == val){
			deletebegin();
			return;
		}
		while(temp && temp->data != val){
			temp=temp->next;
		}
		if(!temp){
			cout<<"The value not found in the list";
			return;
		}
		if(temp->prev)temp->prev->next=temp->next;
		if(temp->next)temp->next->prev=temp->prev;
		delete temp;
		
	}

	
	void display(){
		Node*temp=head;
		while(temp){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
	}
	~LinkedList() {
    		Node* temp = head;
    		while (temp != nullptr) {
        		Node* nextNode = temp->next;
        		delete temp;
        		temp = nextNode;
    		}
}



};
 

int main(){

	LinkedList list;

	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	list.display();

	cout<<endl;
	list.deletebegin();
	list.deleteend();
	list.deletepos(2);
	list.deleteval(40);
	list.display();



return 0;
}