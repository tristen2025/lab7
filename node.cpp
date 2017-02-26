// FILE: node.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t

using namespace std;

namespace coen70_lab7{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;

	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
    	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
    	node *insert_ptr;

    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }

    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr)
    {
        //cerr << "You have not implemented list_piece." << endl;
        head_ptr= new node(start_ptr->data(),NULL);
        node* cursor = head_ptr ->link();
        head_ptr->set_link(cursor);
        node* iter = start_ptr->link();
        
        while(iter != end_ptr){
            node* new_node = new node(iter->data(), NULL);
            cursor->set_link(new_node);
            
            
            
            cursor = cursor->link();
            iter = iter->link();
        
        
        }
        
    }

    size_t list_occurrences(node* head_ptr, const node::value_type& target)
    {
        //cerr << "You have not implemented list_occurrences." << endl;
        node *cursor;
        size_t answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return answer++;
        
        return answer;
        

        
    }

    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position)
    {
        //cerr << "You have not implemented list_insert_at." << endl;
        node *cursor = head_ptr;
        assert(position > 0 and position <= list_length(head_ptr)+1);
        for (size_t i = 1; (i < position) && (cursor != NULL); i++){
            cursor = cursor->link( );
        }
        node* new_node =  new node(entry,cursor->link());
        cursor->set_link(new_node);
        //cursor->set_data(entry);
        
    }

    node::value_type list_remove_at(node*& head_ptr, size_t position)
    {
        //cerr << "You have not implemented list_remove_at." << endl;
        assert(position > 0 and position <= list_length(head_ptr));
        node *cursor = head_ptr;
        for (size_t i = 1; (i < position) && (cursor != NULL); i++){
            cursor = cursor->link( );
        }
        //if(position >list_length(head_ptr))return 0.0;
        node* delnode = cursor->link();
        cursor->set_link(delnode->link());
        
        delete delnode;
        
        
        
        
        
        
        
    }

    node* list_copy_segment(node* head_ptr, size_t start, size_t finish)
    {
       // cerr << "You have not implemented list_copy_segment." << endl;
        assert((1 <= start) && (start <= finish) && (finish <= list_length(head_ptr)));
        node *cursor = head_ptr;
        node* new_head;
        node* new_cursor;
        for (size_t i = start; (i < finish) && (cursor != NULL); i++){
            
                
                node* new_node = new node(cursor->data(),NULL);
                if(i == start){
                    new_head = new_node;
                    new_cursor = new_node;
                }
                else{
                    new_cursor->set_link(new_node);
                    new_cursor = new_cursor->link();
                
                }
            cursor = cursor->link( );
        }

        
        

        return new_head;
    }
}
               
