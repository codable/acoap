#ifndef SOCKET_HPP_
#define SOCKET_HPP_

class UdpSocket
{
public:
    typedef void (*otUdpReceive)(void *aContext, otMessage *aMessage, const otMessageInfo *aMessageInfo);
    UdpSocket(otInstance &aInstance);
    int Open(otUdpReceive aHandler, void* aContext);
    int Bind(const SockAddr &aSockAddr);
    int Close(void);
    const SockAddr &GetSockName(void) const;
    ssize_t SendTo(Message &aMessage, const MessageInfo &aMessageInfo);
    Message* NewMessage(size_t aLength);
};


#endif // SOCKET_HPP_
