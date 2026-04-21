// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    T data[n];
    int top;
    
public:
    TStack() : top(-1) {}
    
    void push(const T& value) {
        if (topIndex >= n - 1) {
            throw std::overflow_error("Stack overflow");
        }
        data[++topIndex] = value;
    }
    
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return data[top--];
    }
    
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[top];
    }
    
    bool isEmpty() const {
        return top == -1;
    }
    
    int size() const {
        return top + 1;
    }
    
    void clear() {
        top = -1;
    }
};


#endif  // INCLUDE_TSTACK_H_
