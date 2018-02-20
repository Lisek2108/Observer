#ifndef OBSERVER_H
#define OBSERVER_H

#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

struct VirtualInterface {
  virtual ~VirtualInterface() {}
};

namespace Funcs {
using FunctionInt = std::function<void(int)>;
using FunctionDouble = std::function<void(double)>;
using FunctionBool = std::function<void(bool)>;
using FunctionString = std::function<void(std::string)>;
using FunctionIntInt = std::function<void(int, int)>;
}; // namespace Funcs

class Observer final {
  template<typename... Args>
  struct Callback : VirtualInterface {
    std::function<void(Args...)> cb;
  };
  Observer() {}
  ~Observer() {}
  static void topicNotFound(std::string const &a_str);
  static std::map<std::string, std::vector<std::shared_ptr<VirtualInterface>>> map;
 public:
  template<typename... Args>
  static void registerListener(std::string const &a_topic, const std::function<void(Args...)> &a_callback)
  {
    auto pfunc = std::make_shared<Callback<Args...>>();
    pfunc->cb = a_callback;
    map[a_topic].push_back(pfunc);
  }

  template<typename... Args>
  static void notify(std::string const &a_topic, Args... a_arg)
  {
    if (map.count(a_topic) > 0) {
      for (auto &function : map.at(a_topic)) {
        auto pfunc = std::dynamic_pointer_cast<Callback<Args...>>(function);
        if (pfunc) {
          std::function<void(Args...)> func = pfunc->cb;
          func(std::forward<Args>(a_arg)...);
        }
      }
    }
  }
};

#endif // OBSERVER_H
