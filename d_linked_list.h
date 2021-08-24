// 20170363 박준석
#pragma once

#include <iostream>

template<typename Type>
class node{
    public: 
         Type data;
         node *next;
         node *prev;
};

template<typename Type>
class d_linked_list {
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
        void push_front(Type data); //Typedata를 멤버 변수로 가지는 노드를 맨 앞에 한 개 추가합니다.
        void push_back(Type data); //Typedata를 멤버 변수로 가지는 노드를 맨 뒤에 한 개 추가합니다.
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

        //불 연산
        bool isEmpty() {
            return (this->size == 0);
        }
};

template<typename Type>
void d_linked_list<Type>::push_front(Type data) {
    node<Type> *ptr = new node<Type>;
    
    if(this->isEmpty()) {
        tail = ptr;
    }
    else {
        ptr->next = head;
        head->prev = ptr;
    }
    head = ptr;
    size += 1;
}

template<typename Type>
void d_linked_list<Type>::push_back(Type data) {
    node<Type> *tmp = new node<Type>;
    
    if(this->isEmpty()) {
        head = tmp;
    }
    else {
        tail->next = tmp;
        tmp->prev = tail;
    }
    tail = tmp;
    size += 1;
}

template<typename Type>
void d_linked_list<Type>::insert_node_at(int idx, Type n) {
    if(idx == 0) {
        push_front(n);
        return;
    }
    else if(idx == Size()) {
        push_back(n);
        return;
    }
    node<Type> *tmp = new node<Type>;
    node<Type> *curr = head;

    for(int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    tmp->next = curr;
    tmp->prev = curr->prev;
    curr->prev->next = tmp;
    curr->prev = tmp;

    size += 1;
}

// 삭제 연산
template<typename Type>
Type d_linked_list<Type>::pop_front() {
    node<Type> *tmp = head;
    Type data = tmp->data;

    head = head->next;
    delete tmp;
    size -= 1;

    if(this->isEmpty() == true) {
        head = nullptr;
        tail = nullptr;
    }
    return data;
}

template<typename Type>
Type d_linked_list<Type>::pop_back() {
   node<Type> *tmp = tail;
   Type data = tmp->data;
   tail = tail->prev;

   delete tmp;
   size -= 1;

   if(this->isEmpty() == true) {
       head = nullptr;
       tail = nullptr;
   }
   return data;
}

template<typename Type>
Type d_linked_list<Type>::pop_node_at(int idx) {
    if (idx == 0) {
        return pop_front();
    }
    else if(idx == size-1) {
        return pop_back();
    }

    node<Type> *curr = head;

    for(int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    Type data = curr->data;
    size -= 1;
    delete curr;
    return data;
}

template<typename Type>
void d_linked_list<Type>::delete_list() {
    head = nullptr;
    tail = nullptr;
    size = 0;
    std::cout << "리스트가 삭제되었습니다. \n";  
}
        
//조회 연산

template<typename Type>
Type d_linked_list<Type>::front() {
    node<Type> *ptr = head;
    Type data = ptr->data;

    if(this->isEmpty() == true)
    {
        head = nullptr;
        tail = nullptr;
    }
    return data;
}

template<typename Type>
Type d_linked_list<Type>::back() {
    node<Type> *ptr = head;
    Type data = ptr->data;

    if(this->isEmpty() == true)
    {
        head = nullptr;
        tail = nullptr;
    }
    return data;
}

template<typename Type>
int d_linked_list<Type>::Size() {
    std::cout << "전체 노드의 수는 " << size << "개 입니다. \n";
    return size;
}

template<typename Type>
class dll_deque: public d_linked_list<Type> {
    public:
        void addFront(Type data);
        void addRear(Type data);
        Type getFront();
        Type getRear();
        Type deleteFront();
        Type deleteRear();
};

template<typename Type>
void dll_deque<Type>::addFront(Type data) {
    push_front(Type this->data);
}

template<typename Type>
void dll_deque<Type>::addRear(Type data) {
    push_back(Type this->data);
}

template<typename Type>
Type dll_deque<Type>::getFront() {
    front();
}

template<typename Type>
Type dll_deque<Type>::getRear() {
    back();
}

template<typename Type>
Type dll_deque<Type>::deleteFront() {
    pop_front();
}

template<typename Type>
Type dll_deque<Type>::deleteRear() {
    pop_back();
}