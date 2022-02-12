#include <iostream>
#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>
#include <rapidjson/filewritestream.h>

namespace rpj = rapidjson;

int main()
{

    char buffer[65536];

    FILE *fp_1 = fopen("file.json", "a");

    rpj::FileWriteStream os(fp_1, buffer, sizeof (buffer));

    fclose(fp_1);

    FILE *fp_2 = fopen("file.json", "rb");


    rpj::FileReadStream  is( fp_2, buffer, sizeof (buffer) );

    rpj::Document d;
    d.ParseStream(is);

    std::cout << d["arr"][0]["hello"].GetInt() << std::endl;

    std::cout << d["arr"][0]["array"].IsArray() << std::endl;
    std::cout << d["arr"][0]["array"][1].GetInt() << std::endl;
    std::cout << d["arr"][0]["array"].Size() << std::endl;

    for( rpj::SizeType i = 0; i < d["arr"][0]["array"].Size(); i++ )

        std::cout << "array[" << i << "]: "
          << d["arr"][0]["array"][i].GetInt()
          << std::endl;

    for( rpj::Value::ConstValueIterator it = d["arr"][0]["array"].Begin(); it != d["arr"][0]["array"].End(); it++ )
        std::cout << "array: " << it->GetInt() << std::endl;

    for( rpj::Value & i : d["arr"][0]["array"].GetArray() )
        std::cout << "array: " << i.GetInt() << std::endl;

    std::cout << d["arr"][0]["array"].GetType() << std::endl;
    std::cout << d["arr"][0]["hello"].GetType() << std::endl;
    std::cout << d["arr"][0]["true"].GetType() << std::endl;
    std::cout << d["arr"][0]["false"].GetType() << std::endl;
    std::cout << d["arr"][0]["null"].GetType() << std::endl;
    std::cout << d["arr"][0].FindMember("hello")->value.GetInt() << std::endl;
    std::cout << d["arr"].HasMember("hello") << std::endl;
//    std::cout << strlen( d["arr"][0]["string"].GetString() ) << " "
//              << d["arr"][0]["string"].GetStringLength()     << std::endl;

//    std::cout << "d[\"arr\"][\"hello\"] == d[\"hello2\"] "
//              << std::boolalpha
//              << ( d["arr"][0]["hello"] == d["hello2"] ) << std::endl;

//    std::cout << d["arr"][0]["string2"].GetString() << std::endl;

    return 0;
}
