// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int prior(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infx2pstfx(const string& inf) {
    TStack<char, 100> st;
    string out = "";
    
    for (int i = 0; i < inf.length(); i++) {
        char ch = inf[i];
        
        if (ch == ' ') continue;
        
        if (ch >= '0' && ch <= '9') {
            while (i < inf.length() && inf[i] >= '0' && inf[i] <= '9') {
                out = out + inf[i];
                i++;
            }
            out = out + ' ';
            i--;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                out = out + st.pop();
                out = out + ' ';
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        }
        else {
            while (!st.empty() && st.top() != '(' && prior(st.top()) >= prior(ch)) {
                out = out + st.pop();
                out = out + ' ';
            }
            st.push(ch);
        }
    }
    
    while (!st.empty()) {
        out = out + st.pop();
        out = out + ' ';
    }
    
    if (out.length() > 0 && out[out.length() - 1] == ' ') {
        out = out.substr(0, out.length() - 1);
    }
    
    return out;
}

int eval(const string& post) {
    TStack<int, 100> s;
    string tmp = "";
    
    for (int i = 0; i < post.size(); i++) {
        char c = post[i];
        
        if (c >= '0' && c <= '9') {
            tmp = tmp + c;
        }
        
        if (c == ' ') {
            if (tmp != "") {
                int x = 0;
                for (int j = 0; j < tmp.length(); j++) {
                    x = x * 10 + (tmp[j] - '0');
                }
                s.push(x);
                tmp = "";
            }
        }
        
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = s.pop();
            int a = s.pop();
            
            int r;
            if (c == '+') r = a + b;
            if (c == '-') r = a - b;
            if (c == '*') r = a * b;
            if (c == '/') r = a / b;
            
            s.push(r);
        }
    }
    
    if (tmp != "") {
        int x = 0;
        for (int j = 0; j < tmp.length(); j++) {
            x = x * 10 + (tmp[j] - '0');
        }
        s.push(x);
    }
    
    return s.pop();
}
