#include "standard_template.hpp"
#include "template_string_creator.hpp"

std::string TemplateString::create()
{
    return  get_name_with_value( "UID",               0                  ) +
            get_name_with_value( "children",          NULL_VALUE         ) +
            get_name_with_value( "name",              "main_node"        ) +
            get_name_with_value( "creation_date",     "10.01.2021 18.25" ) +
            get_name_with_value( "modification_date", "10.01.2021 18.25" ) +
            get_name_with_value( "text",              ""                 );
}
