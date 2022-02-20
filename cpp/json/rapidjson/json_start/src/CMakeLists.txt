set(json_start_SRCS
    json_start.cpp
)

ecm_qt_declare_logging_category(json_start_SRCS
    HEADER debug.h
    IDENTIFIER PLUGIN_JSON_START
    CATEGORY_NAME "kdevelop.plugins.json_start"
)

kdevplatform_add_plugin(json_start
    JSON json_start.json
    SOURCES ${json_start_SRCS}
)

target_link_libraries(json_start
    KDev::Interfaces
)
