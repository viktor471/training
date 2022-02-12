#include <iostream>
#include <climits>

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/prettywriter.h>

namespace rpj = rapidjson;
const int BUF_SIZE = UINT16_MAX;

int main()
{

    FILE* fp = fopen("json.json", "w");
    char  buf[BUF_SIZE];

    rpj::FileWriteStream os( fp, buf, sizeof(buf) );

    rpj::PrettyWriter< decltype (os) > writer(os);

    rpj::Document doc_1;
//    doc.ParseStream(os);
    doc_1.SetObject();
    doc_1.AddMember("hello", "hello", doc_1.GetAllocator() );
    doc_1["hello"] = "not hello";
    doc_1.AddMember("int_1", 33, doc_1.GetAllocator() );

    doc_1.Accept(writer);

    fclose(fp);

    fp = fopen("json.json", "a+");

    rpj::FileReadStream is( fp, buf, sizeof(buf) );
    rpj::Document doc_2;
    doc_2.ParseStream(is);

    std::cout << doc_2["hello"].GetString() << std::endl;
    doc_2["hello"] = 99;

    FILE* fp_2 = fopen("json.json", "w");
    rpj::FileWriteStream os_2( fp_2, buf, sizeof(buf) );
//    rpj::StringBuffer
    rpj::Writer<rpj::FileWriteStream> writer_2(os_2);
    doc_2.Accept(writer_2);

    return 0;
}
