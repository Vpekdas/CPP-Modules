#include "../include/MutantStack.hpp"
#include "../include/colors.hpp"
#include "../include/display.hpp"
#include <list>

// https://stackoverflow.com/questions/73440733/how-can-i-implement-my-own-stack-iterator-in-c

int main() {
    {
        std::string title = "Executing subject test using MutantStack.";
        announcementTitle(title);

        std::string message = "Creating a MutantStack and pushing the numbers 1 and 2";
        announcementMessage(message);

        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        message = "Displaying the top value of the stack.";
        announcementMessage(message);

        std::cout << "top: " << mstack.top() << std::endl;

        mstack.pop();

        message = "Removing a value with pop method and displaying size";
        announcementMessage(message);

        std::cout << "size: " << mstack.size() << std::endl;

        message = "Pushing the numbers 3, 5, 737, and 0 onto the stack and displaying its contents.";
        announcementMessage(message);

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
    }
    {

        std::string title = "Executing subject test using std::list.";
        announcementTitle(title);

        std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);

        std::cout << "back: " << mstack.back() << std::endl;

        mstack.pop_back();

        std::cout << "size: " << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(mstack);
    }
    return 0;
}