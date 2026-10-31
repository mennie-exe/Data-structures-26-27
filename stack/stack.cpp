#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        top++;
        arr[top] = value;
    }

    void pop() {
        top--;
    }

    int peek() {
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

//___________________________
// Balanced Parentheses 
//___________________________
bool is_balanced(const string& expression) {
    stack<char> store;
    bool failed = false;
    for (int i = 0; !failed && (i < expression.length()); ++i) {
        char next = expression[i];
        if (next == '(')
            store.push(next);
        else if ((next == ')') && (!store.empty()))
            store.pop();
        else if ((next == ')') && (store.empty()))
            failed = true;
    }
    return (store.empty() && !failed);
}

//________________________________________
// Evaluating Arithmetic Expressions 
//________________________________________
void evaluate_stack_tops(stack<double>& numbers, stack<char>& operations) {
    double operand1, operand2;
    operand2 = numbers.top();
    numbers.pop();
    operand1 = numbers.top();
    numbers.pop();
    
    char op = operations.top();
    operations.pop();

    if (op == '+') numbers.push(operand1 + operand2);
    else if (op == '-') numbers.push(operand1 - operand2);
    else if (op == '*') numbers.push(operand1 * operand2);
    else if (op == '/') numbers.push(operand1 / operand2);
}

double read_and_evaluate(istream& ins) {
    const char DECIMAL = '.';
    const char RIGHT_PAR = ')';
    stack<double> numbers;
    stack<char> operations;
    double number;
    char symbol;
    

    while (ins && ins.peek() != '\n') {
        if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
            ins >> number;
            numbers.push(number);
        }
        else if (string("+-*/").find(ins.peek()) != string::npos) {
            ins >> symbol;
            operations.push(symbol);
        }
        else if (ins.peek() == RIGHT_PAR) {
            evaluate_stack_tops(numbers, operations);
            ins.ignore();
        }
        else {
            ins.ignore();
        }
    }
    return numbers.top();
}

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.peek() << endl; // 30

    s.pop();

    cout << s.peek() << endl; // 20

//___________________________
//      Reverse a word
//___________________________
    string word;
    cout << "Enter a word: ";
    cin >> word;

    Stack reverseStack;

    for (char c : word) {
        reverseStack.push(c);
    }
    cout << "Reversed word: ";
    while (!reverseStack.isEmpty()) {
        cout << (char)reverseStack.peek();
        reverseStack.pop();
    }
    cout << endl;

    cin.ignore(); // Clear newline from stream

//___________________________
//   Evaluate Expression
//___________________________
    cout << "Type a fully parenthesized arithmetic expression:" << endl;
    double answer = read_and_evaluate(cin);
    cout << "That evaluates to " << answer << endl;

    return 0;
}