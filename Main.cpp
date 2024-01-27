#include <iostream>
#include <stdexcept> // Для використання стандартних винятків

template<typename T>
class Node {
private:
    Node<T>* next;
    T data;
    Node<T>* prev;
public:
    Node() : next(nullptr), prev(nullptr) {}

    explicit Node(T data, Node<T>* next = nullptr, Node<T>* prev = nullptr)
        : data(data), next(next), prev(prev) {}

    Node<T>* getNext() const {
        return next;
    }

    Node<T>* getPrev() const {
        return prev;
    }

    void setNext(Node<T>* next) {
        this->next = next;
    }

    void setPrev(Node<T>* prev) {
        this->prev = prev;
    }

    T getData() const {
        return data;
    }

    void setData(T data) {
        this->data = data;
    }
};

template<typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoubleLinkedList() {
        clear();
    }

    void clear() {
        while (head) {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Додайте реалізацію інших методів класу...

    void removeFirst() {
        if (isEmpty()) {
            throw std::logic_error("List is empty. Cannot remove first element.");
        }

        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
        --size;
    }

    void removeLast() {
        if (isEmpty()) {
            throw std::logic_error("List is empty. Cannot remove last element.");
        }

        Node<T>* temp = tail;
        tail = tail->getPrev();
        delete temp;
        --size;
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    try {
        DoubleLinkedList<int> list;

        // Приклади викликів функцій, які можуть сгенерувати виняток:
        list.removeFirst(); // Генерує виняток, оскільки список пустий
        list.removeLast();  // Генерує виняток, оскільки список пустий
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
