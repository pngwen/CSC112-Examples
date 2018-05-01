// A very simple linked list example
#include <iostream>

using namespace std;


//a simple singly linked list
struct ListNode
{
    int data;
    ListNode *next;
};


//list operations
ListNode *append(ListNode *head, int data);
ListNode *remove(ListNode *head, ListNode *node);
ListNode *find(ListNode *head, int data);


int main()
{
    enum Choice {APPEND=1, REMOVE, PRINT, QUIT} choice;
    int n;
    
    ListNode *head = nullptr;  //start with an empty list

    do {
	//get the choice
	cout << " M E N U" << endl
	     << "==========" << endl
	     << "1.) Append" << endl
	     << "2.) Remove" << endl
	     << "3.) Print" << endl
	     << "4.) Quit" << endl
	     << endl
	     << "Choice: ";
	cin >> n;
	choice = (Choice) n;

	//perform the requested action
	switch(choice) {
	case APPEND:
	    cout << "Number: ";
	    cin >> n;
	    head = append(head, n);
	    break;
	case REMOVE:
	    cout << "Number: ";
	    cin >> n;
	    head = remove(head, find(head, n));
	    break;
	case PRINT:
	    for(ListNode *cur = head; cur != nullptr; cur = cur->next) {
		cout << cur->data << ' ';
	    }
	    cout << endl;
	    break;
	case QUIT:
	    cout << "Thank you for using the linked list!" << endl;
	    break;
	}
    } while(choice != QUIT);
}


//Append an item to the end of the list and return the new head node
ListNode *append(ListNode *head, int data)
{
    ListNode *node;

    //build the new node
    node = new ListNode;
    node->data = data;
    node->next = nullptr;

    //check for an empty list
    if(head == nullptr) {
	return node;
    }


    //find the tail of the list
    ListNode *tail = head;
    while(tail->next != nullptr) {
	tail = tail->next;
    }

    //link the new node
    tail->next = node;

    return head;
}


//removes a node from the list
ListNode *remove(ListNode *head, ListNode *node)
{
    //stop on empty lists or nodes
    if(head == nullptr or node == nullptr) {
	return head;
    }

    //handle removal of the head
    if(head == node) {
	node = node->next;
	delete head;
	return node;
    }

    //find the previous node
    ListNode *prev = head;
    while(prev->next != node) {
	prev = prev->next;
    }

    //unlink
    prev->next = node->next;

    //delete the node that we want to remove
    delete node;

    return head;
}


//Find the first node equal to data
//returns nullptr if not found
ListNode *find(ListNode *head, int data)
{
    for(ListNode *cur = head; cur != nullptr; cur = cur->next) {
	//if we found it, return it
	if(cur->data == data) {
	    return cur;
	}
    }

    return nullptr;
}
