#include <iostream>
#include <new>

using namespace std;

struct Node {
    int _data = 0;
    Node* _right = nullptr;
    Node* _down = nullptr;
};

Node* creat_row_and_init_member(int length_row)
{
    Node* head_row = nullptr;
    Node* temp = nullptr;

    // create new Node with "0"
    Node* newNode = new Node();
    head_row = newNode;
    temp = head_row;

    int val;
    for (int i = 0; i < length_row; i++)
    {
        cin >> val;
        Node* newNode = new Node();
        newNode->_data = val;
        temp->_right = newNode;
        temp = newNode;
    }
    return head_row;
}

Node* build_ds()
{
    Node* head_DS = nullptr;
    Node* temp = nullptr;
    int length_row;
    cin >> length_row;

    while (length_row)
    {
        // Creating a new list(row), and inserting prisoners into the list
        Node* new_row = creat_row_and_init_member(length_row);

        // Threading the new row into the "DS"
        if (!head_DS)
        {
            head_DS = new_row;
            temp = head_DS;
        }
        else
        {
            temp->_down = new_row;
            temp = new_row;
        }

        // Reading an additional line length from the user
        cin >> length_row;
    }
    return head_DS;
}

void print_ds(Node* my_ds)
{
    if (!my_ds)
        return;

    Node* temp = nullptr;
    while (my_ds)
    {
        temp = my_ds;
        while (temp)
        {
            cout << temp->_data << ' ';
            temp = temp->_right;
        }
        cout << endl;
        my_ds = my_ds->_down;
    }
}

void thread_wanted(Node* current, Node*& head_wanted, Node*& temp_head_wanted)
{
    if (!head_wanted)
    {
        head_wanted = current;
        temp_head_wanted = head_wanted;
    }
    else
    {
        temp_head_wanted->_down = current;
        temp_head_wanted = current;
    }
}

void link_wanted(Node* my_ds, int wanted)
{
    if (!my_ds)
        return;

    Node* current = nullptr;
    Node* head_wanted = nullptr;
    Node* temp_head_wanted = nullptr;

    while (my_ds)
    {
        current = my_ds;
        while (current)
        {
            if (current->_data == wanted)
            {
                thread_wanted(current, head_wanted, temp_head_wanted);
                break; // כיוון שבכל שורה לא יכול להיות שישנם 2 איברים דומים לכן ניתן עכשיו לעצור את המשך החיפוש לשורה הזאת
            }
            current = current->_right;
        }
        my_ds = my_ds->_down;
    }
}

void print_pointer_wanted(Node* current)
{
    Node* temp = current;
    if (!current)
        return;

    if (temp->_right)
    {
        temp = temp->_right;
        cout << temp->_data << ' ';
    }
    else
        cout << '0' << ' ';

    print_pointer_wanted(current->_down);
}

void print_wanted(Node* my_ds, int wanted)
{
    if (!my_ds)
        return;

    Node* current = nullptr;

    while (my_ds)
    {
        current = my_ds;
        while (current)
        {
            if (current->_data == wanted)
            {
                print_pointer_wanted(current);
                return;
            }
            current = current->_right;
        }
        my_ds = my_ds->_down;
    }
}

void free_ds(Node*& my_ds)
{
    if (!my_ds)
        return;

    while (my_ds)
    {
        Node* tempRow = my_ds;
        my_ds = my_ds->_down;
        while (tempRow)
        {
            Node* current = tempRow;
            tempRow = tempRow->_right;
            delete current;
        }
    }
    my_ds = nullptr;
}

int main()
{
    Node* my_ds = build_ds();
    print_ds(my_ds);

    int wanted;
    cin >> wanted;
    link_wanted(my_ds, wanted);
    print_wanted(my_ds, wanted);
    free_ds(my_ds);

    return EXIT_SUCCESS;
}
