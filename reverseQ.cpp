#include <stack>
#include <iostream>
#include <queue>

using namespace std;

void reverseQ(int k, queue<int>& Queue)
{
    stack<int> Stack;
    if (Queue.size() == 0 || k > Queue.size() || k<=0)
        return;
    for (int i=0;i<k;i++) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
    for (int i = 0; i<Queue.size()-k;i++) {
        Queue.push(Queue.front());
        Queue.pop();
    }
}

 int main()
{
    queue<int> Queue;
    int k;
    int n;
    cout << "Enter size of queue: " << endl;
    cin >> n;
    int num[n];
    cout << "Enter elements of queue: " << endl;
    for (int i = 0; i < n; ++i){
        std::cin >> num[i];
        Queue.push(num[i]);
    }
    cout << "Enter k: " << endl;
    cin >> k;
    reverseQ(k, Queue);
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}
