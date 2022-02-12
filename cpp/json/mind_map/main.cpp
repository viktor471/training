#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <map>
#include "json_manipulator.hpp"
#include <rapidjson/document.h>

int main() {

//    Json_manipulator manipulator( MAIN_FILE );
//    manipulator.write_to_int_field( "UID", 66 );
//    std::cout << manipulator.read_int_field( "UID" ) << std::endl;
    rpj::Document doc;
    doc.SetObject();
    rpj::Value arr_of_elements( rpj::kArrayType );
    rpj::Document::AllocatorType& allocator = doc.GetAllocator();

    rpj::Value element;
    element.SetObject();
    element.AddMember("UID", 0, allocator);

    rpj::Value arr_of_chilren( rpj::kArrayType );
    element.AddMember( "children", arr_of_chilren, allocator );
    element.AddMember( "name", "main_node", allocator );
    element.AddMember( "creation_date", "10.01.2021 18.25", allocator );
    element.AddMember( "modification_date", "10.01.2021 18.25", allocator );
    element.AddMember( "text", "-", allocator );

    arr_of_elements.PushBack( element, allocator ); //arr_of_elements.AddMember( "element_1", element, allocator );
    doc.AddMember("array_of_elements", arr_of_elements, allocator );

    std::ofstream stream( "main.json" );
    rpj::OStreamWrapper wrapper( stream );
    rpj::Writer< rpj::OStreamWrapper > writer( wrapper );
    doc.Accept( writer );

    return 0;
}
