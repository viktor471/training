#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/ostreamwrapper.h"

//using namespace rapidjson;

#define ROOT_RECORD "{\"project\":\"rapidjson\",\"stars\":10}"

int main() {
    
    using rapidjson::Value;
    using rapidjson::Document;
    using rapidjson::StringBuffer; 
    using rapidjson::OStreamWrapper; 
    using rapidjson::Writer;
    
    // 1. Parse a JSON string into DOM.
    const char* json =  ROOT_RECORD;
    Document d;
    d.Parse(json);
    Value record(rapidjson::Type::kArrayType); 
   //record.AddMember(
    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
 
    // 3. Stringify the DOM
   StringBuffer buffer;
   Writer< StringBuffer> writer(buffer);
    d.Accept(writer);
 
    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    
    //FILE* fp = fopen("first_json.json", "w");
    std::ofstream ofs("first_json.json");
   OStreamWrapper osw(ofs);
   
  rapidjson::Writer< rapidjson::OStreamWrapper> writer_out(osw);
  d.Accept( writer_out ); 
    return 0;
}
