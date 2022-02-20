#include <iostream>

typedef unsigned char ruint8;

int main()
{
    unsigned char isz = 3;
    ruint8 *buf = (ruint8 *)&isz;
    _payloadsize  = (ruint16)buf[0]<<8;
    _payloadsize |= (ruint16)buf[1];
    return 0;
}
