#include "template_string_creator.hpp"

#include <sstream>

const char* QUOTE       = "\"";
const char* COMMA       = ",";
const char* COLON       = ":";
const char* OPEN_BRASE  = "{";
const char* CLOSE_BRASE = "}";

std::string operator+( const std::string &value, const Null_value  &null )
{
  return value + null._null;
}


std::string operator+( const Null_value  &null, const std::string &value )
{
  return value + null._null;
}


Null_value::operator std::string() const
{
  return _null;
}


template<typename T>
std::string quoted_str( const T &str, bool is_quoted )
{
    std::string quote = is_quoted ? QUOTE : "";

    return quote + str + quote;
}


template<typename T>
std::string get_json_entry( const std::string &name,
                            const T           &value,
                                  bool         quoted,
                                  bool         comma_need )
{
    return quoted_str(name)           +
            COLON                     +
            quoted_str(value, quoted) +
            ( comma_need ? "," : "" );
}


template<typename T>
std::string get_name_with_value( const std::string &name,
                                 const T           &value,
                                       bool         comma_need )
{
    return get_json_entry( name, value, true, comma_need );
}


template<>
std::string get_name_with_value<>( const std::string &name,
                                   const std::string &value,
                                         bool         comma_need )
{
    return get_json_entry( name, value, true, comma_need );
}


template<>
std::string get_name_with_value<>( const std::string &name,
                                   const int         &value,
                                         bool         comma_need )
{
    std::stringstream serv_stream;
    serv_stream << value;

    return get_json_entry( name, serv_stream.str(), false, comma_need );
}

template<>
std::string get_name_with_value<>( const std::string &name,
                                   const bool        &value,
                                         bool         comma_need )
{
    std::string serv_string = value ? "true" : "false";

    return get_json_entry( name, serv_string, false, comma_need );
}


template<>
std::string get_name_with_value<>( const std::string &name,
                                   const Null_value  &,
                                         bool         comma_need )
{
    return get_json_entry( name, std::string(NULL_VALUE), false, comma_need );
}

std::string create_template_string()
{
    return  get_name_with_value( "UID",               0                  ) +
            get_name_with_value( "children",          NULL_VALUE         ) +
            get_name_with_value( "name",              "main_node"        ) +
            get_name_with_value( "creation_date",     "10.01.2021 18.25" ) +
            get_name_with_value( "modification_date", "10.01.2021 18.25" ) +
            get_name_with_value( "text",              ""                 );
}

