#include <iostream>
#include <new>
#include <fstream>

using namespace std;

struct Node {
    int _data = 0;
    Node* _right = nullptr;
    Node* _down = nullptr;
};

Node* creat_row_and_init_member(ifstream& input, int length_row)
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
        input >> val;
        Node* newNode = new Node();
        newNode->_data = val;
        temp->_right = newNode;
        temp = newNode;
    }
    return head_row;
}

Node* build_ds(ifstream& input)
{
    Node* head_DS = nullptr;
    Node* temp = nullptr;
    int length_row;
    input >> length_row;

    while (length_row)
    {
        // Creating a new list(row), and inserting prisoners into the list
        Node* new_row = creat_row_and_init_member(input, length_row);

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
        input >> length_row;
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

    cout << "START thread_wanted" << endl;
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

// הפונקציה שמשרשרת את האיברים המבוקשים לא פועלת כראוי
void link_wanted(Node* my_ds, int wanted)
{
    if (!my_ds)
        return;

    cout << "START link_wanted" << endl;
    Node* current = nullptr;
    Node* head_wanted = nullptr;
    Node* temp_head_wanted = nullptr;

    while (my_ds)
    {
        current = my_ds;
        while (current)
        {
            int TEMP = current->_data;

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
    cout << endl << "START print_pointer_wanted" << endl;
    Node* temp = current;
   // int TEMP = current->_data; //זה מעיף את התכנית כאשר רוצים ךבדוק את הערך של NULL
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
    cout << "START print_wanted" << endl;

    while (my_ds)
    {
        current = my_ds;
        while (current)
        {
            cout << "NOT FOUND" << endl;
            int TEMP = current->_data;

            if (current->_data == wanted)
            {
                cout << "*****************FOUND***************" << endl;
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
    ifstream input;
    string str = "input.txt";
    input.open(str);
    if (!input)
    {
        cerr << "The file " << str << " not opened.\n";
        exit(1);
    }

    Node* my_ds = build_ds(input);
    print_ds(my_ds);

    int wanted;
    cout << "Enter wanted       ";
    input >> wanted;
    link_wanted(my_ds, wanted);
    cout << "SUCCESS link_wanted" << endl;
    print_wanted(my_ds, wanted);
    cout << "SUCCESS print_wanted" << endl;

    input.close();

    free_ds(my_ds);

    return EXIT_SUCCESS;
}
