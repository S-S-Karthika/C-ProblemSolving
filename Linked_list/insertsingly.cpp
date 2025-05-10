//linked list


#include<iostream>
using namespace std;

struct Node{

	int data;
	Node* next;

	Node(int val){
		data =val;
		next=nullptr;
	}

};


class LinkedList{

	private:
		Node*head;
	public:
		LinkedList(){
			head=nullptr;
		}
	
	void insertbegin(int val){
		Node* newnode = new Node(val);
		if(head==nullptr){
			head=newnode;
			return ;
		}
		newnode->next=head;
		head=newnode;
		return;
	}

	void insertend(int val){
		Node* newnode = new Node(val);
		if(head==nullptr){
			head=newnode;
			return ;
		}
		Node* temp=head;
		while(temp->next != nullptr){
			temp=temp->next;	
		}
		temp->next=newnode;
		return;
	}
	
	void insertatpos(int pos,int val){
		Node* newnode = new Node(val);
		Node*temp=head;
		if(pos==1){
			insertbegin(val);
			return ;
		}
		for(int i=0; temp && i<pos-1;i++){
			temp=temp->next;
		}
		if(!temp){
			cout<<"out of bound given pos";
			return;
		}
		newnode->next = temp->next;
		temp->next =newnode;
		return;
	}
	
	void display(){
		if(!head)return;
		Node*temp=head;
		while(temp != nullptr){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"NULL";
	}

	~LinkedList(){
		Node*temp;
		while(head!=nullptr){
			temp=head;
			head=head->next;
			delete temp;
		}
	}


};



int main(){

	LinkedList list;
	list.insertbegin(20);
	list.insertend(40);
	list.insertatpos(2,100);
	list.insertbegin(10);
	list.insertend(30);
	list.insertatpos(3,90);
	list.insertbegin(20);
	list.display();
return 0;

}