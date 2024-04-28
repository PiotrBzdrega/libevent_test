#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "event2/event.h"

int main(int, char**){
    std::cout << "Hello, from libevent_test!\n";
    const char **methods = event_get_supported_methods();
    std::cout<<"Starting Libevent "<<event_get_version() <<". Available methods are:\n ";
    for (int i = 0; methods[i] != nullptr; i++)
    {
        std::cout<<methods[i]<<"\n";
    }

    struct event_base *base;
    base =  event_base_new();
    
    std::cout << "Libevent will use method: "<< event_base_get_method(base) << "\n";

    return 0;
}
