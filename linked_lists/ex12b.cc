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
    int num1, num2 = 1;

    while (num2) {
        cin >> num1 >> num2;

        // create new
        Node* newNode = new Node();
        newNode->_id = num1;
        newNode->_jump = num2;
        newNode->_next = newNode->_prev = nullptr;

        if (!head) {      // Inserting the first element into the list, and pointing the pointers to itself.
            head = newNode;
            temp = head;
        }
        else {                      // inserting the element at the end of the list
            temp->_next = newNode;
            newNode->_prev = temp;
            temp = newNode;
        }
    }
    if (head) {
        temp->_next = head;
        head->_prev = temp;
    }
}

void print_list(Node* head)
{
    if (!head)
        return;

    Node* current = head;
    do {
        cout << current->_id << ' ' << current->_jump << endl;
        current = current->_next;
    } while (current != head);

    cout << endl;
}

Node* print_current_and_move_to_next(Node* temp)
{
    cout << temp->_id << ' ';
    int jump = temp->_jump;

    if (jump >= 0) {
        for (int i = 0; i < jump; i++)
            temp = temp->_next;
    }
    else {
        for (int i = jump; i < 0; i++)
            temp = temp->_prev;
    }

    return temp;
}

void print_list(Node* head, string str)
{
    Node* temp = head; // "temp" is pointer to the member we are in
    int  counter = 0;

    while (counter < 15 && temp->_jump) {
        temp = print_current_and_move_to_next(temp);
        counter++;
    }

    if (!temp->_jump)  // The last print, when we reached the end of the list.
        print_current_and_move_to_next(temp);

}

void delete_list(Node*& head)
{
    if (!head)
        return;

    Node* current = head;
    Node* currentNext = nullptr;

    do {
        currentNext = current->_next;
        delete current;
        current = currentNext;
    } while (current != head);

    head = nullptr;
}

int main()
{
    Node* head = nullptr;


    insert(head); // מעביר את הזרם לפונקציה insert
    //print_list(head); // print all list
    print_list(head, "ex_b"); // print according to EX. B.
    delete_list(head);


    return 0;
}
