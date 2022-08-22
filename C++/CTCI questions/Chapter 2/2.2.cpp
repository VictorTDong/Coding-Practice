/*
Return kth to last element

        alogrithm:
            base case:
                if k == 0, return the tail
            
            recursive case:
                go through the linked list till the end
                then on the recursive calls, add 1 to counter until kth element is equal to counter
                return the current node
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

        Node* kthElement(int& counter, int k)
        {
            if(head == nullptr) return nullptr;

            Node* temp = head;

            head = head->next;
            Node* curr = kthElement(counter, k);

            counter += 1;

            if(counter == k)
            {
                return temp;
            }

            return curr;
        }

        Node* kthElement(int k)
        {
            int counter = 0;
            
            if(k == 0) return tail;

            return kthElement(counter, k);
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

    Node* node = list.kthElement(1);

    std::cout << node->value;

    return 0;
}