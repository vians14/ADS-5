// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int N>
class TStack {
private:
    T arr[N];
    int ptr;
    
public:
    TStack() {
        ptr = -1;
    }
    
    void push(T val) {
        if (ptr < N - 1) {
            ptr++;
            arr[ptr] = val;
        }
    }
    
    T pop() {
        if (ptr >= 0) {
            ptr--;
            return arr[ptr + 1];
        }
        return T();
    }
    
    T top() {
        if (ptr >= 0) {
            return arr[ptr];
        }
        return T();
    }
    
    bool empty() {
        return ptr == -1;
    }
};

#endif  // INCLUDE_TSTACK_H_
