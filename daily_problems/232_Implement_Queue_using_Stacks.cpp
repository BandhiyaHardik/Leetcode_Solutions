class MyQueue {
public:
    
    stack<int> input;
    stack<int> output;
    int peekEl = -1;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) {
            peekEl = x;
        }
        input.push(x); 
    }

    int pop() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        int val = output.top(); 
        output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty())
            return peekEl;
        
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty())
            return true;
        
        return false;
    }
};