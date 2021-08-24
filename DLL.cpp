#include <iostream>

template<typename Type>
class node{
    public: 
         Type data;
         node *next;
         node *prev;
};

template<typename Type>
class d_linked_list{
    protected:
        node<Type> *head, *tail;
        int size = 0;
    public:
        d_linked_list() {
            head = nullptr;
            tail = nullptr;
        }
        ~d_linked_list() {
            delete_list();
        }
        // 삽입 연산들
        void push_front(int n); //Typedata를 멤버 변수로 가지는 노드를 맨 앞에 한 개 추가합니다.
        void push_back(int n); //Typedata를 멤버 변수로 가지는 노드를 맨 뒤에 한 개 추가합니다.
        void insert_node_at(int idx, Type n); //idx 위치에 노드를 추가합니다.

        //삭제 연산들
        Type pop_front(); // 맨 앞에 노드를 지우고 그 값을 반환
        Type pop_back(); // 맨 뒤에 노드를 지우고 그 값을 반환
        Type pop_node_at(int idx); //idx 번째 노드를 지우고, 값을 반환
        void delete_list(); // linked list전체를 지웁니다.

        //조회 연산들
        Type front();
        Type back();
        int Size(); // linked list 전체의 노드 수를 반환
        void display_contents();
};

template<typename Type>
void d_linked_list<Type>::push_front(int n) {
    node<Type> *ptr = new node<Type>;
    ptr->next = head;
    ptr->data = n;
    head = ptr;
    size++;
}

template<typename Type>
void d_linked_list<Type>::push_back(int n) {
    node<Type> *tmp = new node<Type>;
    size++;
    tmp->data = n;
    tmp->next = nullptr;
    if(head == nullptr) {
        head = tmp;
        tail = tmp;
    }
    else {
        tail->next = tmp;
        tail = tail->next;
    }
}

template<typename Type>
void d_linked_list<Type>::insert_node_at(int idx, Type n) {
    if(size < idx || 0 > idx) {
        std::cout << "해당 인덱스가 없습니다 \n";
    }
    else {
        node<Type> *ptr = head;
        node<Type> *tmp = ptr;
        node<Type> *new_node = new node<Type>;
        new_node->data = n;
        new_node->next = nullptr;
        for(int i = 0; i < idx; i++) {
            tmp = ptr;
            ptr = ptr->next;
        }
        tmp->next = new_node;
        new_node->next = ptr;
        size++;
    }
}

// 삭제 연산
template<typename Type>
Type d_linked_list<Type>::pop_front() {
    node<Type> *ptr = head;
    int value = head->data;
    head = ptr->next;
    delete ptr;
    size--;
    return value;
}

template<typename Type>
Type d_linked_list<Type>::pop_back() {
   node<Type> *ptr = head;
   node<Type> *tmp = new node<Type>;
   while(ptr->next != nullptr) {
       tmp = ptr;
       ptr = ptr->next;
   }
   int value = ptr->data;
   tail = tmp;
   tail->next = nullptr;
   delete ptr;
   size--;
   return value;
}

template<typename Type>
Type d_linked_list<Type>::pop_node_at(int idx) {
    int value = -1;
    if(size < idx || 0 > idx) {
        std::cout << "해당 인덱스는 존재하지 않습니다. \n";
    }
    else {
      node<Type> *ptr = head;
      node<Type> *tmp = ptr;
      for(int i = 0; i < idx; i++) {
           tmp = ptr;
           ptr = ptr->next;
       }
       value = ptr->data;
       tmp->next = ptr->next;
    }
}

template<typename Type>
void d_linked_list<Type>::delete_list() {
    node<Type> *ptr = head;
    while(ptr != nullptr)
    {
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    size = 0;
    std::cout << "리스트가 삭제되었습니다. \n";  
}
        
//조회 연산

template<typename Type>
Type d_linked_list<Type>::front() {
    node<Type> *ptr = head;
    int value = head->data;
    head = ptr->next;
    return value;
}

template<typename Type>
Type d_linked_list<Type>::back() {
    node<Type> *ptr = head;
    node<Type> *tmp = ptr;
    while(ptr->next != nullptr)
    {
        tmp = ptr;
        ptr = ptr->next;
    }
    int value = ptr->data;
    tail = tmp;
    tail->next = nullptr;
    return value;
}

template<typename Type>
int d_linked_list<Type>::Size() {
    std::cout << "전체 노드의 수는 " << size << "개 입니다. \n";
    return size;
}

template<typename Type>
void d_linked_list<Type>::display_contents(){
    node<Type> *ptr = head;
    while(ptr != nullptr)
    {
        std::cout << ptr->data << "->";
        ptr = ptr->next;
    }
    std::cout << "nullptr" << "\n";
}

int main() {
    d_linked_list<int> dl_list;
    dl_list.push_back(10);
    dl_list.push_back(12);
    dl_list.push_back(15);
    dl_list.push_back(18);
    dl_list.push_back(16);
    dl_list.display_contents();

    std::cout << dl_list.front();
    std::cout << dl_list.back();
}

template<typename Type>
class dll_deque: public d_linked_list<Type> {
    public:
        void addFront(int data);
        void addRear(int data);
        int getFront();
        int getRear();
        int deleteFront();
        int deleteRear();
};


