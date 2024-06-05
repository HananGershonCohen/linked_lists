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

void print_list(Node* head, string str)
{

}

int main()
{
    Node* head = nullptr;

    insert(head);
    print_list(head);
    print_list(head, "ex_b");
    // delete_list(head);
}

