#ifndef JSON_MANIPULATOR_H
#define JSON_MANIPULATOR_H

#include <string>
#include <rapidjson/document.h>
#include "shortenings.h"
#include <fstream>

namespace rpj = rapidjson;
typedef rpj::Writer< rpj::OStreamWrapper > WriterToJSON ;

class json_manipulator
{
    std::string         _file_name;
    std::ofstream       _input_stream;
    std::ofstream       _output_stream;
    rpj::Document       _doc;
    rpj::OStreamWrapper _wrapper;
    WriterToJSON        _writer_out;
    WriterToJSON        _writer_in;

public:
    json_manipulator( std::string file_name = "" );
};

#endif // JSON_MANIPULATOR_H
