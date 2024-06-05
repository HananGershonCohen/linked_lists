#include <iostream>
#include <new>
using namespace std;

struct Node
{
    int _id;
    int _jump;
    Node* _next;
    Node* _prev;
};

void insert(Node*& head)
{
    Node* temp = head;
    int num1, num2;
    cout << "cin >> num1 >> num2" << endl;
    cin >> num1 >> num2;

    if (num2 == 0)
        return;

    while (num2 != 0)
    {
        // create new
        Node* newNode = new Node();
        newNode->_id = num1;
        newNode->_jump = num2;
        newNode->_next = newNode->_prev = nullptr;

        if (head == nullptr)       //I nserting the first element into the list, and pointing the pointers to itself.
        {
            head = newNode;
            temp = head;
        }
        else                       //  inserting the element at the end of the list
        {
            temp->_next = newNode;
            newNode->_prev = temp;
            temp = newNode;
        }

        cout << "cin >> num1 >> num2 " << endl;
        cin >> num1 >> num2;
    }
    temp->_next = head;
    head->_prev = temp;
}

void print_list(Node* head)
{
    if (!head)
        return;

    Node* current = head;
    do
    {
        cout << current->_id << ' ' << current->_jump << endl;
        current = current->_next;
    } while (current != head);

    cout << endl;
}

Node* print_current_and_move_to_next(Node* head)
{
    Node* temp = head;
    cout << head->_id << ' ';

    if (head->_jump >= 0)
    {
        for (int i = 0; i < head->_jump; i++)
            temp = temp->_next;
    }
    else
    {
        for (int i = head->_jump; i > 0; i++)
            temp = temp->_prev;
    }

    return temp;
}

void print_list(Node* head, string str)
{
    Node* temp = head; // "temp" is pointer to the member we are in
    int  counter = 0; 
    while (counter < 15)
    {
        temp = print_current_and_move_to_next(temp);
        counter++;
    }
}

int main()
{
    Node* head = nullptr;

    insert(head);
    print_list(head);
    print_list(head, "ex_b");
    // delete_list(head);
}

