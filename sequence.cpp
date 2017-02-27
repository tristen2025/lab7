#include<iostream>
#include<cassert>
#include"sequence.h"

using namespace std;

namespace coen70_lab7{

sequence::sequence(){
	//cout<<"running constructor \n";
	head_ptr = NULL;
    tail_ptr = NULL;
    cursor = NULL;
    precursor = NULL;
    many_nodes = 0;
  //  cout<<"ran constructor \n";




}
sequence::sequence(const sequence& source){
	//list_copy(source.head_ptr,head_ptr,tail_ptr);
	//many_nodes = source.many_nodes;
    //cout<<"running constructor \n";
    head_ptr = NULL;
    tail_ptr = NULL;
    cursor = NULL;
    precursor = NULL;
    many_nodes = 0;
    //cout<<"ran constructor \n";
    *this = source;

 
 
 
 }
sequence::~sequence(){
	/*node* del = head_ptr;
	while(del->link() != NULL){
		node* new_del = del;
		del = del->link();
		delete new_del;
		
	
	
	
	}*/
    list_clear(head_ptr);//this will clear all nodes


}

void sequence::start(){
cursor = head_ptr;//cursor is head
precursor = NULL;//precursor is null



}
void sequence::end(){
cursor = tail_ptr;
precursor = head_ptr;
while(precursor->link() != tail_ptr){
	precursor = precursor->link();//get precursor util tail
	


}
//cout<<cursor->data()<<"is the data \n";
    
}

void sequence::advance( ){
	if(cursor != NULL ){
	precursor = cursor;
	cursor = cursor->link();
	}
    if(cursor == NULL){
        precursor = NULL;
    
    }



}
void sequence::insert(const value_type& entry){
	/*if(cursor == head_ptr || cursor == NULL){
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
		many_nodes++;
		cout<<current()<<" is current \n";
     */
    if(precursor == NULL || (!is_item())){
        list_head_insert(head_ptr,entry);
        cursor = head_ptr;
        precursor = NULL;
        many_nodes++;
        if(many_nodes == 1){
            tail_ptr = head_ptr;
        
        }
    }
    else{
        list_insert(precursor, entry);
        cursor = precursor->link();
        many_nodes++;
    
    
    
    }
    


}
 void sequence::attach(const value_type& entry){
 if(cursor == tail_ptr || cursor == NULL){
 /*if(tail_ptr == NULL){
			tail_ptr = head_ptr;
			while(tail_ptr ->link() != NULL){
			tail_ptr = tail_ptr->link();
				
			}
		
		}*/
     
      /* cout<<"cursor == tail \n";
		node* new_node = new node(entry, NULL);
		tail_ptr ->set_link(new_node);
		cursor = new_node;
		tail_ptr = new_node;*/
     list_insert(tail_ptr, entry);
     precursor = tail_ptr;
     tail_ptr = tail_ptr->link();
     cursor = tail_ptr;
		
		
	
	
	}
	else{
		list_insert(cursor,entry);
		precursor = cursor;
		cursor = cursor->link();
		
	
	
	}
	
	//cout<<current()<<" is current \n";
	
	
	many_nodes++;
 	
 
 
 
 
 
 }
  void sequence::operator =(const sequence& source){
  	
      if(source.cursor == NULL ){
          
      list_copy(source.head_ptr,head_ptr,tail_ptr);
      }
      else if(source.cursor == source.head_ptr){
          list_copy(source.head_ptr,head_ptr,tail_ptr);
          cursor = head_ptr;
          precursor= NULL;
          
      
      }
      else{
          list_piece(source.head_ptr,source.cursor,head_ptr,precursor );
          list_piece(source.cursor, NULL, cursor, tail_ptr);
          precursor->set_link(cursor);
          
      
      
      
      }
  	many_nodes = source.many_nodes;
  
  
  
  }
    void sequence::remove_current( ){
        assert(is_item());
        if(cursor == head_ptr){
            cursor = cursor->link();
            list_head_remove(head_ptr);
            
        
        
        }
        else{
            list_remove(precursor);
            cursor = precursor->link();
        
        
        
        }
        
        
        
    
    
    
    }
 sequence::size_type sequence::size( ) const{
 	return many_nodes;

 
 
 
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