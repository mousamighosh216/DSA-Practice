#include <iostream>
using namespace std;

// single ll

struct Node {
    int data;
    Node* next;

    Node(int val):data(val),next(nullptr) {}
    Node(int val,Node* next): data(val),next(next) {}
};

class LinkedList {
    Node* head;
    Node* tail;
    int start;

    public:
        LinkedList():head(nullptr),tail(nullptr),start(0) {}

        void addEleStart(int val) {
            Node* node=new Node(val);
            node->next=head;
            head=node;

            if(tail==nullptr) {
                tail=head;
            }
            start++;
        }

        void addEleEnd(int val) {
            if(tail==nullptr) {
                addEleStart(val);
                return;
            }
            Node* node =new Node(val);
            tail->next=node;
            tail=node;
            start++;
        }

        void insertIdx(int val,int idx) {
            if(idx==0) {
                addEleStart(val);
                return;
            }

            if(idx==start) {
                addEleEnd(val);
                return;
            }

            Node* temp = head;
            for(int i=1;i<idx;i++) {
                temp=temp->next;
            }

            Node* node=new Node(val,temp->next);
            temp->next=node;
            start++;
        }

        int deleteFirst() {
            int val=head->data;
            head=head->next;
            if(head==nullptr) {
                tail=nullptr;
            }
            start--;
            return val;
        }

        int deleteLst() {
            if(start<=1) {
                return deleteFirst();
            }

            Node* temp=head;
            for(int i=0;i<start-1;i++) {
                temp=temp->next;
            }
            int val=tail->data;
            tail->next=temp;
            start--;
            return val;
        }

        // void deleteIdx(int idx) {

        // }

        void display() {
            Node* temp=head;
            while(temp!=nullptr) {
                cout << temp->data << " ";
                temp=temp->next;
            }
        }
};

int main() {
    LinkedList ll;
    ll.addEleStart(10);
    ll.addEleStart(20);
    ll.display(); cout << "\n";
    ll.addEleEnd(30);
    ll.display(); cout << "\n";
    ll.insertIdx(40,1);
    cout << ll.deleteLst();
    ll.display(); cout << "\n";
}

// double ll

struct node {
    int val;
    node* prev;
    node* next;

    node(int val):val(val),next(nullptr),prev(nullptr) {}
    node(int val, node* next, node* prev):val(val),next(next),prev(prev) {}
};

class LL {
    node* head;
    node* tail;
    int size;

    public:
        LL():size(0),head(nullptr),tail(nullptr){}

        void insertStart(int val) {
            node* Node = new node(val);
            
            if(head!=nullptr) {
                head->prev = Node;
            }
            Node->next = head;
            head = Node;
            if(tail==nullptr) {
                tail = head;
            }
            Node->prev=nullptr;
            size++;
        }

        void insertLast(int val) {
            if(tail==nullptr) {
                insertStart(val);
            }

            node* Node = new node(val);           
            tail->next = Node;
            Node->next = nullptr;
            Node->prev = tail;
            tail = Node;
            size++;
        }

        void insertRandom(int val, int idx) {
            if(idx == 0) {
                insertStart(val);
            }
            if(idx == size) {
                insertLast(val);
            }
    
            node* temp = head;
            node* Node = new node(val); 
            for(int i=1;i<idx-1;i++) {
                temp = temp->next;
            }
            Node->next = temp->next;
            temp->next = Node;
            Node->prev = temp;
            temp = Node->next;
            temp->prev = Node;
            size++;
        }

        void display() {
            node* temp = head;
            node* last = tail;
            while (temp != nullptr) {
                cout << temp->val << "-> ";
                temp = temp->next;
            }

            cout << "\nREVERSED LIST\n";
            while (last != nullptr) {
                cout << last->val << "->";
                last = last->prev;
            }
        }
};

int main() {
    LL L;
    L.insertStart(2);
    L.insertStart(3);
    L.insertStart(4);
    L.insertLast(7);
    L.insertLast(8);
    L.insertLast(6);
    L.display();
    L.insertRandom(9,3);
    L.display();

    return 0;
}

// circular ll

struct node {
    int val;
    node* next;

    node(int val):val(val),next(nullptr) {}
    node(int val, node* next):val(val),next(next) {}
};

class LL {
    node* head;
    node* tail;
    int size;

    public:
        LL():size(0),head(nullptr),tail(nullptr){}

        void insertStart(int val) {
            node* Node = new node(val);

            if(head == nullptr) {
                head = Node;
                tail = Node;
            }
            tail->next = Node;
            Node->next = head;
            tail = Node;
            size++;
        }

        void del(int val) {
            if(head == nullptr) {
                cout << "not found\n";
            }
            
            node* Node = head;
            while (Node->val != val) {
                tail = Node;
                Node = Node->next;
            }

            tail->next = Node->next;
            Node = Node->next;
            size--;
        }

        void display() {
            node* temp = head;
            while (1) {
                cout << temp->val << "-> ";
                temp = temp->next;
                if(temp == head) {
                    cout << "\n";
                    break;
                }
            }
        }
};

int main() {
    LL L;
    L.insertStart(2);
    L.insertStart(3);
    L.insertStart(4);
    L.insertStart(6);
    L.insertStart(5);
    L.insertStart(8);
    L.display();

    L.del(5);
    L.display();
    return 0;
}