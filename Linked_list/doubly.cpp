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

	list.display();
	return 0;
}