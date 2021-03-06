#include<iostream>

#include"node.h"
#include"sequence.h"

using namespace std;

using namespace coen70_lab7;

void printList(const node* head){
	const node* cursor = head;
	while(cursor != NULL){
		cout<<cursor->data()<<" ";
	
		cursor = cursor->link();
	
	}
	cout<<"\n";

}
void printSequence(sequence seq){

for(seq.start(); seq.is_item(); seq.advance()){
	cout<<seq.current()<<" ";

}
cout<<"\n";


}


int main(){
    
    node* head = new node(15,NULL);
    
    cout<<head->data()<<"\n";
    list_insert(head,25);
    
    printList(head);
    
    cout<<"head length is "<<list_length(head)<<"\n";
    list_insert_at(head,2,list_length(head));
     list_insert_at(head,7,list_length(head)-2);
    cout<<"head length is "<<list_length(head)<<"\n";
    
    printList(head);
    
    node* head2 = list_copy_segment(head,1,list_length(head));
    cout<<"copied list \n";
    
    node* tail; 
    node* head3; 
    list_copy(head,head3,tail );
    //printList(head);
    printList(head2);
    cout<<"head 3: ";
    printList(head3);
    
     
    
   // printList(head);
    
    delete head;
    delete head2;
    
    sequence s;
    s.insert(5);
    cout<<s.current()<<"\n";
    s.insert(5);
    s.insert(7);
    //s.attach(9);
    s.end();
    printSequence(s);
    cout<<s.current()<<"\n";
    s.attach(10);
    
    
    cout<<"performed insertion \n";
    printSequence(s);





    return 0;
}
