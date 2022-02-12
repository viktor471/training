#include <iostream>
#include "template_string_creator.hpp"
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

namespace rpj = rapidjson;

int main()
{
    using std::cout;
    using std::endl;

    using rpj::StringBuffer;
    using rpj::Writer;
    using rpj::Value;
    using rpj::Document;

    // 1. Parse a JSON string into DOM.

    std::string test_json =   OPEN_BRASE
            + get_name_with_value( "project",    "rapidjson" )
            + get_name_with_value( "stars",      10          )
            + get_name_with_value( "it_is_bool", true        )
            + get_name_with_value( "it_is_null", NULL_VALUE, false )
            + CLOSE_BRASE;

    std::cout << test_json << std::endl;

    Document d;
    d.Parse( test_json.c_str() );

    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    assert(d["project"].IsString());
    //    assert(d["project"].IsBool()); // doesn't work

    cout << "d[\"stars\"]: "
         << d["stars"].GetInt()
         << endl;

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    cout << buffer.GetString() << endl;

    return 0;
}
