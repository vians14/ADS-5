// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

bool isOperator(char a) {
    return a == '/' || a == '*' || a == '-' || a == '+';
}


int Precedence(char b) {
    if (b == '+' || b == '-') return 1;
    if (b == '*' || b == '/') return 2;
    return 0;
}


int applyOperator(int a, int b, char c) {
    switch (c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; 
        default: throw std::invalid_argument("Invalid operator");
    }
}
std::string infx2pstfx(const std::string& inf) {
    TStack<char, 100> operators;
    std::string result;
    
    for (size_t i = 0; i < inf.length(); ++i) {
        char c = inf[i];
        
       
        if (isspace(c)) {
            continue;
        }
        

        if (isdigit(c)) {
            while (i < inf.length() && isdigit(inf[i])) {
                result += inf[i];
                i++;
            }
            result += ' '; 
            i--;  
        }
     
        else if (c == '(') {
            operators.push(c);
        }
    
        else if (c == ')') {
            while (!operators.isEmpty() && operators.top() != '(') {
                result += operators.pop();
                result += ' ';
            }
            if (!operators.isEmpty() && operators.top() == '(') {
                operators.pop(); 
            }
        }

        else if (isOperator(c)) {
            while (!operators.isEmpty() && operators.top() != '(' && 
                   Precedence(operators.top()) >= Precedence(c)) {
                result += operators.pop();
                result += ' ';
            }
            operators.push(c);
        }
    }
    
  
    while (!operators.isEmpty()) {
        result += operators.pop();
        result += ' ';
    }
    

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }
    
    return result;
}


int eval(const std::string& pref) {
    TStack<int, 100> st;
    
    std::string num = "";
    
    for (int i = 0; i < post.length(); i++) {
        char ch = post[i];
        
        if (ch >= '0' && ch <= '9') {
            num = num + ch;
        }
        
        if (ch == ' ' && num != "") {
            int val = 0;
            for (int j = 0; j < num.length(); j++) {
                val = val * 10 + (num[j] - '0');
            }
            st.push(val);
            num = "";
        }
        
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = st.pop();
            int a = st.pop();
            
            int res = 0;
            if (ch == '+') res = a + b;
            if (ch == '-') res = a - b;
            if (ch == '*') res = a * b;
            if (ch == '/') res = a / b;
            
            st.push(res);
        }
    }
    
    if (num != "") {
        int val = 0;
        for (int j = 0; j < num.length(); j++) {
            val = val * 10 + (num[j] - '0');
        }
        st.push(val);
    }
    
    return st.pop();
  return 0;
}
