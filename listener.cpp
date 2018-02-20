#include "listener.h"
#include <iostream>
Listener::Listener(std::string a_name)
    :Observer()
    ,m_listenerName(a_name)
{
    addObserver(this);
    std::cout << "Created observer: " << a_name << std::endl;
}
const std::string Listener::getName()
{
    return m_listenerName;
}
