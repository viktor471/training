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
    writer_2.String("hello");
    writer_2.String("world");
    writer_2.String("arr");
    writer_2.StartArray();
    writer_2.Int(33);
    writer_2.Int(34);
    writer_2.Int(36);
    writer_2.EndArray();
    writer_2.String("arr2");
    writer_2.StartArray();
    writer_2.Int(33);
    writer_2.Int(34);
    writer_2.Int(36);
    writer_2.EndArray();
    writer_2.EndObject();

    fclose(fp_w);

    rpj::Document doc;


    FILE* fp_r = fopen("json.json", "r");

    rpj::FileReadStream is(fp_r, buf, sizeof(buf));
    doc.ParseStream(is);
    std::cout << doc["hello"].GetString() << std::endl;
    std::cout << s.GetString() << std::endl;
    fclose(fp_r);
    return 0;
}
