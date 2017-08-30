#include <coap.hpp>

HandleEcho()
{
}

int main()
{
    otInstance otInstance;
    Coap::Resource echo("echo", HandleEcho, NULL);
    Coap coap(otInstance);
    coap.AddResource(echo);
    coap.Start();
    return otMainLoop(otInstance);
}
