#ifndef TEMPLATE_STRING_CREATOR_HPP
#define TEMPLATE_STRING_CREATOR_HPP
#include <string>

extern const char* OPEN_BRASE;
extern const char* CLOSE_BRASE;

struct Null_value
{
    Null_value() = default;

    friend std::string operator+( const std::string &value,
                                  const Null_value  &null );

    friend std::string operator+( const Null_value  &null,
                                  const std::string &value );

    operator std::string() const;

    const std::string _null = "null";
} const NULL_VALUE;


template<typename T>
inline std::string quoted_str( const T&   str, bool is_quoted = true );

template <typename T>
std::string get_json_entry( const std::string &name,
                            const T           &value,
                            bool         quoted     = false,
                            bool         comma_need = true );

template <typename T>
std::string get_name_with_value( const std::string &name,
                                 const T           &value,
                                 bool        comma_need = true );

template<>
std::string get_name_with_value( const std::string &name,
                                 const std::string &value,
                                 bool        comma_need );

template <>
std::string get_name_with_value( const std::string &name,
                                 const bool        &value,
                                 bool        comma_need );


template <>
std::string get_name_with_value( const std::string &name,
                                 const int         &value,
                                 bool               comma_need );



template<>
std::string get_name_with_value( const std::string &name,
                                 const Null_value&,
                                 bool        comma_need );

std::string create_template_string();

#endif // TEMPLATE_STRING_CREATOR_HPP
