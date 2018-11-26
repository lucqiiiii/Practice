#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string input;
    do {
        cout << "Enter a postfix expression or enter end to exit the program:" << endl;
        getline(cin, input);
        int val1, val2, x;
        stack<char> Stack;
        int i=0;
        while (i < input.length()) {
            if ( isspace(input[i]) )
            {
            }
            else if (isdigit(input[i]))
            {
                int val=0;
                do
                {
                    val = val*10 + (input[i]-'0');
                    i++;
                }while(isdigit(input[i]));
                Stack.push(val);
            }
            else
            {
                val2 = Stack.top();
                Stack.pop();
                val1 = Stack.top();
                Stack.pop();
                switch(input[i])
                {
                    case '+': x=val1 + val2;
                        Stack.push(x);
                        break;
                    case '-': x=val1 - val2;
                        Stack.push(x);
                        break;
                    case '*': x=val1 * val2;
                        Stack.push(x);
                        break;
                    case '/': x=val1 / val2;
                        Stack.push(x);
                        break;
                }
            
            }
            i++;
        }
        while (!Stack.empty())
        {
            cout << Stack.top();
            Stack.pop();
        }
        cout << x <<endl;
    
    }while (input != "end");
    return 0;
}
