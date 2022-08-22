/*
Delete middle node

        alogrithm:
            base case:
                if node is null = head or if node->next is null = tail
                    return false // cant delete head or tail
            
            delete the node // make a temp for next node and return the current node = next node
                Node* next = curr->next;
                curr = next;
*/

#include <iostream>

class Node
{
    public:
        int value;
        Node* next;

        Node(int v) : value(v), next(nullptr) {}
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

        Node* deleteNode(Node* node)
        {
            if(node == nullptr || node->next == nullptr)
            {
                return nullptr;
            }

            Node* temp = node->next;
            node->value = temp->value;
            node->next = temp->next;
            
            delete temp;
            
            return node;
        }

        void deleteNode(int k)
        {
            Node* curr = head;
            while (curr != nullptr)
            {
                if(curr->value == k)
                {
                    curr = deleteNode(curr);
                }
                curr = curr->next;
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

    std::cout << "The original list is: "; 
    list.print();

    list.deleteNode(4);
    std::cout << "The new list is: "; 
    list.print();

    return 0;
}