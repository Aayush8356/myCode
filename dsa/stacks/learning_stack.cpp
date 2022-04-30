#include <iostream>
using namespace std;

struct stack
{
private:
    int stack_size;
    int *stack_arr;
    int stack_cap;

public:
    stack()
    {
        stack_arr = nullptr;
        stack_size = 0;
        stack_cap = 0;
    }

    void push(int value)
    {
        if (stack_arr == nullptr)
            stack_cap = 1;
        else if (stack_cap == stack_size)
            stack_cap *= 2;
        else
        {
            stack_arr[stack_size] = value;
            stack_size++;
            return;
        }

        int *arr = new int[stack_cap];
        for (int i = 0; i < stack_size; ++i)
        {
            arr[i] = stack_arr[i];
        }
        arr[stack_size] = value;
        stack_arr = arr;

        stack_size++;
        return;
    }

    void pop()
    {
        if (stack_arr == nullptr)
            return;
        stack_size--;
    }
    bool empty()
    {
        return stack_size == 0;
    }

    int top()
    {
        if (stack_size == 0)
        {
            cout << "Kuch dalo toh sahi niche tmhara size likhha hai\n";
            return -1;
        }
        return stack_arr[stack_size - 1];
    }
    int size()
    {
        return stack_size;
    }
};

int main()
{
    stack s;
    s.push(10);
    cout << s.size() << '\n';
    cout << s.top() << '\n';
    s.pop();
    cout << s.size() << '\n';
    cout << boolalpha << s.empty() << '\n';
    cout << s.top() << '\n';
}