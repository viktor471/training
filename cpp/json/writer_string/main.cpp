#include <iostream>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/writer.h>
#include <rapidjson/document.h>

namespace rpj = rapidjson;

int main()
{
  using rpj::StringBuffer;
  StringBuffer sb;

  rpj::PrettyWriter< StringBuffer > writer( sb );
  writer.StartObject();
  writer.String("double");
  writer.Double(2.3);
  writer.String("bool");
  writer.Bool(true);
  puts(sb.GetString());
  writer.EndObject();

  rpj::Document doc;
  doc.Parse(prg)
  return 0;
}
