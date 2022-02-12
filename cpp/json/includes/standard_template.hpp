#ifndef STANDARD_TEMPLATE_HPP
#define STANDARD_TEMPLATE_HPP
#include "template_string_creator.hpp"

class TemplateString
{
private:

  TemplateString( TemplateString&  ) = delete;
  TemplateString( TemplateString&& ) = delete;

  TemplateString& operator=( TemplateString&  ) = delete;
  TemplateString& operator=( TemplateString&& ) = delete;

  public:

  static std::string create();

};

#endif // STANDARD_TEMPLATE_HPP
