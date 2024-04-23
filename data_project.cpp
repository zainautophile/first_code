#include <iostream>
#include <string>
using namespace std;

class account_node {
public:
    string name, password;
    account_node* next;
    account_node(string name, string password) {
        this->name = name;
        this->password = password;
        next = nullptr;
    }
};

class account_linklist {
public:
    account_node* head;
    account_linklist() {
        head = nullptr;
    }
    void account_detail_insertion(string name, string password) {
        account_node* temp = new account_node(name, password);
        if (head == nullptr) {
            head = temp;
        }
        else {
            account_node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    void displayList() {
        account_node* current = head;
        while (current != nullptr) {
            cout << "Name :" << current->name << "\nPassword  " << current->password << endl;
            current = current->next;
        }
    }
};

class Account {
public:
    string username, password;
    account_linklist accounts; // Shared linked list for all accounts

    Account() {
        username = " ";
        password = " ";
    }

    void creataccount() {
        cout << "Name : ";
        getline(cin, username);
        cout << "Password : ";
        getline(cin, password);
        accounts.account_detail_insertion(username, password);
    }
};

void check_login_information(Account& account) {
    string name, pswrd;
    bool loggedIn = false;
    do {
        cout << "Name : ";
        cin.ignore();
        getline(cin, name);
        account_node* current = account.accounts.head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Password : ";
                getline(cin, pswrd);
                if (current->password == pswrd) {
                    cout << "Logged in\n";
                    loggedIn = true;
                    break;
                }
                else {
                    cout << "Incorrect password\n";
                }
            }
            current = current->next;
        }
        if (!loggedIn) {
            cout << "User not found\n";
        }
    } while (!loggedIn);
}
class node
{
public:
    string repositry;
    node* right;
    node* left;
    node(string repositry)
    {
        this->repositry = repositry;
        right = left = NULL;
    }
};
class Account_Tree
{
    node* root;
public:
    Account_Tree()
    {
        root = NULL;
    }
    void insertion(string repositry)
    {
        if (root == NULL)
        {
            root = new node(repositry);
        }
        else if (root->repositry.length() > repositry.length())
        {
            while (root->right != NULL)
            {
                root = root->right;
            }
            node* new_node = new node(repositry);
            root = new_node;
        }
    }
    void deletion(string deletable)
    {
        if (root == NULL)
        {
            cout << "There is not repositry still\n";
        }
        else
        {
            while (root->right != NULL)
            {
                if (root->repositry == deletable)
                {
                    make_deletion(root);
                }
                root = root->right;
            }
        }
    }
    void make_deletion(node* root)
    {
        if (root->left == NULL && root->right == NULL) // Case 1: Deleting a leaf node
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) // Case 2: Deleting a node with only right child
        {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) // Case 2: Deleting a node with only left child
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else // Case 3: Deleting a node with two children
        {
            // Find the inorder successor (the smallest node in the right subtree)
            node* successor = root->right;
            while (successor->left != NULL)
            {
                successor = successor->left;
            }

            // Copy the data of the inorder successor to this node
            root->repositry = successor->repositry;

            // Delete the inorder successor
            make_deletion(successor);
        }
    }

};
//class commit_node
//{
//public:
//    string comit;
//    commit_node* next;
//    commit_node(string comit)
//    {
//        this->comit = comit;
//        next = nullptr;
//    }
//};
//class commit_linkist
//{
//    commit_node* head;
//    commit_linkist()
//    {
//        head = nullptr;
//    }
//    void commit_insertion(string commit)
//    {
//        commit_node* temp = new commit_node(commit);
//        if (head == nullptr)
//        {
//            head = temp;
//        }
//        else
//        {
//            commit_node* curr = head;
//            while (curr->next != nullptr) 
//            {
//                curr = curr->next;
//            }
//            curr->next = temp;
//        }
//    }
//    void comit_deletion(string deletable_comit)
//    {
//        if (head == NULL)
//        {
//            cout << "No, commit yet!\n";
//        }
//        else
//        {
//            commit_node* curr = head;
//            while (curr != NULL)
//            {
//
//
//            }
//        }
//    }
//};

int main() {
    int choice;

    cout << "IF you have any account \n";
    cout << "1    SignIn\n2    login\n";
    cin >> choice;
    cin.ignore();
    Account ac;
    if (choice == 1) {
        ac.creataccount();
        cout << "your account has been created \n";
        cout << "Do you want to login? \n";
        char choice;
        cout << "Y    Yes\nN     No\n";
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            check_login_information(ac);
        }
    }
    else if (choice == 2) {
        check_login_information(ac);
    }
    system("pause");
    return 0;
}