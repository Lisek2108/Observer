#ifndef LISTENER_H
#define LISTENER_H

#include <observer.h>

class Listener : public Observer
{
public:
    Listener(std::string a_name = "");
private:
    const std::string getName();
    const std::string m_listenerName{};
};

#endif // LISTENER_H
