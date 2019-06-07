#include "observer.h"

using namespace Funcs;
int main()
{
  auto x = [](int a, int b) { std::cout << a + b << std::endl; };
  Observer::registerListener<int, int>("plus", FunctionIntInt(x));
  Observer::registerListener<int, int>("plus", FunctionIntInt(x));
  Observer::notify("plus", 2, 3);
  Observer::notify("plus",20,20);
  return 0;
}
