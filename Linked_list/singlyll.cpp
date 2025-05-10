#include<iostream>
using namespace std;


struct Node{

public:
	int data ;
	Node* next;
	Node(int val){
		data = val;
		next = nullptr;
	}

};


class LinkedList{

private:
	Node* head;

public:
	LinkedList(){

		head=nullptr;
	}
	void insert(int val){
	     Node*newNode =new Node(val);
		if(head==nullptr){
			head = newNode;
			return ;
		}
		Node*temp =head;
		while(temp->next){
		     temp=temp->next;
		}
		temp->next=newNode;
	}


	void display(){
	Node*temp =head;
	 while(temp){
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
	list.insert(10);
	list.insert(20);
	list.insert(30);
	
	list.display();

return 0;

}