#include <iostream>
#include <unistd.h>
#include "user_interface.h"

int main(int argc, char** argv)
{
    UserInterface interface;
    interface.initialize();
    interface.join();
    interface.stop();
    return 0;
}