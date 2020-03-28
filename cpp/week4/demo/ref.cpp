#include <functional>
#include <iostream>
 
void f(int& n1, int& n2, const int& n3) {
    std::cout << "In function      : " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    ++n1; 
    ++n2; 
}
 
int main() {
    int n1 = 1, n2 = 2, n3 = 3;
    std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
    n1 = 10;
    n2 = 11;
    n3 = 12;
    std::cout << "Before function  : " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    bound_f();
    std::cout << "After function(1): " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    bound_f();
    std::cout << "After function(2): " << n1 << ' ' << n2 << ' ' << n3 << '\n';
    bound_f();
    std::cout << "After function(3): " << n1 << ' ' << n2 << ' ' << n3 << '\n';
}
/**
 * Before function  : 10 11 12
 * In function      : 1 11 12
 * After function(1): 10 12 12
 * In function      : 2 12 12
 * After function(2): 10 13 12
 * In function      : 3 13 12
 * After function(3): 10 14 12
 */
