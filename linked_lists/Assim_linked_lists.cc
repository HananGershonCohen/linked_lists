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
void probe_allocation(Node* pointer);
void build_list_with_3_nodes_tail(Node*& head);
void build_list_front(Node*& head);
void insert_front(Node*& head, int data);
void build_list_rear(Node*& head);
void insert_list_rear(Node*& head, Node*& tail, int num);
void insert_in_between(Node* head);
bool delete_node(Node*& head);
bool delete_node(Node*& head, int val);
void switch_pairs(Node*& head);
void add_my_neighbours(Node* head);
void palindromeize_list(Node*& head);

void print_menu();



//==============================================
//          build_list_with_3_nodes
//==============================================
void  build_list_with_3_nodes(Node*& head)
{
	cout << "build_list_with_3_nodes_tail" << " *** Not Implemented Yet ***" << endl;
}

//==============================================
//          print_list
//==============================================
void  print_list(const Node* head)
{
	cout << "print_list" << " *** Not Implemented Yet ***" << endl;
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
	Node* head;
	int option;

	while (true)
	{
		print_menu();
		cin >> option;
		switch (option) {
		case 1:
			build_list_with_3_nodes(head);
			break;
		case 2:
			print_list(head);
			break;
		case 3:
			cout << "build_list_with_3_nodes_tail" << " *** Not Implemented Yet ***" << endl;
			break;
		case 4:
			cout << "build_list_front" << " *** Not Implemented Yet ***" << endl;
			break;
		case 5:
			cout << "build_list_at_tail" << " *** Not Implemented Yet ***" << endl;
			break;
		case 6:
			cout << "insert_in_between" << " *** Not Implemented Yet ***" << endl;
			break;
		case 7:
			cout << "delete_node" << " *** Not Implemented Yet ***" << endl;
			break;
		case 8:
			cout << "switch_pairs" << " *** Not Implemented Yet ***" << endl;
			break;
		case 9:
			cout << "add_my_neighbours" << " *** Not Implemented Yet ***" << endl;
			break;
		case 10:
			cout << "palindromize_list" << " *** Not Implemented Yet ***" << endl;
			break;
		case 11:
			cout << "delete_list" << " *** Not Implemented Yet ***" << endl;
			break;
		case -1: cout << "Going to Exit.. bye" << endl;
			exit(0);
		default: cout << "wrong option. Select again. " << endl;
		}
		cout << endl;
	}
}
