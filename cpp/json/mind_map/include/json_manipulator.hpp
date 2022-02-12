#ifndef JSON_MANIPULATOR_H
#define JSON_MANIPULATOR_H

#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include <map>

#include "shortenings.hpp"

namespace rpj = rapidjson;

typedef rpj::Writer< rpj::OStreamWrapper > WriterToJSON ;


struct Out_JSON_Interface
{
    rpj::OStreamWrapper _out_wrapper;
    std::ofstream       _output_stream;
    rpj::Document       _doc;

    Out_JSON_Interface( const std::string& file_name );
    void record_all_to_file();
};


struct In_JSON_Interface
{
    std::ifstream       _input_stream;
    rpj::Document       _doc;
    rpj::IStreamWrapper _in_wrapper;

    In_JSON_Interface( const std::string& file_name );
    void read_document_again();
};


enum Type
{
    INT,
    STRING
};


class Json_manipulator
{
    In_JSON_Interface  _in_interface;
    Out_JSON_Interface _out_interface;

public:
    Json_manipulator ( const std::string& file_name  );

    long long   read_int_field       ( const std::string& field_name );
    std::string read_string_field    ( const std::string& field_name );
    void        write_to_int_field   ( const std::string& field_name,
                                             long long    value      );

    void        write_to_string_field( const std::string& field_name,
                                       const std::string& value      );

    Type        get_type_of_field    ( const std::string& field_name ) const;
};


class Element_manipulator;

typedef  std::list < std::string >         Children_list;
typedef  std::list < Element_manipulator > Children_collection;

typedef  std::string Field_name;
typedef  std::string Field_content;

struct Element_Info
{
    long long UID;
    std::list< Element_Info > children;
    std::string name;
    std::string creation_date;
    std::string modification_date;
    std::string text;
};

class Element_manipulator
{
    Json_manipulator _json_manipulator;
    Element_Info     _element_info;

    std::string update_modification_time();
    std::string update_creation_time();
    long long   get_last_UID() const;
    long long   update_UID();


public:

    Element_manipulator( std::string file_name = MAIN_FILE );

    long long           get_UID()                const;
    const std::string&  get_parent_name()        const;
    const std::string   get_name()               const;
    const std::string&  get_modification_time()  const;
    const std::string&  get_creation_time()      const;
    const std::string   get_text_of_element()    const;
    const Element_Info& get_Element_Info()       const;

    Children_list&        get_children_list();
    Element_manipulator&  get_new_child();
    Element_manipulator&  get_child( const std::string& child_name );
    Children_collection&  get_children();

    Element_Info       ProcessElementInfo ( Element_Info& element_info );
    const std::string& set_parent_name    ( const std::string& parent_name );
    const std::string& set_name           ( const std::string& new_name    );
    const std::string& set_text_of_element( const std::string& new_text    );
    void               remove_child       ( const std::string& child_name  );

};

#endif // JSON_MANIPULATOR_H
