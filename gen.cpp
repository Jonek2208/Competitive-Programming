#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
 
int main()
{
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = {5, 6, 7, 8};
    std::vector<int> v3 = {9, 10, 11, 12};
 
    std::random_device rd;
    std::mt19937 g(rd());
 
    std::shuffle(v1.begin(), v1.end(), g);
    std::shuffle(v2.begin(), v2.end(), g);
    std::shuffle(v3.begin(), v3.end(), g);
 
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));
    std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}
