#include<iostream>
#include<cassert>
#include"sequence.h"

using namespace std;

namespace coen70_lab7{

sequence::sequence(){
	cout<<"running constructor \n";
	head_ptr = NULL;
    tail_ptr = NULL;
    cursor = NULL;
    precursor = NULL;
    many_nodes = 0;
    cout<<"ran constructor \n";




}
sequence::sequence(const sequence& source){
	list_copy(source.head_ptr,head_ptr,tail_ptr);
 
 
 
 }
sequence::~sequence(){
	node* del = head_ptr;
	while(del->link() != NULL){
		node* new_del = del;
		del = del->link();
		delete new_del;
		
	
	
	
	}


}

void sequence::start(){
cursor = head_ptr;
precursor = NULL;



}
void sequence::end(){
cursor = tail_ptr;
precursor = head_ptr;
while(precursor->link() != tail_ptr){
	precursor = precursor->link();
	


}
cout<<cursor->data()<<"is the data \n";
    
}

void sequence::advance( ){
	if(cursor != NULL ){
	precursor = cursor;
	cursor = cursor->link();
	}



}
void sequence::insert(const value_type& entry){
	if(cursor == head_ptr || cursor == NULL){
		node* new_node = new node(entry, head_ptr);
		head_ptr = new_node;
		cursor = new_node;
		if(tail_ptr == NULL){
			tail_ptr = head_ptr;
			while(tail_ptr ->link() != NULL){
			tail_ptr = tail_ptr->link();
				
			}
		
		}
		
	
	
	}
	else{
		list_insert(precursor,entry);
		cursor = precursor->link();
		
	
	
	}
	tail_ptr = head_ptr;
			while(tail_ptr ->link() != NULL){
			cout<<tail_ptr->data()<<" ";
			tail_ptr = tail_ptr->link();
				
		}
		cout<<"\n end ptr is"<<tail_ptr->data()<<"\n";


}
 void sequence::attach(const value_type& entry){
 if(cursor == tail_ptr || cursor == NULL){
		node* new_node = new node(entry, tail_ptr->link());
		tail_ptr = new_node;
		cursor = new_node;
		if(tail_ptr == NULL){
			tail_ptr = head_ptr;
			while(tail_ptr ->link() != NULL){
			tail_ptr = tail_ptr->link();
				
			}
		
		}
		
	
	
	}
	else{
		list_insert(cursor,entry);
		precursor = cursor;
		cursor = cursor->link();
		
	
	
	}
 	
 
 
 
 
 
 }
  bool sequence::is_item( ) const{
  	if(cursor != NULL)return true;
  	return false;
  
  
  
  }
 sequence::value_type sequence::current( ) const{
 assert(is_item());
 
 	return cursor->data();
 
 
 }











}//end of namespace