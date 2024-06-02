//===============================================================
// List Assimilation Exercise
// Student Name: 
// Date:
// 
// Special comments:
// 
//===============================================================

//-------------includes----------------
#include <iostream>
#include <stdlib.h>
#include <new>

//------------using--------------------
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::nothrow;

//-----------structs-------------------
struct Node
{
	int   data;
	Node* next;
};

//-----------prototypes----------------

void terminate(char* msg, int code);
void build_list_with_3_nodes(Node*& head);
void print_list(const Node* head);
//void probe_allocation(Node* pointer);
void build_list_with_3_nodes_tail(Node*& head);
void build_list_front(Node*& head);
void insert_front(Node*& head, int data);
void build_list_rear(Node*& head);
void insert_list_rear(Node*& head, Node*& tail, int num);
void insert_in_between(Node* head);
bool delete_node(Node*& head);
bool delete_node(Node*& head, int val);
void switch_pairs(Node*& head);
void add_my_neighbours(Node*& head);
void palindromeize_list(Node*& head);

void print_menu();

//==============================================
void  build_list_with_3_nodes(Node*& head)
{	// הכנסת איברים בראש הרשימה
	Node* temp;

	temp = new Node();
	temp->data = 3;
	temp->next = head;
	head = temp;

	temp = new Node();
	temp->data = 2;
	temp->next = head;
	head = temp;

	temp = new Node();
	temp->data = 1;
	temp->next = head;
	head = temp;
}
//==============================================
void  print_list(Node* head)
{
	//cout << "print_list"  << endl;

	Node* temp;
	temp = head;
	while (temp)
	{
		cout << temp->data << ' ';
		temp = temp->next;
	}
}
//==============================================
void build_list_with_3_nodes_tail(Node*& head)
{// הכנסת איברים לסוף הרשימה
	head = new Node();
	head->data = 1;

	head->next = new Node();
	head->next->data = 2;

	head->next->next = new Node();
	head->next->next->data = 3;

	head->next->next->next = nullptr;
}
//==============================================
void insert_front(Node*& head, int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
}
//----------------------------------------------
void build_list_front(Node*& head)
{
	int num;
	cin >> num;
	while (num != 0)
	{
		insert_front(head, num);
		cin >> num;
	}
}
//==============================================
void insert_list_rear(Node*& head, Node*& tail, int num)
{
	Node* temp = new Node();
	temp->data = num;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}
//----------------------------------------------
void build_list_rear(Node*& head)
{
	Node* tail = nullptr;
	int num;
	cin >> num;
	while (num != 0)
	{
		insert_list_rear(head, tail, num);
		cin >> num;
	}
}
//==============================================
void insert_in_between(Node* head)
{
	Node* temp = head;

	while (temp!=nullptr && temp->next != nullptr)
	{
		Node* newNode = new Node();
		newNode->data = 99;
		newNode->next = temp->next;
		temp->next = newNode;
		temp = newNode->next;
	}
}
//==============================================
bool delete_node(Node*& head, int val)
{
	if (head == nullptr) // if there are no members in the list
		return false;

	if (head->data == val) // if need to delete the first member
	{
		Node* temp = head;
		head = head->next; // equal: head = temp->next;
		delete temp;
		return true;
	}

	Node* front = head; 
	Node* rear = head->next;

	while (front)
	{
		if (front->data == val) // if the requested member is found
			break;
		
		// if the requested member is not found, we will advance the pointers to the next member.
		rear = front;
		front = front->next;
	}

	// if found the requested member in the while loop, and stopped the program, then the value of "front" is not "nullptr
	if (front)
	{
		rear->next = front->next;
		delete front;
		return true;
	}

	// if not founded the requested member (=it not exist in linked list)
	return false;

}
//----------------------------------------------
bool delete_node(Node*& head)
{
	int val;
	cin >> val;
	return delete_node(head, val);
}
//==============================================
void switch_pairs(Node*& head) {
	if (!head || !head->next) // אם הרשימה ריקה או אם יש רק איבר אחד ברשימה
		return;

	Node* rear = nullptr;
	Node* curr = head;
	Node* front = nullptr;

	// חילוף ראשוני בין הראש לזוג הבא
	head = curr->next;
	while (curr && curr->next)
	{
		// חלק ההחלפה
		front = curr->next;
		curr->next = front->next;
		front->next = curr;

		// שקר באיטרציה הראשונה 
		if (rear)
		{
			rear->next = front;
		}

		// ניווט המצביעים
		rear = curr;
		curr = curr->next;
	}
}
//==============================================
void add_my_neighbours(Node*& head)
{
	if (!head || !head->next) // אם הרשימה ריקה או אם יש רק איבר אחד ברשימה
		return;

	Node* rear = head;
	Node* mid = rear->next;
	int temp = mid->data;
	int val = rear->data;

	while (mid->next)
	{
		mid->data = val + mid->next->data;
		rear = rear->next;
		mid = mid->next;
		val = temp;
		temp = mid->data;
	}
}
//==============================================
void value_init(Node*& newNode,Node* rear,Node* front)
{
	newNode->data = front->data;
	newNode->next = rear;
}
//==============================================
void palindromeize_list(Node*& head)
{
	if (!head)
		return;

	Node* rear = head;
	Node* front = rear->next;

	while (front)
	{
		Node* newNode = new Node();
		value_init(newNode,rear,front);
		head = newNode;
		rear = newNode;
		front = front->next;
	}
}
//==============================================
void delete_list(Node*& head)
{
	Node* temp;

	while (head)
	{ 
		temp = head;
		head = head->next;
		delete temp;
	}

	delete head;
}
//==============================================
//              terminate
//==============================================
void terminate(const char* msg, int exit_code)
{
	cerr << msg << endl;
	exit(exit_code);
}

//=================================================
//      print menu
//=================================================
void print_menu()
{
	const char* menu[] = {
		"build_list_with_3_nodes",
		"print_list",
		"build_list_with_3_nodes_tail",
		"build_list_front",
		"build_list_at_tail",
		"insert_in_between",
		"delete_node",
		"switch_pairs",
		"add_my_neighbours",
		"palindromize_list",
		"delete_list"
	};

	cout << "Enter number for the option you want:" << endl;

	for (unsigned int i = 0; i < sizeof(menu) / sizeof(char*); i++)
		cout << ' ' << i + 1 << " - " << menu[i] << endl;
}

//==============================================
//                    main
//==============================================
int main()
{
	Node* head = nullptr;
	int option;

	while (true)
	{
		print_menu();
		cin >> option;
		switch (option) {
		case 1:
			build_list_with_3_nodes(head);
			print_list(head);
			break;
		case 2:
			print_list(head);
			break;
		case 3:
			build_list_with_3_nodes_tail(head);
			break;
		case 4:
			build_list_front(head);
			break;
		case 5:
			build_list_rear(head);
			break;
		case 6:
			build_list_rear(head);
			insert_in_between(head);
			break;
		case 7:
			cout << delete_node(head);
			break;
		case 8:
			switch_pairs(head);
			break;
		case 9:
			add_my_neighbours(head);
			break;
		case 10:
			palindromeize_list(head);
			break;
		case 11:
			delete_list(head);
			break;
		case 0:
		case -1: cout << "Going to Exit.. bye" << endl;
			exit(0);
		default: cout << "wrong option. Select again. " << endl;
		}
		cout << endl;
	 	}
	
}
