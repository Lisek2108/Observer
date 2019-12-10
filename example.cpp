#include "observer.h"

using namespace Funcs;

class Foo {
 public:
  Foo(int a)
    : m_a(a)
  {
  }
  Foo(const Foo& a_other)
    :m_a(a_other.m_a){
    std::cout << "Copying a [Foo] object with a value: " << m_a << std::endl;
  }
  void print()const
  {
    std::cout << "[Foo] value is: " << m_a << std::endl;
  }
 private:
  int m_a{};
};

int main()
{
  Foo f(10);
  Foo f2(20);
  auto printFoo = [](Foo a_foo){a_foo.print();};
  auto printFooConstRef = [](const Foo &a_foo){a_foo.print();};

  Observer::registerListener<Foo>("Print foo",std::function<void(Foo)>(printFoo));
  Observer::registerListener<const Foo&>("Print foo const ref",std::function<void(const Foo&)>(printFooConstRef));

  Observer::notify("Print foo",f);
  Observer::notify("Print foo const ref",f2);

  return 0;
}
