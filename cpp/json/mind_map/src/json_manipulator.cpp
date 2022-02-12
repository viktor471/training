#include "json_manipulator.hpp"

Json_manipulator::Json_manipulator( const std::string& file_name ) :
    _in_interface ( file_name ),
    _out_interface( file_name ) {}

long long Json_manipulator::read_int_field( const std::string& field_name )
{
    const char* field = field_name.c_str();
    rpj::Value& int_value = _in_interface._doc[ field ];
    return int_value.GetInt64();
}

void Json_manipulator::write_to_int_field( const std::string& field_name,
                                                long long    value       )
{
    const char* field = field_name.c_str();
    rpj::Value& int_value = _out_interface._doc[ field ];
    int_value.SetInt64( value );
    _out_interface.record_all_to_file();
}

Out_JSON_Interface::Out_JSON_Interface( const std::string& file_name ) :
    _out_wrapper  ( _output_stream ),
    _output_stream( file_name      )
{
    _doc.Parse ( TEMPLATE_RECORD );
}

void Out_JSON_Interface::record_all_to_file()
{
    rpj::Writer< rpj::OStreamWrapper > writer( _out_wrapper );
    _doc.Accept( writer );
}

In_JSON_Interface::In_JSON_Interface( const std::string& file_name ) :
    _input_stream( file_name     ),
    _in_wrapper  ( _input_stream )
{
    _doc.ParseStream( _in_wrapper );
}

Element_manipulator::Element_manipulator(std::string file_name) :
    _json_manipulator( file_name )
{
}
