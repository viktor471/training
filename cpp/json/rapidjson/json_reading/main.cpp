#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <fstream>

using namespace std;

namespace rpj = rapidjson;

int main()
{
    char *templ = "{\"var_a\", \"var_b\"}";

    rpj::Document doc;
    doc.Parse(templ);
    std::ifstream ifs("output.json");
    rpj::IStreamWrapper wrapper(ifs);
    doc.ParseStream(wrapper);
    rpj::Value& var_a = doc["var_a"];
    rpj::Value& var_b = doc["var_b"];

    std::cout << var_a.GetInt() << std::endl;
    std::cout << var_b.GetString() << std::endl;
    return 0;
}
