#ifndef __SERVER__
#define __SERVER__

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
#include <string>
#include <vector>


using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPResponse;

class Server{
private:

public:
    Server() = default;
};

class RequestHandler: public HTTPRequestHandler
{
private:
    static int _count;
public:
    virtual void handleRequest(HTTPServerRequest  &req,
                               HTTPServerResponse &resp);

};

int RequestHandler::_count = 0;

#endif
