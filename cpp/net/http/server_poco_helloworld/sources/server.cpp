#include "server.hpp"

#include <iostream>

std::string p = "<p>";
std::string p_end = "</p>";
std::string h = "<h>";
std::string h_end = "</h>";

using std::cout;
using std::endl;

void RequestHandler::handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp)
{
        resp.setStatus(HTTPResponse::HTTP_OK);
        resp.setContentType("text/html");

        std::ostream &out = resp.send();

        out     << h << "Hello world!"                << h_end
                << p << "Count:  " << ++_count        << p_end
                << p << "Host:   " << req.getHost()   << p_end
                << p << "Method: " << req.getMethod() << p_end
                << p << "URI:    " << req.getURI()    << p_end;

        out.flush();

        cout    << "Response sent for count=" << _count
                << "and URI=" << req.getURI() << endl;

}
