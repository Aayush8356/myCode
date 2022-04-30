#include <iostream>
using namespace std;
#define cap 10
struct stack
{
private:
    int *stack_arr;
    int index1;
    int index2;
    int s1 = 0;

public:
    stack()
    {
        stack_arr = new int[cap];
        index1 = -1;
        index2 = cap;
    }
    void push1(int value)
    {

        if (index1 < index2 - 1)
        {
            index1++;
            stack_arr[index1] = value;
            s1++;
        }
        else
        {
            cout << "stack overflow\n";
            return;
        }
    }
    void push2(int value)
    {
        if (index2 > index1 + 1)
        {
            index2--;
            stack_arr[index2] = value;
            s1++;
        }
        else
        {
            cout << "stack overflow\n";
            return;
        }
    }
    int top1()
    {
        return stack_arr[index1];
    }
    int top2()
    {
        return stack_arr[index2];
    }

    void pop1()
    {
        --index1;
    }
    void pop2()
    {
        ++index1;
    }
    void size()
    {
        cout << s1 << '\n';
    }
    void display()
    {
        for(int i = 0 ; i < cap ; ++i)
           cout << stack_arr[i] << ' ';
    }
};

int main()
{
    stack s;
    s.push1(2);
    cout << s.top1() << '\n';
    s.push2(4);
    cout << s.top2() << '\n';
    s.push1(5);
    cout << s.top1() << '\n';
    s.push2(6);
    cout << s.top2() << '\n';
    s.push1(9);
    cout << s.top1() << '\n';
    s.push2(7);
    cout << s.top2() << '\n';
    cout << s.top2() << ' ' << s.top1() << '\n';
    s.size();
    s.display();
}