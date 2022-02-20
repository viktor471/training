#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
#include <rapidjson/ostreamwrapper.h>
#include <fstream>

namespace rpj = rapidjson;

int main()
{

    const char* templ= "{\"var_a\":\"11\",\"var_b\":\"22\"}";
//    const char* templ= "{\"var_a\", \"var_b\"}";
    rpj::Document doc;
    doc.Parse( templ );
    doc.AddMember("itemone", "1", doc.GetAllocator());
    //rpj::Value &var_a = doc["var_a"];
    //var_a.SetInt(3);
    //std::cout << var_a.GetString()  << std::endl;
//    std::cout << var_a.GetInt() 	<< std::endl;
    //var_a.SetInt(14);
    //std::cout << var_a.GetInt() 	<< std::endl;

//    doc["var_"].SetInt(34);
    std::ofstream ofs( "output.json" );
    rpj::OStreamWrapper osw( ofs );

    rpj::Writer< rpj::OStreamWrapper > writer( osw );
    doc.Accept( writer );

    rpj::Value& var_a = doc["var_a"];
    var_a.SetInt(55);

//    rpj::Writer< rpj::OStreamWrapper > writer2( osw );
//    doc.Accept( writer );

    return 0;
}
