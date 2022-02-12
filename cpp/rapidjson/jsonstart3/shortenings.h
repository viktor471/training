#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/ostreamwrapper.h"

#define ROOT_RECORD "{\"project\":\"rapidjson\",\"stars\":10}"

#define SCOPE_OPENING                          \
	using rapidjson::Value;                    \
	using rapidjson::Document;                 \
	using rapidjson::StringBuffer;             \
	using rapidjson::OStreamWrapper;           \
	using rapidjson::Writer;                   \
	using rapidjson::kArrayType;               \
                                               \
	using std::cout;                           \
	using std::endl;                       
