#include <iostream>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/NetException.h>
#include <boost/scoped_array.hpp>


#include <cstring>
#include <iomanip>


void hexOutputOfBuf(u_char *buf, size_t size_of_buf, const std::string &comment)
{
    std::cout << comment << "\n";

    for( size_t i = 0; i < size_of_buf; i++ )
            std::cout << std::hex << buf[i];

    std::cout << std::endl;

}


class TestMsg
{
    unsigned short _header;
    short _a, _b;
    char _d = 2;
    char _buf[8];

public:

    TestMsg(int a, int b, const std::string &msg): _header(0xFFFF), _a(a), _b(b)
    {
        (void)_a, (void)_b, (void)_d, (void)_header;

        memcpy(_buf, msg.c_str(), msg.length());

        hexOutputOfBuf(reinterpret_cast<u_char*>(this),
                       sizeof(TestMsg),
                       "content of Testmsg");
    }

};


void send_some_buffer(const void* buffer, size_t len,
                      Poco::Net::DatagramSocket &sock,
                      Poco::Net::SocketAddress  &server
                      )
{
    boost::scoped_array<char> buf(new char[256]);

    try{
        sock.sendTo(buffer, len, server);
        len = sock.receiveFrom(buf.get(), 256, server);
    } catch( const Poco::Net::NetException &e){
       std::cerr << e.what() << std::endl;
    }

    std::string ans(buf.get(), len);
    std::cout << "got " << len << " bytes" << std::endl;
    std::cout << ans << std::endl;
}


void send_input(Poco::Net::DatagramSocket &sock,
                Poco::Net::SocketAddress  &server )
{
    std::string line;

    while (std::cin >> line)
        send_some_buffer(line.c_str(), line.length(), sock, server);

}


int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] <<
            "address port" << std::endl;
        return 1;
    }

    Poco::Net::DatagramSocket sock;
    Poco::Net::SocketAddress  server(argv[1], argv[2]);

    TestMsg msg(2,3, "hello");

    send_some_buffer(&msg, sizeof(msg), sock, server);

    sock.close();
}
