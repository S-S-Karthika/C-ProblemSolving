#include<iostream>
using namespace std;

class Node{

public :
	int data;
	Node*next;
	Node*prev;
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

	void insertbegin(int val){
		Node * newnode = new Node ( val);
		if(!head){
			head=newnode;
			return;
		}
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		return;
	}


	void insertatpos(int pos,int val){
		if(pos<=0){
			cout<<"InValid position"<<endl;
			return ;
		}
		if(pos==1){
			insertbegin(val);
			return;
		}
		Node *newnode =new Node(val);
		Node*temp =head;
		for(int i=1 ; temp && i<pos-1;i++){
			temp=temp->next;
		}
		if(!temp){
			cout<<"Position out of bound"<<endl;
			return;
		}
		newnode->next=temp->next;
		newnode->prev=temp;
		if(temp->next)temp->next->prev=newnode;
		temp->next=newnode;
		return ;

	}


	
	void insertend(int val){
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
	list.insertbegin(10);
	list.insertend(20);
	list.insertend(30);
	list.insertatpos(2,90);

	list.display();

return 0;
}