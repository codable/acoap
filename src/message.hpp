#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include <vector>

#include <coap.h>

class Address : public otIp6Address {
public:
    bool IsMulticast(void) const;
    bool IsAnycastRoutingLocator(void) const;
    bool operator==(const Address &aOther);
    bool operator!=(const Address &aOther);
};

class Message : public otMessage {
public:
    int Prepend(const void *aBuffer, size_t aLength);
    ssize_t Append(const void *aBuffer, size_t aLength);
    Message *Clone(size_t aLength) const;
    Message *Clone(void) const;
    size_t Read(size_t aOffset, size_t aLength, void* aBuffer) const;
    ssize_t Write(size_t aOffset, size_t aLength, const void* aBuffer) const;
    size_t GetLength(void) const;
    size_t GetOffset(void) const;
    void SetOffset(size_t aOffset);
    void MoveOffset(ssize_t aOffset);
    Message *GetNext(void) const;
    int SetLength(size_t aLength);
    void Free(void);

private:
    std::vector<uint8_t> mBuffer;
};

class MessageInfo : public otMessageInfo {
public:
    void SetPeerAddr(const otIp6Address aAddress);
    void SetPeerPort(uint16_t aPort);
    void SetSockAddr(const otIp6Address aAddress);
    Address &GetPeerAddr(void) const;
    Address &GetSockAddr(void) const;
    uint16_t GetPeerPort(void) const;
};

class MessageQueue {
public:
    Message* GetHead(void);
    int Enqueue(Message &aMessge);
    int Dequeue(Message &aMessage);
    void GetInfo(uint16_t &aMessageCount, uint16_t &aBufferCount) const;
};
#endif
