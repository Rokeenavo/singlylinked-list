
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front();
    void push_back(T data);
    void push_front(T data);
    void clear();
    void insert(T data, int index);
    int GetSize() { return Size; };
    T& operator[](const int index);

private:
    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr)    //nullptr - по умолчанию null
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;

};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;

    delete temp;
    Size--;
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;

        while (current->pNext != nullptr) 
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::clear()
{
    while(Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0)
    {
        push_front(data);
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node<T> *newNode = new Node<T>(data, previous->pNext);
        previous->pNext = newNode;
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *current = this->head;
    while (current!= nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}



int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(22);
    /*
    int numbersCount;
    cin >> numbersCount;

    for (int i = 0; i < numbersCount; i++)
    {
        lst.push_back(rand()%10);
    }
    */

    cout << endl << "Элементов в списке: " << lst.GetSize() << endl;
    

    lst.clear();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << endl;
    }

    cout << endl << "Элементов в списке: " << lst.GetSize() << endl;

    return 0;
}
