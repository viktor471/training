#ifndef JSON_START_H
#define JSON_START_H

#include <interfaces/iplugin.h>

class json_start : public KDevelop::IPlugin
{
    Q_OBJECT

public:
    // KPluginFactory-based plugin wants constructor with this signature
    json_start(QObject* parent, const QVariantList& args);
};

#endif // JSON_START_H
