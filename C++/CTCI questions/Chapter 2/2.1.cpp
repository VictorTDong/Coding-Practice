/*
Remove Dups

    algorithm:
        iterate through a linked list
        if dup is found make prev = curr.next
        else you go on to next node

    we can keep track of the data by using a set to store the data that we have kept track of
*/

#include <iostream>
#include <set>

class Node
{
    public:
    int value;
    Node* next;
    Node* prev;

    Node(int v) : value(v), next(nullptr), prev(nullptr) {}
};

class LinkedList
{
    private:
        Node *head;
        Node *tail;

    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        void removeDup()
        {
            std::set<int> duplicate;

            if (head == nullptr) return;
            
            Node* curr = head;

            while(curr)
            {
                if(duplicate.find(curr->value) != duplicate.end())
                {
                    Node* temp = curr;
                    curr->prev->next = curr->next;
                    if(curr->next != nullptr)
                    {
                        curr->next->prev = curr->prev;
                    }
                    delete temp;
                }
                else
                {
                    duplicate.insert(curr->value);
                }
                curr = curr->next;
            }
        }

        void append(int value)
        {
            Node *node = new Node(value);

            if (head == nullptr)
            {
                head = node;
                tail = head;
            }
            else
            {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }

        void print()
        {
            Node *curr = head;
            std::cout << "[";
            if (curr->next == NULL)
            {
                std::cout << curr->value;
                std:: cout << "]";
            }
            else
            {
                while (curr->next != nullptr)
                {
                    std::cout << curr->value;
                    std::cout << ", ";
                    curr = curr->next;
                }
                std::cout << curr->value << "]" << std::endl;
            }
        }

        ~LinkedList()
        {
            Node *curr;
            Node *next;

            curr = head;

            while (curr)
            {
                next = curr->next;
                delete curr;
                curr = next;
            }
        }
};




int main()
{
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(5);
    list.append(6);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(6);
    list.append(4);
    list.append(5);
    list.append(6);

    std::cout << "The original list is: "; 
    list.print();
    
    list.removeDup();

    std::cout << "The updated list should be: [1, 2, 3, 4, 5, 6]" << std::endl << "New list: "; 
    list.print();
}
