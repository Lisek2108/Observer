// MIT License
//
// Copyright (c) 2018 Paweł Lisiecki
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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

class Observer {
  template<typename... Args>
  struct Callback : VirtualInterface {
    std::function<void(Args...)> cb;
  };

  static inline std::map<std::string, std::vector<std::shared_ptr<VirtualInterface>>> map{};

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
          func((a_arg)...);
        }
      }
    }
  }
};

#endif // OBSERVER_H
