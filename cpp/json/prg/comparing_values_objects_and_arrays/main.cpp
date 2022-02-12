#include <iostream>
#include <rapidjson/filewritestream.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>
#include <cstdio>
#include <rapidjson/writer.h>
#include <rapidjson/prettywriter.h>

const int BUF_SIZE = 65536;

namespace rpj = rapidjson;

int main()
{
    FILE* fp_w = fopen("json.json", "w" );

    char buf[BUF_SIZE];

    rpj::StringBuffer s;
    rpj::FileWriteStream os(fp_w, buf, sizeof (buf));

//    rpj::PrettyWriter<rpj::StringBuffer> writer(s);
    rpj::Writer<rpj::FileWriteStream> writer_2(os);
//    rpj::PrettyWriter<rpj::FileWriteStream> writer_2(os);

    writer_2.StartObject();
    {

        writer_2.String("object1");
        writer_2.StartObject();
        {

            writer_2.String("hello1");
            writer_2.String("world");

            writer_2.String("hello2");
            writer_2.String("world");

            writer_2.String("arr1");
            writer_2.StartArray();
            {
                writer_2.Int(33);
                writer_2.Int(35);
                writer_2.Int(36);
            }
            writer_2.EndArray();
        }
        writer_2.EndObject();


        writer_2.String("object2");
        writer_2.StartObject();
        {
            writer_2.String("arr2");
            writer_2.StartArray();
            {
                writer_2.Int(33);
                writer_2.Int(34);
                writer_2.Int(36);
            }
            writer_2.EndArray();
        }
        writer_2.EndObject();

        writer_2.String("object3");
        writer_2.StartObject();
        {
            writer_2.String("arr2");
            writer_2.StartArray();
            {
                writer_2.Int(33);
                writer_2.Int(34);
                writer_2.Int(36);
            }
            writer_2.EndArray();
        }
        writer_2.EndObject();

        writer_2.String("hello1");
        writer_2.String("world");

        writer_2.String("hello2");
        writer_2.String("world");

        writer_2.String("number");
        writer_2.Int(33);

    }
    writer_2.EndObject();

    fclose(fp_w);

    rpj::Document doc;

    rpj::Value val(88);

    FILE* fp_r = fopen("json.json", "r");

    rpj::FileReadStream is(fp_r, buf, sizeof(buf));
    doc.ParseStream(is);

//    std::cout << doc["hello1"].GetString() << std::endl;
//    std::cout << ( doc["arr1"] == doc["arr2"] ) << std::endl;

//    std::cout << ( doc["hello1"] == doc["hello2"] ) << std::endl;
    std::cout << std::boolalpha << (doc["object1"] == doc["object2"]) << std::endl;
    std::cout << std::boolalpha << (doc["object3"] == doc["object2"]) << std::endl;
    std::cout << s.GetString() << std::endl;
    std::cout << ( doc["number"] == 2 ) << std::endl;
    fclose(fp_r);

    doc.AddMember("new_number", val, doc.GetAllocator());
    doc["object1"]["arr1"].GetArray().PushBack(888, doc.GetAllocator());
    return 0;


}
