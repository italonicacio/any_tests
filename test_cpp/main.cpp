#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector < int >a{1, 2, 3};
  vector < int >b{4, 5, 6};

    for (auto& [e_a, e_b] : zip(a, b))
    {
      std::cout << e_a << e_b << std::endl;
    }




  return 0;
}
