#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;

};
struct Node* head;
struct Node* tail;


class LinkedList
{
public:
    struct Node *temp;
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }


    void display();

    void create_list();

    void create_sec_list();

    void add_at_start();

    void add_at_mid();

    void add_at_end();

    void del_at_start();

    void del_at_mid();

    void del_at_end();

    void rev_list();


    struct Node* concat_list(struct Node *head_1, struct Node *head_2)
    {
        struct Node *tail_1;
        if(head_1 == NULL)
        {
            return head_2;
        }
        if(head_2 == NULL)
        {
            return head_1;
        }

        tail_1 = head_1;
        while(tail_1 -> next != NULL)
        {
            tail_1 = tail_1 -> next;
        }
        tail_1 -> next = head_2;
        head_2 -> prev = tail_1;

        return head_1;
    }

};


int main()
{
    LinkedList l;
    int menu_choice, ins_loc;
    do{
        cout << "\n-------------------"<<endl;
        cout << " 1. Creation" << endl;
        cout << " 2. Insertion" << endl;
        cout << " 3. Deletion" << endl;
        cout << " 4. Reverse" << endl;
        cout << " 5. Concatenation" << endl;
        cout << " 6. Display" << endl;
        cout << " 7. Exit the Program"<< endl;
        cout << "Enter your choice : ";
        cin >> menu_choice;

        switch(menu_choice)
        {
            case 1:
                l.create_list();
                break;



            case 2:
                cout << "\nInsert at?"<<endl;
                cout << " 1. Start\n 2. Middle\n 3. End"<<endl;
                cout << "Select location to Insert from : ";
                cin >> ins_loc;
                switch(ins_loc)
                {
                    case 1:
                        l.add_at_start();
                        break;

                    case 2:
                        l.add_at_mid();
                        break;

                    case 3:
                        l.add_at_end();
                        break;

                    default:
                        cout << "Enter a valid expression!"<< endl;
                        break;
                }
                break;

            case 3:
                cout << "\nDelete at?" << endl;
                cout << " 1. Start\n 2. Middle\n 3. End" << endl;
                cout << "Select location to Delete from : ";
                cin >> ins_loc;
                switch(ins_loc)
                {
                    case 1:
                        l.del_at_start();
                        break;

                    case 2:
                        l.del_at_mid();
                        break;

                    case 3:
                        l.del_at_end();
                        break;

                    default:
                        cout << "Please enter a valid character..." << endl;
                        break;
                }
                break;

            case 4:
                l.rev_list();
                break;

            case 5:
                l.create_sec_list();
                head = l.concat_list(head, tail);
                l.display();
                break;

            case 6:
                l.display();
                break;

            case 7:
                cout << "\nProgram Terminated.\n";
                exit(0);


            default:
                cout << "Please enter a valid character..." << endl;
                break;
        }
    }while(menu_choice != 7);
}


void LinkedList::display(){
    cout << "List now : ";
        Node *loc = head;
        if(head != NULL)
        {
            while(loc != NULL)
            {
                cout << loc -> data << " -> ";
                loc = loc -> next;
            }
        }
        cout << "NULL" << endl;
}


void LinkedList::create_list()
{
    int i, n, x;
    Node *temp;
    cout << "\nEnter the number of nodes you wish to add : ";
    cin >> n;
    for(i = 0;i < n;i++){
        Node *newnode = new Node;
        cout << "\n Node " << i + 1 << " data : ";
        cin >> x;
        newnode -> prev = NULL;
        newnode -> data = x;
        newnode -> next = NULL;

        if(head == NULL){
            head = temp = newnode;
        }
        else{
            newnode -> prev = temp;
            temp -> next = newnode;
            temp = newnode;
        }
    }
    display();
}


void LinkedList::create_sec_list()
{
    int i, n, x;
    Node *temp;
    cout << "\nEnter the number of nodes in concatenated list : ";
    cin >> n;
    for(i = 0;i < n;i++){
        Node *newnode = new Node;
        cout << "\n Node " << i + 1 << " data : ";
        cin >> x;
        newnode -> prev = NULL;
        newnode -> data = x;
        newnode -> next = NULL;

        if(head == NULL){
            head = temp =newnode;
        }
        else{
            newnode -> prev = temp;
            temp -> next = newnode;
            temp = newnode;
        }
    }
}


void LinkedList::add_at_start()
{
    Node *newnode = new Node;
    int x;
    cout << "Enter value : ";
    cin >> x;

    newnode -> prev = NULL;
    newnode -> data = x;
    newnode -> next = head;
    head = newnode;

    display();
}


void LinkedList::add_at_mid()
{
    int i = 1, x, n;
    Node* temp;
    cout << "Enter position : ";
    cin >> n;

    temp = head;
    while(i != n - 1)
    {
        temp = temp -> next;
        i++;
    }

    Node *newnode = new Node;
    cout << "Enter value : ";
    cin >> x;

    newnode -> prev = temp;
    newnode -> data = x;
    newnode -> next = temp -> next;
    temp ->next -> prev = newnode;
    temp -> next = newnode;

    display();
}


void LinkedList::add_at_end()
{
    Node *newnode = new Node;
    int x;
    Node* temp;
    cout << "Enter value : ";
    cin >> x;

    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = newnode;
    temp ->next -> prev = newnode;
    newnode -> data = x;
    newnode -> next = NULL;

    display();
}


void LinkedList::del_at_start()
{
    if(head==NULL)
    {
        cout << "Empty List...";
    }
    else
    {
        Node* temp;
        temp = head;
        head = temp -> next;
        head -> prev = NULL;
        delete(temp);

        display();
    }
}


void LinkedList::del_at_mid()
{
    if(head==NULL)
    {
        cout << "Empty List...";
    }
    else
    {
        int i, n;
        Node* temp;
        cout << "Enter position : ";
        cin >> n;

        temp = head;
        Node *del_node = new Node;
        if(n > 1)
        {
            for(i = 1;i < (n-1);i++)
            {
                temp = temp -> next;
            }
            del_node = temp -> next;
            del_node ->next -> prev = temp;
            temp -> next = del_node -> next;
            delete(del_node);

            display();
        }
        else
        {
            cout << "Enter l location number actually in the list...";
        }
    }
}


void LinkedList::del_at_end()
{
    if(head == NULL)
    {
        cout << "Empty List...";
    }
    else
    {
        Node *last_node;
        Node* temp;
        temp = head;
        while(temp ->next -> next != NULL)
        {
            temp = temp -> next;
        }
        last_node = temp -> next;
        temp -> next = NULL;
        delete(last_node);

        display();
    }
}


void LinkedList::rev_list()
{
    Node *forward, *current, *backward;
    forward = head;
    current = backward = NULL;
    while(forward != NULL)
    {
        backward = current;
        current = forward;
        forward = forward -> next;
        current -> next = backward;
    }
    head = current;

    display();
}
