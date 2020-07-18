#include <iostream>
#include <cstdint>
#include <algorithm>

#include "circular_buffer.hpp"

using namespace std;

int main()
{
    CirBuff<int, 5> v;

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(7);

    cout << "next" << endl;
    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;
    cout << v.pop_front() << endl;

    cout << v.pop_front() << endl;
    // // cout << v.pop_front() << endl;
    // v.push_back(10);
    // cout << "next" << endl;
    // cout << v.pop_front() << endl;
    // cout << v.pop_front() << endl;

    // cout << v.pop_front() << endl;
    // v.push_back(5);

    // for( int it : v )
    //     std::cout << it << std::endl;
}