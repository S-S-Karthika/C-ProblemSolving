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





	void deletekey(int val){
		if(!head){
			cout<<"List is empty ";
			return;
		}
		Node*temp=head;
		while(temp->next){
			
			if(temp->data==val){
				
				if(temp==head){
					deletebegin();
				}
				Node*newnode=temp;
			   if(newnode->next)newnode->next->prev=newnode->prev;
			   if(newnode->prev)newnode->prev->next=newnode->next;
			   delete temp;
			   temp=newnode;
			}else{
				temp=temp->next;
			}
		
		}
		
		
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
	list.insert(40);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	list.insert(20);
	cout<<"The original List is"<<endl;
	list.display();
	cout<<endl;




	int key = 20;
	cout<<"The Key is "<<key<<endl;
	list.deletekey(key);
	return 0;
}