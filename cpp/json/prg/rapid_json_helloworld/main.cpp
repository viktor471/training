#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>
#include <sstream>

const std::string QUOTE       = "\"";
const std::string OPEN_BRASE  = "{";
const std::string CLOSE_BRASE = "}";
const std::string COMMA       = ",";
const std::string COLON       = ":";

namespace rpj = rapidjson;


struct Null_value
{
    Null_value() = default;
    friend std::string operator+( const std::string &value, const Null_value &null )
    {
        return value + null._null;
    }

    friend std::string operator+( const Null_value &null, const std::string &value )
    {
        return value + null._null;
    }

    operator std::string() const { return _null; };

    const std::string _null = "null";
} const NULL_VALUE;


inline std::string quouted_str( const std::string& str, bool is_quoted = true )
{
   std::string quote = is_quoted ? QUOTE : "";

   return quote + str + quote;
}
template <typename T>
std::string get_json_entry( const std::string &name, const T &value, bool comma_need = true, bool quoted = false )
{
   return quouted_str(name) + COLON + quoted_str(value, quoted) + ( comma_need ? "," : "" );
}

template <typename T>
std::string get_name_with_value( const std::string &name, const T &value, bool comma_need = true );

template<>
std::string get_name_with_value( const std::string &name, const std::string &value, bool comma_need )
{
   return QUOTE + name  + QUOTE + COLON +
          QUOTE + value + QUOTE;
}

template <>
std::string get_name_with_value( const std::string &name, const bool &value, bool comma_need )
{
   std::string serv_string = value ? "true" : "false";

   return get_json_entry( name, serv_string, comma_need );
}


template <>
std::string get_name_with_value( const std::string &name, const int &value, bool comma_need )
{
   std::stringstream serv_stream;
   serv_stream << value;

   return get_json_entry( name, serv_stream.str(), comma_need );
}



template<>
std::string get_name_with_value( const std::string &name, const Null_value&, bool comma_need )
{
   return get_json_entry( name, std::string(NULL_VALUE), comma_need );
}


int main() {

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

    cout << "d[\"it_is_null\"].IsNull: "
         <<  d["it_is_null"].IsNull()
         << endl;

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    cout << buffer.GetString() << endl;
    return 0;
}
